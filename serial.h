#ifndef SERIAL_H
#define SERIAL_H
#include "qextserialport.h"
#include <QQueue>
#include <QPushButton>
#include <QMutex>
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
    bool isok(){return ErrorString.isEmpty();}
    void setMinimumDelay(int msec) ;
protected:
    virtual bool init()=0 ;
    void processError(const QString &) ;
    bool waitForReadyRead(int msecs) ;
    virtual bool answerComplete(const QByteArray &, serialRequest* nextRequest) ;

private:
    QString ErrorString ;
    QMutex mutex ;
    QQueue<serialRequest*> waiting ;
    QTimer delayTime ;
    bool awaitingResponse ;
    bool ignoreNext ;
    void clearQueue() ;
    void buildQueue() ;
    void childEvent(QChildEvent *) ;
    void prepareToWrite() ;
private slots:
    void read() ;
    void requestDestroyed() ;
    void writeNext() ;

public slots:
    void clearError() ;

signals:
    void Error(const QString &) ;

};


class deviceButton : public QPushButton
{
    Q_OBJECT

public:
    deviceButton(QWidget *parent=0) ;
    void setDevice(serial* dev) ;
private:
    serial* device ;
    void setButtonColor(const QColor & Color) ;
private slots:
    void resetDevice() ;
    void errorOccured(QString S) ;
};

#endif // SERIAL_H
