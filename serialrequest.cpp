#include "serialrequest.h"
#include "serial.h"

serialRequest::serialRequest(QObject* parent, bool singleUse)
    : QObject(parent),
      single(singleUse)
{
    serial *p = qobject_cast<serial*>(parent) ;
    if (p) p->enqueue(this) ;
}

bool serialRequest::singleUse() const
{
    return single ;
}
