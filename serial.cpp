#include "serial.h"
#include "serialrequest.h"
#include <QTest>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include "serialdebugbuffer.h"
#include <QTableView>

qint64 serial::write(const QByteArray &data)
{
    if (debugBuffer) debugBuffer->addOutgoingEntry(data) ;
    return QextSerialPort::write(data) ;
}

QByteArray serial::readAll()
{
    QByteArray result = QextSerialPort::readAll() ;
    if (debugBuffer) debugBuffer->addIncomingEntry(result) ;
    return result ;
}

void serial::showDebugBuffer()
{
    if (debugBuffer && debugBufferView)
    {
        debugBufferView->setModel(debugBuffer);
        debugBufferView->show();
    }
}

void serial::setDebugBufferSize(int items)
{
    if (debugBuffer) debugBuffer->setMaxEntries(items) ;
}

serial::serial(PortSettings Settings, QObject *parent)
    : QextSerialPort(Settings,EventDriven, parent),
      queueMutex(QMutex::Recursive),
      debugBuffer(new serialDebugBuffer(this)),
      debugBufferView(0)
{
    debugBufferView = new QTableView ;
    processError("not initialized") ;
    connect(this, SIGNAL(readyRead()), this, SLOT(read())) ;
    delayTime.setSingleShot(true) ;
    delayTime.setInterval(0);
    connect(&delayTime,SIGNAL(timeout()), this, SLOT(writeNext())) ;
}

serial::~serial()
{
    delete debugBufferView ;
}

void serial::prepareToWrite()
{
    if (!writeMutex.tryLock() || delayTime.isActive()) return ;
    delayTime.start();
    writeMutex.unlock();
}

void serial::writeNext()
{
    if (!writeMutex.tryLock()) delayTime.start();
    queueMutex.lock();
    if (!waiting.isEmpty())
        write(waiting.head()->request()) ;
    queueMutex.unlock();
}

void serial::setMinimumDelay(int msec)
{
    delayTime.setInterval(msec) ;
}

void serial::enqueue(serialRequest *requestPointer)
{
    requestPointer->setParent(this) ;
    if (!isok())
    {
        if (requestPointer->singleUse()) delete requestPointer ;
        return ;
    }
    if (waiting.contains(requestPointer)) return ;
    queueMutex.lock();
    waiting.enqueue(requestPointer) ;
    queueMutex.unlock() ;
    prepareToWrite();
}

// INVARIANT for communication:  First item in queue has been sent and
// is awaiting response.

void serial::read()
{
    // get waiting request
    queueMutex.lock();
    serialRequest *currentRequest = (waiting.isEmpty() ? 0 : waiting.dequeue()) ;

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
        if (currentRequest->singleUse())
            delete currentRequest ;
        else enqueue(currentRequest);
    }
    queueMutex.unlock();
    writeMutex.unlock();
    prepareToWrite();
}

bool serial::answerComplete(const QByteArray &a, serialRequest *nextRequest)
{
    Q_UNUSED(a)
    Q_UNUSED(nextRequest)
    return true ;
}

void serial::childEvent(QChildEvent *e)
{
    if (!e->removed()) return ;
    serialRequest *request = qobject_cast<serialRequest*>(e->child()) ;
    if (!request) return ;
    queueMutex.lock() ;
    if (!waiting.isEmpty() && waiting.head() == request)
        waiting.head() = 0 ;
    waiting.removeAll(request) ;
    queueMutex.unlock() ;
}

void serial::clearError()
{
    clearQueue();
    if (!init())
    {
        processError("Initializing failed") ;
        return ;
    }
    else ErrorString.clear() ;
    // rebuild queue:
    buildQueue();
    writeMutex.unlock() ;
    prepareToWrite();
}

void serial::clearQueue()
{
    queueMutex.lock();
    waiting.clear() ;
    queueMutex.unlock();
}

void serial::buildQueue()
{
    queueMutex.lock();
    clearQueue();
    waiting << findChildren<serialRequest*>() ;
    queueMutex.unlock();
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

void deviceButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton && e->modifiers() == Qt::NoModifier && device)
        device->showDebugBuffer();
    else
        QPushButton::mouseReleaseEvent(e) ;
}
