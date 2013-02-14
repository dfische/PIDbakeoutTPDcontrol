#include "serial.h"
#include "serialrequest.h"
#include <QTest>
#include <QDebug>
#include <QTime>


serial::serial(PortSettings Settings, QObject *parent)
    : QextSerialPort(Settings,EventDriven, parent),
      ignoreNext(false)
{
   processError("not initialized") ;
   connect(this, SIGNAL(readyRead()), this, SLOT(read())) ;


}

void serial::enqueue(serialRequest *requestPointer)
{
    mutex.lock() ;
    connect(requestPointer, SIGNAL(destroyed()), this, SLOT(requestDestroyed())) ;
    if (requestPointer->parent() == this && waiting.contains(requestPointer))
    {
        mutex.unlock();
        return ;
    }
    requestPointer->setParent(this) ;
    if (!isok())
    {
        if (requestPointer->singleUse()) delete requestPointer ;
        mutex.unlock();
        return ;
    }
    if (waiting.contains(requestPointer))
    {
        mutex.unlock();
        return ;
    }
    // Only send, if nothing else is underway:
    if (waiting.isEmpty())
        write(requestPointer->request()) ;
    waiting.enqueue(requestPointer) ;
    mutex.unlock() ;
}

// INVARIANT for communication:  First item in queue has been sent and
// is awaiting response.

void serial::read()
{
    mutex.lock();
    // wait for all bytes to arrive -- might not be necessary -> TODO: check!
    serialRequest *currentRequest = ((ignoreNext || waiting.isEmpty())? 0 : waiting.dequeue()) ;
    ignoreNext = false ;
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
        if (currentRequest->singleUse())
        {   mutex.unlock() ;
            delete currentRequest ;
            mutex.lock() ;
        }

        else if (isok()) waiting.enqueue(currentRequest);
    }
    // if requests are pending, continue with the next in line:
    if (!waiting.isEmpty() && isok())
        write(waiting.head()->request()) ;
    mutex.unlock();
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
    if (!waiting.isEmpty() && waiting.head() == request) ignoreNext = true ;
    waiting.removeAll(request) ;
}

void serial::childEvent(QChildEvent *e)
{
    if (!e->removed()) return ;
    mutex.lock() ;
    serialRequest *request = (serialRequest*) (e->child()) ;
    if (!waiting.isEmpty() && waiting.head() == request) ignoreNext = true ;
    waiting.removeAll(request) ;
    mutex.unlock() ;
}

void serial::clearError()
{
    clearQueue();
    mutex.lock() ;
    bool initsuccess = init() ;
    mutex.unlock();
    if (initsuccess) ErrorString.clear() ;
    else processError("Initializing failed") ;
    // rebuild queue:

    buildQueue();
    if (!waiting.isEmpty())
        write(waiting.head()->request()) ;
}

void serial::clearQueue()
{
    waiting.clear() ;
}

void serial::buildQueue()
{
    clearQueue();
    waiting << findChildren<serialRequest*>() ;
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


