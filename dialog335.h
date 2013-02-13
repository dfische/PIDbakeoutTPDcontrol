#ifndef DIALOG335_H
#define DIALOG335_H
#include "serial.h"
#include "serialrequest.h"

class dialog335Request : public serialRequest
{
    Q_OBJECT ;
private:
    char Channel ;
protected:
    dialog335Request(char ch) ;
    virtual QString request335() = 0 ;
    virtual QString process335(QString &) = 0 ;
    char channelNo() const ;
    char channel() const ;
private:
    QByteArray request() ;
    QString process(QByteArray &) ;
};


class temperatureRequest : public dialog335Request
{
    Q_OBJECT ;
public:
    explicit temperatureRequest(char ch='A');
    QString request335() ;
    QString process335(QString &) ;
};

class heaterOutputRequest : public dialog335Request
{
    Q_OBJECT ;
public:
    explicit heaterOutputRequest(char ch='A') ;
    QString request335() ;
    QString process335(QString &) ;
} ;

class setpoint : public dialog335Request
{
private:
    char Channel ;

public:
    explicit setpoint( char ch = 'A') ;
    QString request335() ;
    QString process335(QString &) ;
};

class setSetpoint : public setpoint
{
public:
    explicit setSetpoint(double sv = 300, char ch = 'A') ;
    QString request335() ;

private:
    double setpointValue ;
};

class setHeaterRange : public dialog335Request
{
private:
    char Channel ;
    int rangeValue ;
public:
    explicit setHeaterRange(int rv = 0 ,char ch = 'A') ;
    QString request335() ;
    QString process335(QString &) ;
};

class setPID : public dialog335Request
{
    Q_OBJECT
private:
    char Channel ;
    double pVal ;
    double iVal ;
    double dVal ;
public:
    explicit setPID(char ch = 'A', double pV = 100, double iV = 50, double dV = 0) ;
    QString request335() ;
    QString process335(QString &) ;
signals:
    void pValue(double) ;
    void iValue(double) ;
    void dValue(double) ;


};

class dialog335 : public serial
{
    Q_OBJECT
public:
    explicit dialog335(QObject *parent = 0);
    
private:
    bool init() ;
    bool answerComplete(const QByteArray &, serialRequest *nextRequest) ;

signals:
    
public slots:
    
};

#endif // DIALOG335_H
