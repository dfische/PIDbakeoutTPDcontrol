#ifndef SERIALREQUEST_H
#define SERIALREQUEST_H
#include <QByteArray>
#include <QObject>

class serialRequest : public QObject
{
    Q_OBJECT
private:
    bool single ;
public:
    serialRequest(bool singleUse = false);
    //generieren der Abfrage
    virtual QByteArray request()=0 ;
    //verarbeitet die Anfrage
    virtual QString process(QByteArray&)=0 ;
    bool singleUse() const ;
signals:
    void numericvalue(double) ;
    void numericvalue(int) ;


};

#endif // SERIALREQUEST_H
