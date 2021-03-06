#include "dialogrga.h"
#include "QTest"
#include <QDebug>
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
    qDebug() << "Filament abgeschaltet" ;
}

bool dialogRGA::answerComplete(const QByteArray & a, serialRequest *nextRequest)
{
    dialogRGARequest* nr = dynamic_cast<dialogRGARequest*>(nextRequest) ; // TODO in serial::enqueue() einbauen
    if (nr) return nr->answerComplete(a) ;
    return a.contains("\n\r") ;
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

    return QString ("MR") + QString::number(mass()) ;
}

QString singleMassRequest::process(QByteArray &massProcessArray)
{
    if (massProcessArray.size() != 4)
        return "Communication Error" ;
    emit numericvalue(*((qint32 *)massProcessArray.data())*5.95E-13) ;
    return "" ;
}

QString singleMassRequest::processRGA(QString &)
{
    return "" ;
}

//startFilament::startFilament(int EE, int IE, int VF, double FL)
//    : electronEnergy(qBound(25, EE, 105)),
//      ionEnergy(qBound(0, IE, 1)),
//      focusVoltage(qBound(0, VF, 150)),
//      filamentEmission(qBound(0., FL, 3.5))
//{

//}

filamentRequest::filamentRequest(bool a)
    : filament(a)
{

}

QString filamentRequest::requestRGA()
{
    return QString("FL") + (filament ? QString("*") : QString("0")) ;
}

QString filamentRequest::processRGA(QString &s)
{
    if (s == "1")
    {
        emit state(filament)  ;
    }
    else
    {
        return "Filament Error" ;
    }
    return QString() ;
}

CDEMRequest::CDEMRequest(bool a)
    :CDEM(a)
{

}

QString CDEMRequest::requestRGA()
{
    return QString("HV") + (CDEM ? QString("*") : QString("0")) ;//+ QString("NF7") + QString("CA") ;
}

QString CDEMRequest::processRGA(QString & b)
{
    if(b == "1")
    {
        emit state(b == "1") ;
    }
    else
    {
        return "CDEM Error" ;
    }
    return QString() ;
}

bool dialogRGARequest::answerComplete(const QByteArray &a)
{
    return a.contains("\n\r") ;
}

bool singleMassRequest::answerComplete(const QByteArray &a)
{
    return a.size() >= 4 ;
}
