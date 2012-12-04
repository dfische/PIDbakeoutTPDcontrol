#include "form.h"
#include "ui_form.h"
#include "combivac.h"
#include "dialog335.h"
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    cv = new combivac(this) ;
    dl = new dialog335(this) ;
    ui->setupUi(this);
    ui->resetDevice->setDevice(cv);
    ui->resetPID->setDevice(dl) ;
    bakeoutTimer = new QTimer(this) ;
    PIDtimer =new QTimer(this) ;
    bakeoutTimerIntervalChanged(ui->pressureTimeInterval ->value());
    PIDtimerIntervalChanged(ui->PIDtempSpinBox ->value()) ;

    connect(ui->PIDtempSpinBox, SIGNAL(valueChanged(int)), this, SLOT(PIDtimerIntervalChanged(int))) ;
    connect(ui->StartPID, SIGNAL(clicked()), PIDtimer, SLOT(start())) ;
    connect(ui->StopPID, SIGNAL(clicked()), PIDtimer, SLOT(stop())) ;
    connect(PIDtimer, SIGNAL(timeout()), this, SLOT(getPIDValue())) ;

    connect(ui->pressureTimeInterval, SIGNAL(valueChanged(int)), this, SLOT(bakeoutTimerIntervalChanged(int))) ;
    connect(ui->stopPressureMeasurement, SIGNAL(clicked()), bakeoutTimer, SLOT(stop())) ;
    connect(ui->startPressureMeasurement, SIGNAL(clicked()), bakeoutTimer, SLOT(start())) ;
    connect(bakeoutTimer, SIGNAL(timeout()), this, SLOT(getBakeoutValue())) ;
}

void Form::getPIDValue()
{
    temperatureRequest* a = new temperatureRequest('A') ;
    temperatureRequest* b = new temperatureRequest('B') ;
    connect(a, SIGNAL(numericvalue(double)), ui->tempValueA, SLOT(setNum(double))) ;
    connect(b, SIGNAL(numericvalue(double)), ui->tempValueB, SLOT(setNum(double))) ;
    dl->enqueue(a) ;
    dl->enqueue(b) ;
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
    setHeaterRange * a = new setHeaterRange(index, 1) ;
    connect(a, SIGNAL(numericvalue(int)), ui->heaterRange1, SLOT(setCurrentIndex(int))) ;
    dl->enqueue(a) ;
}
