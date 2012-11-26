#include "serial.h"
#include "serialrequest.h"

serial::serial(PortSettings Settings, QObject *parent)
    : QextSerialPort(Settings,EventDriven, parent),
      ok(true)
{
   if (!init())
       processError() ;
   connect(this, SIGNAL(readyRead()), this, SLOT(read())) ;


}

void serial::enqueue(serialRequest *requestPointer)
{
    write(requestPointer->request()) ;
    waiting.enqueue(requestPointer) ;
}

void serial::read()
{
    QByteArray data = readAll() ;
    while(!data.isEmpty())
    {
        serialRequest* request = waiting.dequeue() ;
        if (!request->process(data))
        {
            delete request ;
            processError() ;
            return ;
        }
        delete request ;
    }
}

void serial::clearError()
{
    if (!init())
        processError() ;

}

void serial::processError()
{
    waiting.clear() ;
    ok = false ;
    emit Error() ;
}

deviceButton::deviceButton(serial *Device, QString Name,  QWidget *parent)
    :QPushButton(Name, parent),
      device(Device)
{
    connect(device, SIGNAL(Error()), this, SLOT(errorOccured())) ;
    connect(this, SIGNAL(clicked()), this, SLOT(resetDevice())) ;

}
void deviceButton::setButtonColor(const QColor& Color)
{
    QPalette pal = palette() ;
    pal.setColor(QPalette::Background, Color) ;
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

void deviceButton::errorOccured()
{
    setButtonColor(Qt::red);
}


