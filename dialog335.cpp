#include "dialog335.h"

dialog335::dialog335(QObject *parent) :
    serial(serialSettings(BAUD57600,
                          DATA_7,
                          PAR_ODD,
                          STOP_1,
                          FLOW_OFF,
                          -1), parent)
{
    setPortName("COM4") ;
    open(ReadWrite) ;
}

bool dialog335::init()
{
    flush() ;
    write("*IDN?\n") ;
    if (!waitForReadyRead(1000))
        return false ;
    QByteArray ba = readAll() ;
    return ba == QByteArray("LSCI,MODEL335,335A0KE/#######,1.1\r\n") ;
}



QByteArray temperatureRequest::request()
{
    return QByteArray().append("KRDG?" + QString(Channel)  + "\n") ;
}

QString temperatureRequest::process(QByteArray & temperatureProcessArray)
{
    emit numericvalue(temperatureProcessArray.toDouble()) ;
    return "" ;
}
