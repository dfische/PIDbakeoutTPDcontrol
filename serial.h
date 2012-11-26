#ifndef SERIAL_H
#define SERIAL_H
#include "qextserialport.h"
#include <QQueue>
#include <QPushButton>
class serialRequest ;

struct serialSettings : public PortSettings
{
    serialSettings(BaudRateType BR,
    DataBitsType DB,
    ParityType Parit,
    StopBitsType SB,
    FlowType FC,
    long TM)
    {
        BaudRate = BR ;
        DataBits = DB ;
        Parity = Parit ;
        StopBits = SB ;
        FlowControl = FC ;
        Timeout_Millisec = TM ;
    }
};

class serial : public QextSerialPort
{
    Q_OBJECT
public:
    explicit serial(PortSettings, QObject* parent=0) ;
    void enqueue(serialRequest* requestPointer) ;
    bool isok(){return ok;}
protected:
    virtual bool init()=0 ;

private:
    bool ok ;
    QQueue<serialRequest*> waiting ;
    void processError() ;

private slots:
    void read() ;

public slots:
    void clearError() ;

signals:
    void Error() ;

};


class deviceButton : public QPushButton
{
    Q_OBJECT

public:
    deviceButton(serial* device, QString Name, QWidget *parent=0) ;
private:
    serial* device ;
    void setButtonColor(const QColor & Color) ;
private slots:
    void resetDevice() ;
    void errorOccured() ;
};

#endif // SERIAL_H
