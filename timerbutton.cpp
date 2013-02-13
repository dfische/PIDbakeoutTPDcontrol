#include "timerbutton.h"

timerButton::timerButton(QWidget *parent) :
    QPushButton(parent)
{

    timer = new QTimer(this) ;
    setCheckable(true) ;
    connect(this, SIGNAL(toggled(bool)), this, SLOT(toggleTimer(bool))) ;
    connect(timer, SIGNAL(timeout()), this, SIGNAL(timeout())) ;

}

void timerButton::toggleTimer(bool a)
{
    if (a)
    {
        timer->start() ;
        this->setText("STOP");
    }
    else
    {
        timer->stop() ;
        this->setText("START") ;
    }

}


void timerButton::setTimerInterval(int a)
{
    timer->setInterval(1000*a) ;
}
