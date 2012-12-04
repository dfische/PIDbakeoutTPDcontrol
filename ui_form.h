/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created: Tue 4. Dec 16:17:29 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt_plot.h"
#include "serial.h"
#include "trackingplot.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTabWidget *tabWidget;
    QWidget *tabPID;
    QWidget *widget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *tempValueA;
    QLabel *label_26;
    QSpinBox *PIDtempSpinBox;
    QLabel *label_2;
    QLabel *tempValueB;
    QFormLayout *formLayout;
    QPushButton *StartPID;
    QPushButton *StopPID;
    QPushButton *SavePID;
    deviceButton *resetPID;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QComboBox *heaterOutput1Ohm;
    QLabel *label_5;
    QDoubleSpinBox *setpoint1;
    QLabel *setpoint1Label;
    QLabel *label_6;
    QComboBox *heaterRange1;
    QLabel *label_28;
    QLabel *label_7;
    QLabel *HeaterOutputA;
    QLabel *label_8;
    QLabel *ProportionaA;
    QLabel *label_29;
    QLabel *label_9;
    QLabel *IntegralA;
    QLabel *label_30;
    QLabel *label_10;
    QLabel *DerivativeA;
    QLabel *label_31;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QComboBox *heaterOutput2Ohm;
    QLabel *label_15;
    QDoubleSpinBox *setpoint2;
    QLabel *label_11;
    QComboBox *heaterRange2;
    QLabel *label_16;
    QLabel *HeaterOutputB;
    QLabel *label_12;
    QLabel *ProportionalB;
    QLabel *label_14;
    QLabel *IntegralB;
    QLabel *label_13;
    QLabel *DerivativeB;
    QwtPlot *PIDPlot;
    QWidget *tabBakeout;
    QWidget *layoutWidget;
    QFormLayout *formLayout_4;
    QPushButton *startPressureMeasurement;
    QPushButton *stopPressureMeasurement;
    deviceButton *resetDevice;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_22;
    QLabel *pressureCombi1;
    QLabel *label_23;
    QLabel *pressureCombi2;
    QLabel *label_24;
    QLabel *pressureIonGauge;
    QCheckBox *combi1CheckBox;
    QCheckBox *combi2CheckBox;
    QCheckBox *ionGaugeCheckBox;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_9;
    QLabel *label_25;
    QSpinBox *pressureTimeInterval;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    trackingPlot *pressurePlot1;
    trackingPlot *pressurePlot2;
    trackingPlot *ionGaugePlot;
    QWidget *tabTPD;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *startTPD;
    QPushButton *stopPID;
    QPushButton *savePID;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_3;
    QwtPlot *TPDmass1;
    QwtPlot *TPDmass2;
    QwtPlot *TPDmass3;
    QWidget *layoutWidget6;
    QFormLayout *formLayout_6;
    QLabel *label_17;
    QSpinBox *TPDMass1;
    QLabel *label_18;
    QSpinBox *TPDMass2;
    QLabel *label_19;
    QSpinBox *TPDMass3;
    QWidget *layoutWidget7;
    QFormLayout *formLayout_7;
    QLabel *label_20;
    QLabel *temperature335;
    QLabel *label_21;
    QLabel *temperatureThermocouple;
    QWidget *layoutWidget8;
    QFormLayout *formLayout_5;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(816, 919);
        tabWidget = new QTabWidget(Form);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 771, 881));
        tabPID = new QWidget();
        tabPID->setObjectName(QString::fromUtf8("tabPID"));
        widget = new QWidget(tabPID);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 12, 741, 811));
        gridLayout_7 = new QGridLayout(widget);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tempValueA = new QLabel(widget);
        tempValueA->setObjectName(QString::fromUtf8("tempValueA"));

        gridLayout->addWidget(tempValueA, 0, 1, 1, 1);

        label_26 = new QLabel(widget);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout->addWidget(label_26, 1, 0, 1, 1);

        PIDtempSpinBox = new QSpinBox(widget);
        PIDtempSpinBox->setObjectName(QString::fromUtf8("PIDtempSpinBox"));
        PIDtempSpinBox->setMinimum(1);

        gridLayout->addWidget(PIDtempSpinBox, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        tempValueB = new QLabel(widget);
        tempValueB->setObjectName(QString::fromUtf8("tempValueB"));

        gridLayout->addWidget(tempValueB, 4, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        StartPID = new QPushButton(widget);
        StartPID->setObjectName(QString::fromUtf8("StartPID"));

        formLayout->setWidget(0, QFormLayout::LabelRole, StartPID);

        StopPID = new QPushButton(widget);
        StopPID->setObjectName(QString::fromUtf8("StopPID"));

        formLayout->setWidget(0, QFormLayout::FieldRole, StopPID);

        SavePID = new QPushButton(widget);
        SavePID->setObjectName(QString::fromUtf8("SavePID"));

        formLayout->setWidget(1, QFormLayout::LabelRole, SavePID);

        resetPID = new deviceButton(widget);
        resetPID->setObjectName(QString::fromUtf8("resetPID"));

        formLayout->setWidget(1, QFormLayout::FieldRole, resetPID);


        gridLayout_7->addLayout(formLayout, 0, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 0, 0, 1, 2);

        heaterOutput1Ohm = new QComboBox(widget);
        heaterOutput1Ohm->setObjectName(QString::fromUtf8("heaterOutput1Ohm"));

        gridLayout_5->addWidget(heaterOutput1Ohm, 0, 2, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 1, 0, 1, 1);

        setpoint1 = new QDoubleSpinBox(widget);
        setpoint1->setObjectName(QString::fromUtf8("setpoint1"));

        gridLayout_5->addWidget(setpoint1, 1, 1, 1, 1);

        setpoint1Label = new QLabel(widget);
        setpoint1Label->setObjectName(QString::fromUtf8("setpoint1Label"));

        gridLayout_5->addWidget(setpoint1Label, 1, 2, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_5->addWidget(label_6, 2, 0, 1, 1);

        heaterRange1 = new QComboBox(widget);
        heaterRange1->setObjectName(QString::fromUtf8("heaterRange1"));

        gridLayout_5->addWidget(heaterRange1, 2, 1, 1, 1);

        label_28 = new QLabel(widget);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_5->addWidget(label_28, 2, 2, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 3, 0, 1, 1);

        HeaterOutputA = new QLabel(widget);
        HeaterOutputA->setObjectName(QString::fromUtf8("HeaterOutputA"));

        gridLayout_5->addWidget(HeaterOutputA, 3, 1, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 4, 0, 1, 1);

        ProportionaA = new QLabel(widget);
        ProportionaA->setObjectName(QString::fromUtf8("ProportionaA"));

        gridLayout_5->addWidget(ProportionaA, 4, 1, 1, 1);

        label_29 = new QLabel(widget);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_5->addWidget(label_29, 4, 2, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_5->addWidget(label_9, 5, 0, 1, 1);

        IntegralA = new QLabel(widget);
        IntegralA->setObjectName(QString::fromUtf8("IntegralA"));

        gridLayout_5->addWidget(IntegralA, 5, 1, 1, 1);

        label_30 = new QLabel(widget);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_5->addWidget(label_30, 5, 2, 1, 1);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 6, 0, 1, 1);

        DerivativeA = new QLabel(widget);
        DerivativeA->setObjectName(QString::fromUtf8("DerivativeA"));

        gridLayout_5->addWidget(DerivativeA, 6, 1, 1, 1);

        label_31 = new QLabel(widget);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_5->addWidget(label_31, 6, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 1, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 0, 0, 1, 2);

        heaterOutput2Ohm = new QComboBox(widget);
        heaterOutput2Ohm->setObjectName(QString::fromUtf8("heaterOutput2Ohm"));

        gridLayout_6->addWidget(heaterOutput2Ohm, 0, 2, 1, 1);

        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 1, 0, 1, 1);

        setpoint2 = new QDoubleSpinBox(widget);
        setpoint2->setObjectName(QString::fromUtf8("setpoint2"));

        gridLayout_6->addWidget(setpoint2, 1, 1, 1, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_6->addWidget(label_11, 2, 0, 1, 1);

        heaterRange2 = new QComboBox(widget);
        heaterRange2->setObjectName(QString::fromUtf8("heaterRange2"));

        gridLayout_6->addWidget(heaterRange2, 2, 1, 1, 1);

        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 3, 0, 1, 1);

        HeaterOutputB = new QLabel(widget);
        HeaterOutputB->setObjectName(QString::fromUtf8("HeaterOutputB"));

        gridLayout_6->addWidget(HeaterOutputB, 3, 1, 1, 1);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_6->addWidget(label_12, 4, 0, 1, 1);

        ProportionalB = new QLabel(widget);
        ProportionalB->setObjectName(QString::fromUtf8("ProportionalB"));

        gridLayout_6->addWidget(ProportionalB, 4, 1, 1, 1);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_6->addWidget(label_14, 5, 0, 1, 1);

        IntegralB = new QLabel(widget);
        IntegralB->setObjectName(QString::fromUtf8("IntegralB"));

        gridLayout_6->addWidget(IntegralB, 5, 1, 1, 1);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_6->addWidget(label_13, 6, 0, 1, 1);

        DerivativeB = new QLabel(widget);
        DerivativeB->setObjectName(QString::fromUtf8("DerivativeB"));

        gridLayout_6->addWidget(DerivativeB, 6, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 1, 1, 1, 1);

        PIDPlot = new QwtPlot(widget);
        PIDPlot->setObjectName(QString::fromUtf8("PIDPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PIDPlot->sizePolicy().hasHeightForWidth());
        PIDPlot->setSizePolicy(sizePolicy);
        PIDPlot->setMinimumSize(QSize(0, 300));

        gridLayout_7->addWidget(PIDPlot, 2, 0, 1, 2);

        tabWidget->addTab(tabPID, QString());
        tabBakeout = new QWidget();
        tabBakeout->setObjectName(QString::fromUtf8("tabBakeout"));
        layoutWidget = new QWidget(tabBakeout);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 158, 54));
        formLayout_4 = new QFormLayout(layoutWidget);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        startPressureMeasurement = new QPushButton(layoutWidget);
        startPressureMeasurement->setObjectName(QString::fromUtf8("startPressureMeasurement"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, startPressureMeasurement);

        stopPressureMeasurement = new QPushButton(layoutWidget);
        stopPressureMeasurement->setObjectName(QString::fromUtf8("stopPressureMeasurement"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, stopPressureMeasurement);

        resetDevice = new deviceButton(layoutWidget);
        resetDevice->setObjectName(QString::fromUtf8("resetDevice"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, resetDevice);

        layoutWidget1 = new QWidget(tabBakeout);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(200, 0, 225, 65));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_2->addWidget(label_22, 0, 0, 1, 1);

        pressureCombi1 = new QLabel(layoutWidget1);
        pressureCombi1->setObjectName(QString::fromUtf8("pressureCombi1"));

        gridLayout_2->addWidget(pressureCombi1, 0, 1, 1, 1);

        label_23 = new QLabel(layoutWidget1);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_2->addWidget(label_23, 1, 0, 1, 1);

        pressureCombi2 = new QLabel(layoutWidget1);
        pressureCombi2->setObjectName(QString::fromUtf8("pressureCombi2"));

        gridLayout_2->addWidget(pressureCombi2, 1, 1, 1, 1);

        label_24 = new QLabel(layoutWidget1);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_2->addWidget(label_24, 2, 0, 1, 1);

        pressureIonGauge = new QLabel(layoutWidget1);
        pressureIonGauge->setObjectName(QString::fromUtf8("pressureIonGauge"));

        gridLayout_2->addWidget(pressureIonGauge, 2, 1, 1, 1);

        combi1CheckBox = new QCheckBox(layoutWidget1);
        combi1CheckBox->setObjectName(QString::fromUtf8("combi1CheckBox"));

        gridLayout_2->addWidget(combi1CheckBox, 0, 2, 1, 1);

        combi2CheckBox = new QCheckBox(layoutWidget1);
        combi2CheckBox->setObjectName(QString::fromUtf8("combi2CheckBox"));

        gridLayout_2->addWidget(combi2CheckBox, 1, 2, 1, 1);

        ionGaugeCheckBox = new QCheckBox(layoutWidget1);
        ionGaugeCheckBox->setObjectName(QString::fromUtf8("ionGaugeCheckBox"));

        gridLayout_2->addWidget(ionGaugeCheckBox, 2, 2, 1, 1);

        layoutWidget2 = new QWidget(tabBakeout);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(450, 10, 72, 22));
        formLayout_9 = new QFormLayout(layoutWidget2);
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        formLayout_9->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(layoutWidget2);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, label_25);

        pressureTimeInterval = new QSpinBox(layoutWidget2);
        pressureTimeInterval->setObjectName(QString::fromUtf8("pressureTimeInterval"));
        pressureTimeInterval->setMinimum(1);

        formLayout_9->setWidget(0, QFormLayout::FieldRole, pressureTimeInterval);

        layoutWidget3 = new QWidget(tabBakeout);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 80, 741, 761));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pressurePlot1 = new trackingPlot(layoutWidget3);
        pressurePlot1->setObjectName(QString::fromUtf8("pressurePlot1"));
        pressurePlot1->setFrameShape(QFrame::StyledPanel);
        pressurePlot1->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(pressurePlot1);

        pressurePlot2 = new trackingPlot(layoutWidget3);
        pressurePlot2->setObjectName(QString::fromUtf8("pressurePlot2"));
        pressurePlot2->setFrameShape(QFrame::StyledPanel);
        pressurePlot2->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(pressurePlot2);

        ionGaugePlot = new trackingPlot(layoutWidget3);
        ionGaugePlot->setObjectName(QString::fromUtf8("ionGaugePlot"));
        ionGaugePlot->setFrameShape(QFrame::StyledPanel);
        ionGaugePlot->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(ionGaugePlot);

        tabWidget->addTab(tabBakeout, QString());
        tabTPD = new QWidget();
        tabTPD->setObjectName(QString::fromUtf8("tabTPD"));
        layoutWidget4 = new QWidget(tabTPD);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 10, 77, 83));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        startTPD = new QPushButton(layoutWidget4);
        startTPD->setObjectName(QString::fromUtf8("startTPD"));

        verticalLayout_2->addWidget(startTPD);

        stopPID = new QPushButton(layoutWidget4);
        stopPID->setObjectName(QString::fromUtf8("stopPID"));

        verticalLayout_2->addWidget(stopPID);

        savePID = new QPushButton(layoutWidget4);
        savePID->setObjectName(QString::fromUtf8("savePID"));

        verticalLayout_2->addWidget(savePID);

        layoutWidget5 = new QWidget(tabTPD);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 120, 721, 707));
        verticalLayout_3 = new QVBoxLayout(layoutWidget5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        TPDmass1 = new QwtPlot(layoutWidget5);
        TPDmass1->setObjectName(QString::fromUtf8("TPDmass1"));

        verticalLayout_3->addWidget(TPDmass1);

        TPDmass2 = new QwtPlot(layoutWidget5);
        TPDmass2->setObjectName(QString::fromUtf8("TPDmass2"));

        verticalLayout_3->addWidget(TPDmass2);

        TPDmass3 = new QwtPlot(layoutWidget5);
        TPDmass3->setObjectName(QString::fromUtf8("TPDmass3"));

        verticalLayout_3->addWidget(TPDmass3);

        layoutWidget6 = new QWidget(tabTPD);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(120, 10, 83, 74));
        formLayout_6 = new QFormLayout(layoutWidget6);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        formLayout_6->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget6);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_17);

        TPDMass1 = new QSpinBox(layoutWidget6);
        TPDMass1->setObjectName(QString::fromUtf8("TPDMass1"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, TPDMass1);

        label_18 = new QLabel(layoutWidget6);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_18);

        TPDMass2 = new QSpinBox(layoutWidget6);
        TPDMass2->setObjectName(QString::fromUtf8("TPDMass2"));

        formLayout_6->setWidget(1, QFormLayout::FieldRole, TPDMass2);

        label_19 = new QLabel(layoutWidget6);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, label_19);

        TPDMass3 = new QSpinBox(layoutWidget6);
        TPDMass3->setObjectName(QString::fromUtf8("TPDMass3"));

        formLayout_6->setWidget(2, QFormLayout::FieldRole, TPDMass3);

        layoutWidget7 = new QWidget(tabTPD);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(230, 20, 136, 34));
        formLayout_7 = new QFormLayout(layoutWidget7);
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        formLayout_7->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(layoutWidget7);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_20);

        temperature335 = new QLabel(layoutWidget7);
        temperature335->setObjectName(QString::fromUtf8("temperature335"));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, temperature335);

        label_21 = new QLabel(layoutWidget7);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_21);

        temperatureThermocouple = new QLabel(layoutWidget7);
        temperatureThermocouple->setObjectName(QString::fromUtf8("temperatureThermocouple"));

        formLayout_7->setWidget(1, QFormLayout::FieldRole, temperatureThermocouple);

        tabWidget->addTab(tabTPD, QString());
        layoutWidget8 = new QWidget(Form);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(0, 0, 2, 2));
        formLayout_5 = new QFormLayout(layoutWidget8);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Form);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Temp. Channel A :", 0, QApplication::UnicodeUTF8));
        tempValueA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("Form", "Temp. Polling Interval", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "Temp. Channel B :", 0, QApplication::UnicodeUTF8));
        tempValueB->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        StartPID->setText(QApplication::translate("Form", "Start", 0, QApplication::UnicodeUTF8));
        StopPID->setText(QApplication::translate("Form", "Stop", 0, QApplication::UnicodeUTF8));
        SavePID->setText(QApplication::translate("Form", "Save", 0, QApplication::UnicodeUTF8));
        resetPID->setText(QApplication::translate("Form", "Reset", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "Heater Output 1", 0, QApplication::UnicodeUTF8));
        heaterOutput1Ohm->clear();
        heaterOutput1Ohm->insertItems(0, QStringList()
         << QApplication::translate("Form", "25 Ohm", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "50 Ohm", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("Form", "Setpoint", 0, QApplication::UnicodeUTF8));
        setpoint1Label->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form", "Heater Range", 0, QApplication::UnicodeUTF8));
        heaterRange1->clear();
        heaterRange1->insertItems(0, QStringList()
         << QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "4", 0, QApplication::UnicodeUTF8)
        );
        label_28->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Form", "Heater Output", 0, QApplication::UnicodeUTF8));
        HeaterOutputA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Form", "Proportional", 0, QApplication::UnicodeUTF8));
        ProportionaA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Form", "Integral", 0, QApplication::UnicodeUTF8));
        IntegralA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Form", "Derivative", 0, QApplication::UnicodeUTF8));
        DerivativeA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form", "Heater Output 2", 0, QApplication::UnicodeUTF8));
        heaterOutput2Ohm->clear();
        heaterOutput2Ohm->insertItems(0, QStringList()
         << QApplication::translate("Form", "25 Ohm", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "50 Ohm", 0, QApplication::UnicodeUTF8)
        );
        label_15->setText(QApplication::translate("Form", "Setpoint", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Form", "Heater Range", 0, QApplication::UnicodeUTF8));
        heaterRange2->clear();
        heaterRange2->insertItems(0, QStringList()
         << QApplication::translate("Form", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "3", 0, QApplication::UnicodeUTF8)
        );
        label_16->setText(QApplication::translate("Form", "Heater Output", 0, QApplication::UnicodeUTF8));
        HeaterOutputB->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Form", "Proportional", 0, QApplication::UnicodeUTF8));
        ProportionalB->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Form", "Integral", 0, QApplication::UnicodeUTF8));
        IntegralB->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Form", "Derivative", 0, QApplication::UnicodeUTF8));
        DerivativeB->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabPID), QApplication::translate("Form", "PID", 0, QApplication::UnicodeUTF8));
        startPressureMeasurement->setText(QApplication::translate("Form", "Start", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        stopPressureMeasurement->setToolTip(QApplication::translate("Form", "stop measurement", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        stopPressureMeasurement->setText(QApplication::translate("Form", "Stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        resetDevice->setToolTip(QApplication::translate("Form", "testtooltip", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        resetDevice->setText(QApplication::translate("Form", "Reset", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("Form", "Pressure Combi 1", 0, QApplication::UnicodeUTF8));
        pressureCombi1->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Form", "Pressure Combi 2", 0, QApplication::UnicodeUTF8));
        pressureCombi2->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Form", "Pressure Ion Gauge", 0, QApplication::UnicodeUTF8));
        pressureIonGauge->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        combi1CheckBox->setText(QApplication::translate("Form", "CheckBox", 0, QApplication::UnicodeUTF8));
        combi2CheckBox->setText(QApplication::translate("Form", "CheckBox", 0, QApplication::UnicodeUTF8));
        ionGaugeCheckBox->setText(QApplication::translate("Form", "CheckBox", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("Form", "Time", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabBakeout), QApplication::translate("Form", "Bakeout", 0, QApplication::UnicodeUTF8));
        startTPD->setText(QApplication::translate("Form", "Start", 0, QApplication::UnicodeUTF8));
        stopPID->setText(QApplication::translate("Form", "Stop", 0, QApplication::UnicodeUTF8));
        savePID->setText(QApplication::translate("Form", "Save", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Form", "Mass 1", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Form", "Mass 2", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("Form", "Mass 3", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Form", "Temperature 335", 0, QApplication::UnicodeUTF8));
        temperature335->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Form", "Thermocouple", 0, QApplication::UnicodeUTF8));
        temperatureThermocouple->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabTPD), QApplication::translate("Form", "TPD", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
