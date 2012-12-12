#include "combivac.h"
#include <QDebug>
#include <QTime>

combivac::combivac(QObject *parent) :
    serial(serialSettings(BAUD19200,
                          DATA_8,
                          PAR_NONE,
                          STOP_1,
                          FLOW_OFF,
                          -1),parent)
{
    setPortName("COM7") ;
    open(ReadWrite) ;
}

//Initialisierung des Geräts
bool combivac::init()
{
//    close() ;
    //Wenn der port nicht offen ist -> Fehler
//    if (!open(ReadWrite))
//        return false ;
    flush() ;
    //Fragen nach Gerätestatus
    write("RSA\r") ;
    if (!waitForReadyRead(1000))
        return false ;
    QByteArray ba = readAll() ;
    if (ba != "0") return false ;
    return true ;
}

//Festlegen, dass es 3 Channel gibt
pressureRequest::pressureRequest(int channel) :
    Channel(qBound(1, channel, 3))
{
    qDebug() << "Konstruktor von" << this << "fuer Kanal" << Channel;
}

//Senden des Befehls (es gibt einen pointer von SerialRequest auf request !
QByteArray pressureRequest::request()
{
    qDebug() << "Request" << this << "Kanal:" << Channel;

    return QByteArray().append("RPV" + QString::number(Channel) + "\r") ;

}

//Verarbeitung der Daten
QString pressureRequest::process(QByteArray & pressureProcessArray)
{
    qDebug() << "Process" << this << "Kanal:" << Channel ;
// TODO Manchmal kommen Antworten, die noch ein "\r" am Anfang haben.
    int pos = pressureProcessArray.indexOf("\r") ;
    if (pos == -1) return "No termination character" ;
    QString ppa(pressureProcessArray.left(pos)) ;
    pressureProcessArray.remove(0, pos+1) ;
    //Wenn das Array keine Werte enthält -> Fehler
    if (ppa.isEmpty())
        return "Empty answer string" ;
    //Wenn der Druck unter dem Messbereich liegt (Fehlercode 1)
    if (ppa.startsWith("1"))
        return "Pressure to low" ;
    //Wenn der Druck über dem Messbreich liegt (Fehlerode 2)
    if (ppa.startsWith("2"))
        return "Pressure to high" ;
    //Wenn der Druck deutlich kleiner als de rMessbereich ist (Fehlercode 3)
    if (ppa.startsWith("3"))
        return "Pressure to low" ;
    //Wenn der Druck deutlich über dem Messbereich liegt (Fehlercode 4)
    if (ppa.startsWith("4"))
        return "Pressure to high"  ;
    //Wenn der Sensor aus ist (Fehlercode 5)
    if (ppa.startsWith("5"))
        return "Sensor is off" ;
    //Wenn die Hochspannung an ist (Code 6)
    if (ppa.startsWith("6"))
        return "HV on" ;
    //Wenn es einen Sensor Fehler gibt (Fehlercode 7)
    if (ppa.startsWith("7"))
        return "Sensor-Error" ;
    //Wenn das Gerät Fehlercode 9 (kein Sensor) zurückgibt
    if (ppa.startsWith("9"))
        return "no Sensor" ;
    //Wenn es keinen Ein-oder Ausschaltpunkt gibt
    if (ppa.startsWith("10"))
        return "no Trigger" ;
    //Wenn das Gerät Fehlercode 12 (Pirani-Fehler) zurückgibt
    if (ppa.startsWith("12"))
        return "Pirani-Error" ;
    if (ppa == "?\tX")
        return "Error Input" ;
    if (!ppa.startsWith("0"))
        return "undefined Error: " + ppa ;

    emit numericvalue(ppa.section("\t", 1).toDouble()) ;



    return "" ;


}
