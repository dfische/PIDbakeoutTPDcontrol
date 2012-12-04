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
    if (ba != QByteArray("LSCI,MODEL335,335A0KE/#######,1.1\r\n"))
        return false ;
    write("OUTMODE 1,1,1,0;OUTMODE 2,1,2,0\n") ;
    return true ;

}

QByteArray dialog335Request::request()
{
    return QByteArray().append(request335() + "\n") ;
}

QString dialog335Request::process(QByteArray & processByteArray)
{
    // Evtl leading ";" loeschen.
    int pos = processByteArray.indexOf("\r\n") ;
    if (pos == -1)
        return "Wrong Answer from Device" ;
    QString leftPart = processByteArray.left(pos) ;
    processByteArray = processByteArray.right(processByteArray.size() - pos - 2) ;
    return process335(leftPart) ;

}

QString temperatureRequest::request335()
{
    return "KRDG?" + QString(Channel) ;
}

QString temperatureRequest::process335(QString &temperatureProcessArray)
{
    emit numericvalue(temperatureProcessArray.toDouble()) ;
    return "" ;
}

setHeaterRange::setHeaterRange(int rv, char ch)
    : Channel(qBound('1', ch, '2')),
      rangeValue(qBound(0, rv, 3))
{

}

QString setHeaterRange::request335()
{
    return "RANGE" + QString(Channel)
            + ","
            + QString::number(rangeValue)
            + "\nRANGE?"
            + QString(Channel)
            + "\n" ;
}

QString setHeaterRange::process335(QString &heaterRangeArray)
{
    emit numericvalue(heaterRangeArray.toInt()) ;
    return "" ;
}

