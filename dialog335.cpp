#include "dialog335.h"
#include <QTest>
#include <QDebug>
dialog335::dialog335(QObject *parent) :
    serial(serialSettings(BAUD57600,
                          DATA_7,
                          PAR_ODD,
                          STOP_1,
                          FLOW_OFF,
                          -1), parent)
{
    setPortName("COM12") ;
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
    //QTest::qWait(100) ;
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
{setObjectName("Temperature 335 Request");}

QString temperatureRequest::request335()
{
    return QString("KRDG?") + channel() ;
}

QString temperatureRequest::process335(QString &temperatureProcessArray)
{
    emit numericvalue(temperatureProcessArray.toDouble()) ;
    return "" ;
}

heaterOutputRequest::heaterOutputRequest(char ch)
    :dialog335Request(ch)
{
    setObjectName("Heater Output Request");
}
QString heaterOutputRequest::request335()
{
    return QString("HTR?") + channelNo() ;
}

QString heaterOutputRequest::process335(QString & heaterOutputRequestArray)
{
    emit numericvalue(heaterOutputRequestArray.toDouble()) ;
    return "" ;
}

setHeaterRange::setHeaterRange(int rv, char ch)
    : dialog335Request(ch),
      rangeValue(qBound(0, rv, 3))
{
    setObjectName("Set Heater Range Request");
}

QString setHeaterRange::request335()
{
    return QString("RANGE ") + channelNo()
            + ","
            + QString::number(rangeValue)
            + "; RANGE?"
            + channel() ;
}

QString setHeaterRange::process335(QString &heaterRangeArray)
{
    emit numericvalue(heaterRangeArray.toInt()) ;
    return "" ;
}

setPID::setPID(char ch, double pV, double iV, double dV)
    :dialog335Request(ch) ,
    pVal(qBound(0., pV, 1000.)) ,
    iVal(qBound(0., iV, 1000.)) ,
    dVal(qBound(0., dV, 200.))
{
    setObjectName("Set PID Request");
}

QString setPID::request335()
{
    return QString("PID ") + channelNo()
            + ","
            + QString::number(pVal) + ","
            + QString::number(iVal) + ","
            + QString::number(dVal) + ","
            + "; PID?"
            + channelNo() ;
}

QString setPID::process335(QString &setPIDArray)
{
    QStringList list = setPIDArray.split(",") ;
    if (list.size() < 3)
        return "PID read error" ;
    emit pValue(list[0].toDouble()) ;
    emit iValue(list[1].toDouble()) ;
    emit dValue(list[2].toDouble()) ;
    return "" ;
}

setpoint::setpoint(char ch)
    : dialog335Request(ch)
{
    setObjectName("Setpoint Request");
}

QString setpoint::request335()
{
    return QString("SETP?")
            + channelNo() ;
}

QString setpoint::process335(QString & setpointArray)
{
    double a = setpointArray.toDouble() ;
    emit numericvalue(a) ;
    return "" ;
}

setSetpoint :: setSetpoint(double sv, char ch)
    : setpoint(ch),
      setpointValue(qBound(0., sv, 500.))
{

}

QString setSetpoint::request335()
{
    return QString("SETP ") + channelNo()
            + ","
            + QString::number(setpointValue)
            + "; "
            + setpoint::request335() ;
}

bool dialog335::answerComplete(const QByteArray &a, serialRequest *nextRequest)
{
    Q_UNUSED(nextRequest)
    return a.contains("\r\n") ;
}
