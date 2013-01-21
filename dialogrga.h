#ifndef DIALOGRGA_H
#define DIALOGRGA_H
#include "serial.h"
#include "serialrequest.h"

class dialogRGA : public serial
{
    Q_OBJECT
public:
    explicit dialogRGA(QObject *parent = 0) ;
    ~dialogRGA() ;
private:
    bool init() ;


};

class dialogRGARequest : public serialRequest
{
    Q_OBJECT
private:

    QByteArray request() ;
    QString process(QByteArray &) ;
protected:
    virtual QString requestRGA() = 0 ;
    virtual QString processRGA(QString &) = 0 ;


};

class singleMassRequest : public dialogRGARequest
{
    Q_OBJECT
public:
    QString requestRGA() ;
    QString processRGA(QString &) ;
    singleMassRequest(int Ma) ;
private:
    int Mass ;
protected:
    int mass() const ;
};

class startFilament : public dialogRGARequest
{
    Q_OBJECT
public:
    QString requestRGA() ;
    QString processRGA(QString &) ;
//    startFilament() ;

};

class stopFilament : public dialogRGARequest
{
    Q_OBJECT
public:
    QString requestRGA() ;
    QString processRGA(QString &) ;
    stopFilament() ;

};


#endif // DIALOGRGA_H
