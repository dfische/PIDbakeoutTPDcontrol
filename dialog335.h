#ifndef DIALOG335_H
#define DIALOG335_H
#include "serial.h"
#include "serialrequest.h"



class temperatureRequest : public serialRequest
{
    Q_OBJECT ;
private:
    char Channel ;
public:
    explicit temperatureRequest(char ch='A') : Channel(qBound('A', ch, 'B')) {}
    QByteArray request() ;
    QString process(QByteArray &) ;
};




class dialog335 : public serial
{
    Q_OBJECT
public:
    explicit dialog335(QObject *parent = 0);
    
private:
    bool init() ;

signals:
    
public slots:
    
};

#endif // DIALOG335_H
