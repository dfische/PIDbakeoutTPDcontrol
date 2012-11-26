#ifndef SERIALREQUEST_H
#define SERIALREQUEST_H
#include <QByteArray>

class serialRequest
{
public:
    serialRequest();
    //generieren der Abfrage
    virtual QByteArray request()=0 ;
    //verarbeitet die Anfrage
    virtual bool process(QByteArray&)=0 ;
};

#endif // SERIALREQUEST_H
