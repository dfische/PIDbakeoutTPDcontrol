#include "form.h"
#include "ui_form.h"
#include "combivac.h"
#include "dialog335.h"
#include "dialogrga.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    cv = new combivac(this) ;
    dl = new dialog335(this) ;
    rg = new dialogRGA(this) ;
    ui->setupUi(this);
    ui->resetDevice->setDevice(cv);
    ui->resetPID->setDevice(dl) ;
    ui->resetRGA->setDevice(rg) ;
    bakeoutTimer = new QTimer(this) ;
    PIDtimer = new QTimer(this) ;

    bakeoutTimerIntervalChanged(ui->pressureTimeInterval ->value());
    PIDtimerIntervalChanged(ui->PIDtempSpinBox->value()) ;


    ui->startTPD->setTimerInterval(1);

    connect(ui->startTPD, SIGNAL(timeout()), this, SLOT(getMassValue())) ;



    connect(ui->PIDtempSpinBox, SIGNAL(valueChanged(int)), this, SLOT(PIDtimerIntervalChanged(int))) ;
    connect(ui->StartPID, SIGNAL(clicked()), PIDtimer, SLOT(start())) ;
    connect(ui->StopPID, SIGNAL(clicked()), PIDtimer, SLOT(stop())) ;
    connect(PIDtimer, SIGNAL(timeout()), this, SLOT(getPIDValue())) ;

    connect(ui->pressureTimeInterval, SIGNAL(valueChanged(int)), this, SLOT(bakeoutTimerIntervalChanged(int))) ;
    connect(ui->stopPressureMeasurement, SIGNAL(clicked()), bakeoutTimer, SLOT(stop())) ;
    connect(ui->startPressureMeasurement, SIGNAL(clicked()), bakeoutTimer, SLOT(start())) ;
    connect(bakeoutTimer, SIGNAL(timeout()), this, SLOT(getBakeoutValue())) ;

    connect(ui->pSpin1, SIGNAL(valueChanged(int)), this, SLOT(pidValueChanged1())) ;
    connect(ui->iSpin1, SIGNAL(valueChanged(int)), this, SLOT(pidValueChanged1())) ;
    connect(ui->dSpin1, SIGNAL(valueChanged(int)), this, SLOT(pidValueChanged1())) ;
    connect(ui->pSpin2, SIGNAL(valueChanged(int)), this, SLOT(pidValueChanged2())) ;
    connect(ui->iSpin2, SIGNAL(valueChanged(int)), this, SLOT(pidValueChanged2())) ;
    connect(ui->dSpin2, SIGNAL(valueChanged(int)), this, SLOT(pidValueChanged2())) ;
}

void Form::getPIDValue()
{
    temperatureRequest* temperature1 = new temperatureRequest('A') ;
    temperatureRequest* temperature2 = new temperatureRequest('B') ;
    connect(temperature1, SIGNAL(numericvalue(double)), ui->tempValueA, SLOT(setNum(double))) ;
    connect(temperature2, SIGNAL(numericvalue(double)), ui->tempValueB, SLOT(setNum(double))) ;
    heaterOutputRequest* heaterOutput1 = new heaterOutputRequest('1') ;
    heaterOutputRequest* heaterOutput2 = new heaterOutputRequest('2') ;
    connect(heaterOutput1, SIGNAL(numericvalue(double)), ui->HeaterOutput1, SLOT(setNum(double))) ;
    connect(heaterOutput2, SIGNAL(numericvalue(double)), ui->HeaterOutput2, SLOT(setNum(double))) ;
    dl->enqueue(temperature1) ;
    dl->enqueue(temperature2) ;
    dl->enqueue(heaterOutput1) ;
    dl->enqueue(heaterOutput2) ;


}

void Form::getMassValue()
{
    singleMassRequest* mass = 0 ;
#define MASSREQUESTMACRO(CHECKBOX, LABEL, SPINBOX, PLOT) \
    if(ui->CHECKBOX->isChecked()) \
{    \
    mass = new singleMassRequest(ui->SPINBOX->value()) ; \
    connect(mass, SIGNAL(numericvalue(double)), ui->LABEL, SLOT(setNum(double))) ; \
    connect(mass, SIGNAL(numericvalue(double)), ui->PLOT, SLOT(addValue(double))) ; \
    rg->enqueue(mass) ; \
}
    MASSREQUESTMACRO(mass1CheckBox, mass1Label, TPDMass1, TPDmass1Plot) ;
    MASSREQUESTMACRO(mass2CheckBox, mass2Label, TPDMass2, TPDmass2Plot) ;
    MASSREQUESTMACRO(mass3CheckBox, mass3Label, TPDMass3, TPDmass3Plot) ;

}

void Form::PIDtimerIntervalChanged(int b)
{
    PIDtimer->setInterval((1000*b)) ;
}


void Form::getBakeoutValue()
{
    pressureRequest * request =0 ;
#define PRESSUREREQUESTMACRO(CHECKBOX, PRESSURECOMBI, NUMBER, PLOT) \
    if(ui->CHECKBOX->isChecked()) \
    { \
        request = new pressureRequest(NUMBER) ; \
        connect(request, SIGNAL(numericvalue(double)), ui->PRESSURECOMBI, SLOT(setNum(double))) ; \
    connect(request, SIGNAL(numericvalue(double)), ui->PLOT, SLOT(addValue(double))) ;\
        cv->enqueue(request); \
    }


    PRESSUREREQUESTMACRO(combi1CheckBox, pressureCombi1, 1, pressurePlot1) ;
    PRESSUREREQUESTMACRO(combi2CheckBox, pressureCombi2, 2, pressurePlot2) ;
    PRESSUREREQUESTMACRO(ionGaugeCheckBox, pressureIonGauge, 3, ionGaugePlot) ;

}



void Form::bakeoutTimerIntervalChanged(int a)
{
    bakeoutTimer->setInterval(1000*a);
}

Form::~Form()
{
    delete ui;
}

void Form::on_heaterRange1_currentIndexChanged(int index)
{
    setHeaterRange * a = new setHeaterRange(index, 'A') ;
    connect(a, SIGNAL(numericvalue(int)), ui->heaterRange1, SLOT(setCurrentIndex(int))) ;
    dl->enqueue(a) ;
}

void Form::on_heaterRange2_currentIndexChanged(int index)
{
    setHeaterRange * a = new setHeaterRange(index, 'B') ;
    connect(a, SIGNAL(numericvalue(int)), ui->heaterRange2, SLOT(setCurrentIndex(int))) ;
    dl->enqueue(a) ;
}

void Form::on_setpoint1_valueChanged(double arg1)
{
    setpoint * a = new setpoint('A') ;
    connect(a, SIGNAL(numericvalue(double)), ui->setpoint1Label, SLOT(setNum(double))) ;
   // connect(a, SIGNAL(numericvalue(double)), ui->setpoint1, SLOT(setValue(double))) ;
    dl->enqueue(new setSetpoint(arg1,'A'));
    dl->enqueue(a) ;
}

void Form::on_setpoint2_valueChanged(double arg1)
{
    setpoint * a = new setpoint('B') ;
    connect(a, SIGNAL(numericvalue(double)), ui->setpoint2Label, SLOT(setNum(double))) ;
   // connect(a, SIGNAL(numericvalue(double)), ui->setpoint1, SLOT(setValue(double))) ;
    dl->enqueue(new setSetpoint(arg1,'B'));
    dl->enqueue(a) ;
}

void Form::pidValueChanged1()
{
    setPID *a = new setPID('A', ui->pSpin1->value(), ui->iSpin1->value(), ui->dSpin1->value()) ;
    connect(a, SIGNAL(pValue(double)), ui->pValue1, SLOT(setNum(double))) ;
    connect(a, SIGNAL(iValue(double)), ui->iValue1, SLOT(setNum(double))) ;
    connect(a, SIGNAL(dValue(double)), ui->dValue1, SLOT(setNum(double))) ;
    dl->enqueue(a) ;
}

void Form::pidValueChanged2()
{
    setPID *a = new setPID('B', ui->pSpin2->value(), ui->iSpin2->value(), ui->dSpin2->value()) ;
    connect(a, SIGNAL(pValue(double)), ui->pValue2, SLOT(setNum(double))) ;
    connect(a, SIGNAL(iValue(double)), ui->iValue2, SLOT(setNum(double))) ;
    connect(a, SIGNAL(dValue(double)), ui->dValue2, SLOT(setNum(double))) ;
    dl->enqueue(a) ;
}
