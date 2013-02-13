#include "serial.h"
#include "serialrequest.h"
#include <QTest>
#include <QDebug>
#include <QTime>
#include <QTimer>


serial::serial(PortSettings Settings, QObject *parent)
    : QextSerialPort(Settings,EventDriven, parent),
      ignoreNext(false),
      awaitingResponse(false)
{
   processError("not initialized") ;
   connect(this, SIGNAL(readyRead()), this, SLOT(read())) ;
   delayTime.setSingleShot(true) ;
   connect(&delayTime,SIGNAL(timeout()), this, SLOT(writeNext())) ;
   delayTime.setInterval(0);
}

void serial::prepareToWrite()
{
    if (awaitingResponse || delayTime.isActive()) return ;
    delayTime.start();
}

void serial::writeNext()
{
    mutex.lock();
    if (waiting.isEmpty())
    {
        mutex.unlock();
        return ;
    }
    write(waiting.head()->request()) ;
    awaitingResponse = true ;
    mutex.unlock();
}

void serial::setMinimumDelay(int msec)
{
    delayTime.setInterval(msec) ;
}

void serial::enqueue(serialRequest *requestPointer)
{
    connect(requestPointer, SIGNAL(destroyed()), this, SLOT(requestDestroyed())) ;
    requestPointer->setParent(this) ;
    if (!isok())
    {
        if (requestPointer->singleUse()) delete requestPointer ;
        return ;
    }
    if (waiting.contains(requestPointer)) return ;
    mutex.lock();
    waiting.enqueue(requestPointer) ;
    mutex.unlock() ;
    prepareToWrite();
}

// INVARIANT for communication:  First item in queue has been sent and
// is awaiting response.

void serial::read()
{
    awaitingResponse = false ;
    // get waiting request
    mutex.lock();
    serialRequest *currentRequest = ((ignoreNext || waiting.isEmpty())? 0 : waiting.dequeue()) ;
    ignoreNext = false ;

    // wait for all bytes to arrive -- might not be necessary -> TODO: check!
    QTime timeout ;
    timeout.start() ;
    QByteArray data(readAll()) ;
    while (!answerComplete(data, currentRequest))
    {
        if (timeout.elapsed() > 100)
        {
            qDebug() << "timed out" ;
            break ;
        }
        data += readAll() ;
    }

    if (currentRequest)
    {
        processError(currentRequest->process(data)) ;
        if (currentRequest->singleUse()) delete currentRequest ;
        else if (isok()) waiting.enqueue(currentRequest);
    }
    mutex.unlock();
    prepareToWrite();
}

bool serial::answerComplete(const QByteArray &a, serialRequest *nextRequest)
{
    Q_UNUSED(a)
    Q_UNUSED(nextRequest)
    return true ;
}

void serial::requestDestroyed()
{
    serialRequest* request = (serialRequest*) sender() ;
    mutex.lock();
    if (!waiting.isEmpty() && waiting.head() == request) ignoreNext = true ;
    waiting.removeAll(request) ;
    mutex.unlock();
}

void serial::childEvent(QChildEvent *e)
{
    if (!e->removed()) return ;
    serialRequest *request = (serialRequest*) (e->child()) ;
    if (!requst) return ;
    mutex.lock() ;
    if (!waiting.isEmpty() && waiting.head() == request) ignoreNext = true ;
    waiting.removeAll(request) ;
    mutex.unlock() ;
}

void serial::clearError()
{
    clearQueue();
    if (!init())
        processError("Initializing failed") ;
    else ErrorString.clear() ;
    // rebuild queue:
    buildQueue();
    if (!waiting.isEmpty())
        write(waiting.head()->request()) ;
}

void serial::clearQueue()
{
    mutex.lock();
    waiting.clear() ;
    mutex.unlock();
}

void serial::buildQueue()
{
    clearQueue();
    mutex.lock();
    waiting << findChildren<serialRequest*>() ;
    mutex.unlock();
}

void serial::processError(const QString & Es)
{
    ErrorString = Es ;   
    if (!Es.isEmpty())
    {
        clearQueue() ;
        emit Error(Es) ;
    }    
}

bool serial::waitForReadyRead(int msecs)
{
    QTime timeout ;
    timeout.start();
    while (!bytesAvailable() && timeout.elapsed() < msecs) ;
    if (timeout.elapsed() >= msecs) return false ;
    return true ;
}


deviceButton::deviceButton(QWidget *parent)
    :QPushButton(parent),
      device(0)
{
    connect(this, SIGNAL(clicked()), this, SLOT(resetDevice())) ;
    setButtonColor(Qt::blue);
}

void deviceButton::setDevice(serial *dev)
{
    if (device)
        disconnect(device, SIGNAL(Error(QString)), this, SLOT(errorOccured(QString))) ;
    device = dev ;
    connect(device, SIGNAL(Error(QString)), this, SLOT(errorOccured(QString))) ;
}

void deviceButton::setButtonColor(const QColor& Color)
{
    QPalette pal = palette() ;
    pal.setColor(QPalette::ButtonText, Color) ;
    setPalette(pal) ;
}


void deviceButton::resetDevice()
{
    if (!device)
        return ;
    device->clearError() ;
    if (device->isok())
        setButtonColor(Qt::green) ;
}

void deviceButton::errorOccured(QString S)
{
    setButtonColor(Qt::red);
    setToolTip(S);
}


