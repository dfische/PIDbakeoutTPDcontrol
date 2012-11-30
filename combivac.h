#ifndef COMBIVAC_H
#define COMBIVAC_H

#include "serial.h"
#include "serialrequest.h"

class pressureRequest : public serialRequest
{
    Q_OBJECT
private:
    int Channel ;
public:
    pressureRequest(int Channel = 1) ;
    QByteArray request() ;
    QString process(QByteArray &) ;
};

class combivac : public serial
{
    Q_OBJECT
private:
    bool init() ;
public:
    explicit combivac(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // COMBIVAC_H
