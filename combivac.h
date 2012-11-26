#ifndef COMBIVAC_H
#define COMBIVAC_H

#include "serial.h"

class combivac : public serial
{
    Q_OBJECT
private:
    bool init() ;
public:
    explicit combivac(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // COMBIVAC_H
