#ifndef SERIALREQUEST_H
#define SERIALREQUEST_H
#include <QByteArray>
#include <QObject>

class serialRequest : public QObject
{
    Q_OBJECT
public:
    serialRequest();
    //generieren der Abfrage
    virtual QByteArray request()=0 ;
    //verarbeitet die Anfrage
    virtual QString process(QByteArray&)=0 ;
signals:
    void numericvalue(double) ;
    void numericvalue(int) ;
    void state(bool) ;


};

#endif // SERIALREQUEST_H
