#include "cdembutton.h"
#include "dialogrga.h"

CDEMButton::CDEMButton(QWidget *parent) :
    QPushButton(parent),
    rg(0)
{
    setCheckable(true) ;
    connect(this, SIGNAL(toggled(bool)), this, SLOT(CDEMToggleTimer(bool))) ;
}

void CDEMButton::setRGA(dialogRGA *a)
{
    rg = a ;
}

void CDEMButton::CDEMToggleTimer(bool a)
{
    if (!rg)
        return ;
    dialogRGARequest *ab = new CDEMRequest(a) ;
    connect(ab, SIGNAL(state(bool)), this, SLOT(textChange(bool))) ;
    rg->enqueue(ab) ;
}

void CDEMButton::textChange(bool a)
{
    setText("CDEM " + (a ? QString("On") : QString("Off"))) ;
}
