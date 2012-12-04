#include "serial.h"
#include "serialrequest.h"
#include <QTest>

serial::serial(PortSettings Settings, QObject *parent)
    : QextSerialPort(Settings,EventDriven, parent)
{
   processError("not initialized") ;
   connect(this, SIGNAL(readyRead()), this, SLOT(read())) ;


}

void serial::enqueue(serialRequest *requestPointer)
{
    write(requestPointer->request()) ;
    waiting.enqueue(requestPointer) ;
}

void serial::read()
{
    int bytes = bytesAvailable() ;
    do
    {
        bytes = bytesAvailable() ;
        QTest::qWait(10) ;
    }
    while (bytesAvailable() > bytes && !canReadLine()) ;
    QByteArray data = readAll() ;
    while(!data.isEmpty() && !waiting.isEmpty())
    {
        serialRequest* request = waiting.dequeue() ;
        QString D = request->process(data) ;
        if (!D.isEmpty())
        {
            delete request ;
            processError(D) ;
            return ;
        }
        delete request ;
    }

}

void serial::clearError()
{
    if (!init())
        processError("Initializing failed") ;
    else ErrorString.clear() ;
}

void serial::clearQueue()
{
    //Löschen der Objekte (Schleife) auf den der jeweilige Pointer gezeigt hat
    foreach(serialRequest* Pointer, waiting)
        delete Pointer ;
    //Löschen der Schlange
    waiting.clear() ;
}

void serial::processError(const QString & Es)
{
    clearQueue() ;
    ErrorString = Es ;
    emit Error(Es) ;
}

serial::~serial()
{
    clearQueue();
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


