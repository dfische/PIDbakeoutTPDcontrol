#include "filamentbutton.h"
#include "dialogrga.h"


filamentButton::filamentButton(QWidget *parent) :
    QPushButton(parent),
    rg(0)
{
    setCheckable(true) ;
    connect(this, SIGNAL(toggled(bool)), this, SLOT(FilamentToggleTimer(bool))) ;

}

void filamentButton::setRGA(dialogRGA * a)
{
    rg = a ;
}

void filamentButton::FilamentToggleTimer(bool a)
{
    if (!rg)
        return ;
    dialogRGARequest *ab = new filamentRequest(a) ;
    connect(ab, SIGNAL(state(bool)), this, SLOT(textChange(bool))) ;
    rg->enqueue(ab) ;
}

void filamentButton::textChange(bool a)
{
    setText("Filament "  + (a ? QString("On") : QString("Off"))) ;
}
