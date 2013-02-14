#ifndef SERIAL_H
#define SERIAL_H
#include "qextserialport.h"
#include <QQueue>
#include <QPushButton>
#include <QMutex>
#include <QTimer>
class serialRequest ;
class serialDebugBuffer ;
class QTableView ;

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
    ~serial() ;
    void enqueue(serialRequest* requestPointer) ;
    bool isok(){return ErrorString.isEmpty();}
    void setMinimumDelay(int msec) ;
    int minimumDelay() const ;
    void setDebugBufferSize(int items) ;
protected:
    virtual bool init()=0 ;
    void processError(const QString &) ;
    bool waitForReadyRead(int msecs) ;
    virtual bool answerComplete(const QByteArray &, serialRequest* nextRequest) ;
    qint64 write(const QByteArray &data) ;
    QByteArray readAll() ;

private:
    QString ErrorString ;
    QMutex queueMutex, writeMutex ;
    QQueue<serialRequest*> waiting ;
    QTimer delayTime ;
    serialDebugBuffer* debugBuffer ;
    QTableView *debugBufferView;
    void clearQueue() ;
    void buildQueue() ;
    void childEvent(QChildEvent *) ;
    void prepareToWrite(bool mandatoryTimer=false) ;
private slots:
    void read() ;
    void writeNext() ;

public slots:
    void clearError() ;
    void showDebugBuffer() ;

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
    QMenu *contextMenu ;
    void setButtonColor(const QColor & Color) ;
    void mouseReleaseEvent(QMouseEvent *e) ;
private slots:
    void resetDevice() ;
    void errorOccured(QString S) ;
    void showConfig() ;
};

#endif // SERIAL_H
