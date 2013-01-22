#include "serial.h"
#include "serialrequest.h"
#include <QTest>

serial::serial(PortSettings Settings, QObject *parent)
    : QextSerialPort(Settings,EventDriven, parent),
      ignoreNext(false)
{
   processError("not initialized") ;
   connect(this, SIGNAL(readyRead()), this, SLOT(read())) ;


}

void serial::enqueue(serialRequest *requestPointer)
{
    if (requestPointer->parent() == this && waiting.contains(requestPointer)) return ;
    requestPointer->setParent(this) ;
    if (!isok()) return ;
    // Only send, if nothing else is underway:
    if (waiting.isEmpty())
        write(requestPointer->request()) ;
    waiting.enqueue(requestPointer) ;
}

// INVARIANT for communication:  First item in queue has been sent and
// is awaiting response.

void serial::read()
{
    // wait for all bytes to arrive -- might not be necessary -> TODO: check!
    int bytes = bytesAvailable() ;
    do
    {
        bytes = bytesAvailable() ;
        QTest::qWait(10) ;
    }
    while (bytesAvailable() > bytes && !canReadLine()) ;
    QByteArray data = readAll() ;
    serialRequest *currentRequest = 0 ;
    if (!ignoreNext)
    {
        if (waiting.isEmpty())
        {
            // ooops, we got data, although not asked for:
            processError("answer without request");
            return ;
        }
        // We have only sent the first request in the queue,
        // so we only need to evaluate that one
        currentRequest = waiting.dequeue() ;
        processError(currentRequest->process(data)) ;

        if (currentRequest->singleUse()) delete currentRequest ;
        else enqueue(currentRequest);
    }
    // if requests are pending, continue with the next in line:
    if (!waiting.isEmpty() && waiting.head() != currentRequest)
        write(waiting.head()->request()) ;
}

void serial::childEvent(QChildEvent *e)
{
    QextSerialPort::childEvent(e) ;
    serialRequest *r = qobject_cast<serialRequest*>(e) ;
    if (!r || !e->removed()) return ;
    e->accept();
    ignoreNext = (waiting.head() == r) ;
    waiting.removeAll(r) ;
}

void serial::clearError()
{
    if (!init())
        processError("Initializing failed") ;
    else ErrorString.clear() ;
    // rebuild queue:
    buildQueue();
}

void serial::clearQueue()
{
    waiting.clear() ;
}

void serial::buildQueue()
{
    waiting << findChildren<serialRequest*>() ;
}

void serial::processError(const QString & Es)
{
    clearQueue() ;
    ErrorString = Es ;
    if (!Es.isEmpty()) emit Error(Es) ;
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


