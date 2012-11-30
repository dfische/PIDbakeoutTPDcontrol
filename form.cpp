#include "form.h"
#include "ui_form.h"
#include "combivac.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    cv = new combivac(this) ;
    ui->setupUi(this);
    ui->resetDevice->setDevice(cv);
    timer = new QTimer(this) ;
    timerIntervalChanged(ui->pressureTimeInterval ->value());
    connect(ui->pressureTimeInterval, SIGNAL(valueChanged(int)), this, SLOT(timerIntervalChanged(int))) ;
    connect(ui->stopPressureMeasurement, SIGNAL(clicked()), timer, SLOT(stop())) ;
    connect(ui->startPressureMeasurement, SIGNAL(clicked()), timer, SLOT(start())) ;
    connect(timer, SIGNAL(timeout()), this, SLOT(getValue())) ;
}

void Form::getValue()
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

void Form::timerIntervalChanged(int a)
{
    timer->setInterval(1000*a);
}

Form::~Form()
{
    delete ui;
}
