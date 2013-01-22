#include "serialrequest.h"
#include "serial.h"

serialRequest::serialRequest(QObject* parent, bool singleUse = true)
    : single(singleUse),
      QObject(parent)
{
    serial *p = qobject_cast<serial*>(parent) ;
    if (p) p->enqueue(this) ;
}

bool serialRequest::singleUse() const
{
    return single ;
}
