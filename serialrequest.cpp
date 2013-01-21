#include "serialrequest.h"

serialRequest::serialRequest(bool singleUse = true)
    : single(singleUse)
{

}

bool serialRequest::singleUse() const
{
    return single ;
}
