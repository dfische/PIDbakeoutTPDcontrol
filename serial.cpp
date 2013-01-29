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
    if (requestPointer->parent() == this && waiting.contains(requestPointer)) return ;
    if (!isok())
    {
        delete requestPointer ;
        return ;
    }
    requestPointer->setParent(this) ;
    // Only send, if nothing else is underway:
    if (waiting.isEmpty())
    {
        QByteArray req = requestPointer->request() ;
        qDebug() << "sent a:" << req ;
        write(req) ;
    }
    waiting.enqueue(requestPointer) ;
}

// INVARIANT for communication:  First item in queue has been sent and
// is awaiting response.

void serial::read()
{
    // wait for all bytes to arrive -- might not be necessary -> TODO: check!
    serialRequest *pendingRequest = ((ignoreNext || waiting.isEmpty())? 0 : waiting.head()) ;
    if (waiting.isEmpty() && !ignoreNext)
        processError("answer without request: ");
    if (!isok())
    {
        qDebug() << "Error:" << readAll() ;
        return ;
    }
    QTime timeout ;
    timeout.start() ;
    while (!answerComplete(peek(100), pendingRequest))
    {
        if (timeout.elapsed() > 100) break ;
//        {
//            QByteArray p = peek(100) ;
//            qDebug() << "Peek:" << p.size() << p ;
//            for (int i = 0 ; i < p.size() ; ++i)
//                qDebug() << "Peekbyte:" << i << (int) (p[i]) ;
//            processError("Timeout") ;
//            return ;
//        }
    }
    QByteArray data(readAll()) ;
    // TODO timeout
    qDebug() << "Datasize" << data.size() << "data:" << data ;
    if (!ignoreNext)
    {
        serialRequest *currentRequest = waiting.dequeue() ;
        // We have only sent the first request in the queue,
        // so we only need to evaluate that one
        processError(currentRequest->process(data)) ;

        if (currentRequest->singleUse()) delete currentRequest ;
        else if (isok()) waiting.enqueue(currentRequest);
    }
    // if requests are pending, continue with the next in line:
    if (!waiting.isEmpty() && isok())
    {
        QByteArray req = waiting.head()->request() ;
        qDebug() << "  sent:" << req ;
        write(req) ;
    }
}

bool serial::answerComplete(const QByteArray &a, serialRequest *nextRequest)
{
    Q_UNUSED(a)
    Q_UNUSED(nextRequest)
    return true ;
}

void serial::childEvent(QChildEvent *e)
{
    QextSerialPort::childEvent(e) ;
    serialRequest *r = qobject_cast<serialRequest*>(e->child()) ;
    if (!r || !e->removed()) return ;
    e->accept();
    ignoreNext = (waiting.head() == r) ;
    waiting.removeAll(r) ;
}

void serial::clearError()
{
    clearQueue();
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


