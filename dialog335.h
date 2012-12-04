#ifndef DIALOG335_H
#define DIALOG335_H
#include "serial.h"
#include "serialrequest.h"

class dialog335Request : public serialRequest
{
    Q_OBJECT ;
protected:
    virtual QString request335() = 0 ;
    virtual QString process335(QString &) = 0 ;
private:
    QByteArray request() ;
    QString process(QByteArray &) ;
};


class temperatureRequest : public dialog335Request
{
    Q_OBJECT ;
private:
    char Channel ;
public:
    explicit temperatureRequest(char ch='A') : Channel(qBound('A', ch, 'B')) {}
    QString request335() ;
    QString process335(QString &) ;
};


class setHeaterRange : public dialog335Request
{
private:
    char Channel ;
    int rangeValue ;
public:
    explicit setHeaterRange(int rv = 0 ,char ch = '1') ;
    QString request335() ;
    QString process335(QString &) ;
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
