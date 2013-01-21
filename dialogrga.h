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

class filamentRequest : public dialogRGARequest
{
    Q_OBJECT
private:
    bool filament ;
public:
    QString requestRGA() ;
    QString processRGA(QString &) ;
    filamentRequest(bool) ;

};

class CDEMRequest : public dialogRGARequest
{
    Q_OBJECT
private:
    bool CDEM ;
public:
    QString requestRGA() ;
    QString processRGA(QString &) ;
    CDEMRequest(bool) ;
};




#endif // DIALOGRGA_H
