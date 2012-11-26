#include "combivac.h"

combivac::combivac(QObject *parent) :
    serial(serialSettings(BAUD19200,
                          DATA_8,
                          PAR_NONE,
                          STOP_1,
                          FLOW_OFF,
                          -1),parent)
{
    setPortName("COM6") ;

}

bool combivac::init()
{
    close() ;
    if (!open(ReadWrite))
        return false ;
    write("RSA\r\n") ;
    while (!bytesAvailable()) ;
    readAll() ;
    return true ;
}
