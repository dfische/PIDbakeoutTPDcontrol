#include "dialogrga.h"
#include "QTest"
dialogRGA::dialogRGA(QObject *parent) :
    serial(serialSettings(BAUD28800,
                          DATA_8,
                          PAR_NONE,
                          STOP_1,
                          FLOW_HARDWARE,
                          -1), parent)
{
    setPortName("COM10") ;
    open(ReadWrite) ;
}

bool dialogRGA::init()
{
    flush() ;
    write("ID?\r") ;
    if (!waitForReadyRead(1000))
        return false ;
    QByteArray ra = readAll() ;
    if (ra != QByteArray("SRSRGA200VER0.24SN14346\n\r"))
        return false ;

    return true ;

}

dialogRGA::~dialogRGA()
{
    write("FL0\rHV0\rMR0\r") ;
}

QByteArray dialogRGARequest::request()
{
    QString req(requestRGA()) ;
    return QByteArray().append((requestRGA() + "\r")) ;
}

QString dialogRGARequest::process(QByteArray & processByteArray)
{
    QTest::qWait(100) ;
    int pos = processByteArray.indexOf("\n\r") ;
    if (pos == -1)
        return "Wrong Answer from Device" ;
    QString leftPart = processByteArray.left(pos) ;
    leftPart.remove(';') ;
    processByteArray = processByteArray.right(processByteArray.size() - pos - 2) ;
    return processRGA(leftPart) ;

}

singleMassRequest::singleMassRequest(int Ma)
    : Mass(qBound(1, Ma, 200))
{

}

int singleMassRequest::mass() const
{
    return Mass ;
}

QString singleMassRequest::requestRGA()
{

    return QString ("MR") + mass() ;
}

QString singleMassRequest::processRGA(QString &massProcessArray)
{
    emit numericvalue(massProcessArray.toDouble()) ;
    return "" ;
}

//startFilament::startFilament(int EE, int IE, int VF, double FL)
//    : electronEnergy(qBound(25, EE, 105)),
//      ionEnergy(qBound(0, IE, 1)),
//      focusVoltage(qBound(0, VF, 150)),
//      filamentEmission(qBound(0., FL, 3.5))
//{

//}

QString startFilament::requestRGA()
{
    return QString ("FL*") ;
}

QString startFilament::processRGA(QString &)
{
//    QStringList list = filamentArray.split();
    return QString() ;
}

QString stopFilament::requestRGA()
{
    return QString ("FL0") ;
}

QString stopFilament::processRGA(QString &)
{
//    QStringList list = filamentArray.split();
    return QString() ;
}
