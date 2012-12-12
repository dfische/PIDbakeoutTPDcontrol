#include "dialog335.h"

dialog335::dialog335(QObject *parent) :
    serial(serialSettings(BAUD57600,
                          DATA_7,
                          PAR_ODD,
                          STOP_1,
                          FLOW_OFF,
                          -1), parent)
{
    setPortName("COM7") ;
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
    write("OUTMODE 1,1,1,0; OUTMODE 2,1,2,0\n") ;
    return true ;

}

dialog335Request::dialog335Request(char ch)
    : Channel(qBound('A',ch,'B'))
{}

char dialog335Request::channelNo() const
{
    return Channel - 'A' + '1' ;
}

char dialog335Request::channel() const
{
    return Channel ;
}

QByteArray dialog335Request::request()
{
    QString req(request335()) ;
    return QByteArray().append(request335() + "\n") ;
}

QString dialog335Request::process(QByteArray & processByteArray)
{
    int pos = processByteArray.indexOf("\r\n") ;
    if (pos == -1)
        return "Wrong Answer from Device" ;
    QString leftPart = processByteArray.left(pos) ;
    leftPart.remove(';') ;
    processByteArray = processByteArray.right(processByteArray.size() - pos - 2) ;
    return process335(leftPart) ;

}

temperatureRequest::temperatureRequest(char ch)
    : dialog335Request(ch)
{}

QString temperatureRequest::request335()
{
    return QString("KRDG?") + channel() ;
}

QString temperatureRequest::process335(QString &temperatureProcessArray)
{
    emit numericvalue(temperatureProcessArray.toDouble()) ;
    return "" ;
}

setHeaterRange::setHeaterRange(int rv, char ch)
    : dialog335Request(ch),
      rangeValue(qBound(0, rv, 3))
{

}

QString setHeaterRange::request335()
{
    return QString("RANGE ") + channelNo()
            + ","
            + QString::number(rangeValue)
            + "; RANGE?"
            + channel();
}

QString setHeaterRange::process335(QString &heaterRangeArray)
{
    emit numericvalue(heaterRangeArray.toInt()) ;
    return "" ;
}

setpoint::setpoint(double sv, char ch)
    : dialog335Request(ch),
      setpointValue(qBound(0., sv, 500.))
{

}

QString setpoint::request335()
{
    return QString("SETP ") + channelNo()
            + ","
            + QString::number(setpointValue)
            + "; SETP? "
            + channel();
}

QString setpoint::process335(QString & setpointArray)
{
    double a = setpointArray.toDouble() ;
    emit numericvalue(a) ;
    return "" ;
}
