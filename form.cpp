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
    ui->startFilament->setRGA(rg) ;
    ui->startCDEM->setRGA(rg) ;
    ui->resetDevice->setDevice(cv);
    ui->resetPID->setDevice(dl) ;
    ui->resetRGA->setDevice(rg) ;
    bakeoutTimer = new QTimer(this) ;
    PIDtimer = new QTimer(this) ;

    bakeoutTimerIntervalChanged(ui->pressureTimeInterval ->value());
    //PIDtimerIntervalChanged(ui->PIDtempSpinBox->value()) ;




    connect(ui->startTPD, SIGNAL(timeout()), this, SLOT(getMassValue())) ;



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
    heaterOutputRequest1 = new heaterOutputRequest('1') ;
    heaterOutputRequest2 = new heaterOutputRequest('2') ;
    heaterOutputRequest1->setSingleUse(false) ;
    heaterOutputRequest2->setSingleUse(false) ;

    connect(heaterOutputRequest1, SIGNAL(numericvalue(double)), ui->HeaterOutput1, SLOT(setNum(double))) ;
    connect(heaterOutputRequest2, SIGNAL(numericvalue(double)), ui->HeaterOutput2, SLOT(setNum(double))) ;
    connect(ui->StartPID, SIGNAL(toggled(bool)), this, SLOT(heaterOutput(bool))) ;

    foreach(QCheckBox* checkBox, findChildren<QCheckBox*>())
        connect(checkBox, SIGNAL(toggled(bool)), this, SLOT(checkBoxToggled(bool))) ;


    initializeRequest(new pressureRequest(1), ui->pressureCombi1, ui->pressurePlot1, ui->combi1CheckBox) ;
    initializeRequest(new pressureRequest(2), ui->pressureCombi2, ui->pressurePlot2, ui->combi2CheckBox) ;
    initializeRequest(new temperatureRequest('A'), ui->tempValueA, ui->PIDPlot, ui->plotTemperatureA) ;
    initializeRequest(new temperatureRequest('B'), ui->tempValueB, ui->PIDPlot, ui->plotTemperatureB) ;
}

void Form::heaterOutput(bool a)
{
    if (a)
    {
        dl->enqueue(heaterOutputRequest1) ;
        dl->enqueue(heaterOutputRequest2) ;
    }
    else
    {
        heaterOutputRequest1->setParent(this) ;
        heaterOutputRequest2->setParent(this) ;
    }
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

//void Form::PIDtimerIntervalChanged(int b)
//{
//    PIDtimer->setInterval((1000*b)) ;
//}

void Form::checkBoxToggled(bool b)
{
    QCheckBox *checkBox = qobject_cast<QCheckBox*>(sender()) ;
    if (!requestMap.contains(checkBox)) return ;
    serialRequest* request =  requestMap[checkBox] ;
    if (!request) return ;
    if (!b)
    {        
        if (request) request->setParent(this);
    }
    else
    {
        if (request->inherits("dialog335Request"))
            dl->enqueue(request) ;
        if (request->inherits("pressureRequest"))
            cv->enqueue(request) ;
        if (request->inherits("dialogRGARequest"))
            rg->enqueue(request) ;
    }
}

serialRequest* Form::initializeRequest(serialRequest *request, QLabel *label, trackingPlot *plot, QCheckBox* checkBox)
{
    if (!request) return 0 ;
    request->setParent(this);
    if (label)
    {
        connect(request, SIGNAL(numericvalue(double)), label, SLOT(setNum(double))) ;
        connect(request, SIGNAL(numericvalue(int)), label, SLOT(setNum(int))) ;
    }
    if (plot)
        connect(request, SIGNAL(numericvalue(double)), plot, SLOT(addValue(double))) ;
//    connect(request, SIGNAL(destroyed()), this, SLOT(requestDeleted())) ;
    requestMap[checkBox] = request ;
    request->setSingleUse(false) ;
    return request ;
}

/*void Form::requestDeleted()
{
    serialRequest* request = (serialRequest*)sender() ;
    QList<QCheckBox*> checkBoxes ;
    foreach(QCheckBox* key, requestMap.keys())
        if (request == requestMap[key])
            checkBoxes << key ;
    foreach(QCheckBox* checkBox, checkBoxes)
    {
        requestMap.remove(checkBox) ;
        checkBox->setCheckState(Qt::Unchecked);
    }
}*/

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


//    PRESSUREREQUESTMACRO(combi1CheckBox, pressureCombi1, 1, pressurePlot1) ;
//    PRESSUREREQUESTMACRO(combi2CheckBox, pressureCombi2, 2, pressurePlot2) ;
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
