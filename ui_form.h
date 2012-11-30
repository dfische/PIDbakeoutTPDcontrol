/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created: Thu 29. Nov 12:04:43 2012
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
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QFormLayout *TempValue;
    QLabel *label;
    QLabel *tempValueA;
    QLabel *label_2;
    QLabel *tempValueB;
    QFormLayout *formLayout;
    QPushButton *StartPID;
    QPushButton *SavePID;
    QPushButton *StopPID;
    QFormLayout *formLayout_2;
    QFormLayout *HeaterA;
    QLabel *label_3;
    QSpinBox *ResistanceA;
    QFormLayout *PIDSettingsA;
    QLabel *label_5;
    QLabel *SetpointA;
    QLabel *label_6;
    QSpinBox *HeaterRangeA;
    QLabel *label_7;
    QLabel *HeaterOutputA;
    QLabel *label_8;
    QLabel *ProportionaA;
    QLabel *label_9;
    QLabel *IntegralA;
    QLabel *label_10;
    QLabel *DerivativeA;
    QFormLayout *formLayout_3;
    QFormLayout *HeaterB;
    QLabel *label_4;
    QSpinBox *ResistanceB;
    QFormLayout *PIDSettingsB;
    QLabel *label_15;
    QLabel *SetpointB;
    QLabel *label_11;
    QSpinBox *HeaterRangeB;
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
    QWidget *layoutWidget1;
    QFormLayout *formLayout_4;
    QPushButton *startPressureMeasurement;
    QPushButton *stopPressureMeasurement;
    deviceButton *resetDevice;
    QWidget *layoutWidget2;
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
    QWidget *layoutWidget3;
    QFormLayout *formLayout_9;
    QLabel *label_25;
    QSpinBox *pressureTimeInterval;
    QWidget *widget;
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
        tabWidget->setGeometry(QRect(0, 20, 771, 881));
        tabPID = new QWidget();
        tabPID->setObjectName(QString::fromUtf8("tabPID"));
        layoutWidget = new QWidget(tabPID);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 701, 211));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TempValue = new QFormLayout();
        TempValue->setObjectName(QString::fromUtf8("TempValue"));
        TempValue->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        TempValue->setWidget(0, QFormLayout::LabelRole, label);

        tempValueA = new QLabel(layoutWidget);
        tempValueA->setObjectName(QString::fromUtf8("tempValueA"));

        TempValue->setWidget(0, QFormLayout::FieldRole, tempValueA);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        TempValue->setWidget(1, QFormLayout::LabelRole, label_2);

        tempValueB = new QLabel(layoutWidget);
        tempValueB->setObjectName(QString::fromUtf8("tempValueB"));

        TempValue->setWidget(1, QFormLayout::FieldRole, tempValueB);


        gridLayout->addLayout(TempValue, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        StartPID = new QPushButton(layoutWidget);
        StartPID->setObjectName(QString::fromUtf8("StartPID"));

        formLayout->setWidget(0, QFormLayout::LabelRole, StartPID);

        SavePID = new QPushButton(layoutWidget);
        SavePID->setObjectName(QString::fromUtf8("SavePID"));

        formLayout->setWidget(1, QFormLayout::LabelRole, SavePID);

        StopPID = new QPushButton(layoutWidget);
        StopPID->setObjectName(QString::fromUtf8("StopPID"));

        formLayout->setWidget(0, QFormLayout::FieldRole, StopPID);


        gridLayout->addLayout(formLayout, 0, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        HeaterA = new QFormLayout();
        HeaterA->setObjectName(QString::fromUtf8("HeaterA"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        HeaterA->setWidget(0, QFormLayout::LabelRole, label_3);

        ResistanceA = new QSpinBox(layoutWidget);
        ResistanceA->setObjectName(QString::fromUtf8("ResistanceA"));

        HeaterA->setWidget(0, QFormLayout::FieldRole, ResistanceA);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, HeaterA);

        PIDSettingsA = new QFormLayout();
        PIDSettingsA->setObjectName(QString::fromUtf8("PIDSettingsA"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        PIDSettingsA->setWidget(0, QFormLayout::LabelRole, label_5);

        SetpointA = new QLabel(layoutWidget);
        SetpointA->setObjectName(QString::fromUtf8("SetpointA"));

        PIDSettingsA->setWidget(0, QFormLayout::FieldRole, SetpointA);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        PIDSettingsA->setWidget(1, QFormLayout::LabelRole, label_6);

        HeaterRangeA = new QSpinBox(layoutWidget);
        HeaterRangeA->setObjectName(QString::fromUtf8("HeaterRangeA"));

        PIDSettingsA->setWidget(1, QFormLayout::FieldRole, HeaterRangeA);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        PIDSettingsA->setWidget(2, QFormLayout::LabelRole, label_7);

        HeaterOutputA = new QLabel(layoutWidget);
        HeaterOutputA->setObjectName(QString::fromUtf8("HeaterOutputA"));

        PIDSettingsA->setWidget(2, QFormLayout::FieldRole, HeaterOutputA);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        PIDSettingsA->setWidget(3, QFormLayout::LabelRole, label_8);

        ProportionaA = new QLabel(layoutWidget);
        ProportionaA->setObjectName(QString::fromUtf8("ProportionaA"));

        PIDSettingsA->setWidget(3, QFormLayout::FieldRole, ProportionaA);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        PIDSettingsA->setWidget(4, QFormLayout::LabelRole, label_9);

        IntegralA = new QLabel(layoutWidget);
        IntegralA->setObjectName(QString::fromUtf8("IntegralA"));

        PIDSettingsA->setWidget(4, QFormLayout::FieldRole, IntegralA);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        PIDSettingsA->setWidget(5, QFormLayout::LabelRole, label_10);

        DerivativeA = new QLabel(layoutWidget);
        DerivativeA->setObjectName(QString::fromUtf8("DerivativeA"));

        PIDSettingsA->setWidget(5, QFormLayout::FieldRole, DerivativeA);


        formLayout_2->setLayout(1, QFormLayout::LabelRole, PIDSettingsA);


        gridLayout->addLayout(formLayout_2, 1, 0, 1, 1);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        HeaterB = new QFormLayout();
        HeaterB->setObjectName(QString::fromUtf8("HeaterB"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        HeaterB->setWidget(0, QFormLayout::LabelRole, label_4);

        ResistanceB = new QSpinBox(layoutWidget);
        ResistanceB->setObjectName(QString::fromUtf8("ResistanceB"));

        HeaterB->setWidget(0, QFormLayout::FieldRole, ResistanceB);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, HeaterB);

        PIDSettingsB = new QFormLayout();
        PIDSettingsB->setObjectName(QString::fromUtf8("PIDSettingsB"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        PIDSettingsB->setWidget(0, QFormLayout::LabelRole, label_15);

        SetpointB = new QLabel(layoutWidget);
        SetpointB->setObjectName(QString::fromUtf8("SetpointB"));

        PIDSettingsB->setWidget(0, QFormLayout::FieldRole, SetpointB);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        PIDSettingsB->setWidget(1, QFormLayout::LabelRole, label_11);

        HeaterRangeB = new QSpinBox(layoutWidget);
        HeaterRangeB->setObjectName(QString::fromUtf8("HeaterRangeB"));

        PIDSettingsB->setWidget(1, QFormLayout::FieldRole, HeaterRangeB);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        PIDSettingsB->setWidget(2, QFormLayout::LabelRole, label_16);

        HeaterOutputB = new QLabel(layoutWidget);
        HeaterOutputB->setObjectName(QString::fromUtf8("HeaterOutputB"));

        PIDSettingsB->setWidget(2, QFormLayout::FieldRole, HeaterOutputB);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        PIDSettingsB->setWidget(3, QFormLayout::LabelRole, label_12);

        ProportionalB = new QLabel(layoutWidget);
        ProportionalB->setObjectName(QString::fromUtf8("ProportionalB"));

        PIDSettingsB->setWidget(3, QFormLayout::FieldRole, ProportionalB);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        PIDSettingsB->setWidget(4, QFormLayout::LabelRole, label_14);

        IntegralB = new QLabel(layoutWidget);
        IntegralB->setObjectName(QString::fromUtf8("IntegralB"));

        PIDSettingsB->setWidget(4, QFormLayout::FieldRole, IntegralB);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        PIDSettingsB->setWidget(5, QFormLayout::LabelRole, label_13);

        DerivativeB = new QLabel(layoutWidget);
        DerivativeB->setObjectName(QString::fromUtf8("DerivativeB"));

        PIDSettingsB->setWidget(5, QFormLayout::FieldRole, DerivativeB);


        formLayout_3->setLayout(1, QFormLayout::LabelRole, PIDSettingsB);


        gridLayout->addLayout(formLayout_3, 1, 1, 1, 1);

        PIDPlot = new QwtPlot(tabPID);
        PIDPlot->setObjectName(QString::fromUtf8("PIDPlot"));
        PIDPlot->setGeometry(QRect(60, 230, 631, 351));
        tabWidget->addTab(tabPID, QString());
        tabBakeout = new QWidget();
        tabBakeout->setObjectName(QString::fromUtf8("tabBakeout"));
        layoutWidget1 = new QWidget(tabBakeout);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 10, 158, 54));
        formLayout_4 = new QFormLayout(layoutWidget1);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        startPressureMeasurement = new QPushButton(layoutWidget1);
        startPressureMeasurement->setObjectName(QString::fromUtf8("startPressureMeasurement"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, startPressureMeasurement);

        stopPressureMeasurement = new QPushButton(layoutWidget1);
        stopPressureMeasurement->setObjectName(QString::fromUtf8("stopPressureMeasurement"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, stopPressureMeasurement);

        resetDevice = new deviceButton(layoutWidget1);
        resetDevice->setObjectName(QString::fromUtf8("resetDevice"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, resetDevice);

        layoutWidget2 = new QWidget(tabBakeout);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(200, 0, 225, 65));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(layoutWidget2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_2->addWidget(label_22, 0, 0, 1, 1);

        pressureCombi1 = new QLabel(layoutWidget2);
        pressureCombi1->setObjectName(QString::fromUtf8("pressureCombi1"));

        gridLayout_2->addWidget(pressureCombi1, 0, 1, 1, 1);

        label_23 = new QLabel(layoutWidget2);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_2->addWidget(label_23, 1, 0, 1, 1);

        pressureCombi2 = new QLabel(layoutWidget2);
        pressureCombi2->setObjectName(QString::fromUtf8("pressureCombi2"));

        gridLayout_2->addWidget(pressureCombi2, 1, 1, 1, 1);

        label_24 = new QLabel(layoutWidget2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_2->addWidget(label_24, 2, 0, 1, 1);

        pressureIonGauge = new QLabel(layoutWidget2);
        pressureIonGauge->setObjectName(QString::fromUtf8("pressureIonGauge"));

        gridLayout_2->addWidget(pressureIonGauge, 2, 1, 1, 1);

        combi1CheckBox = new QCheckBox(layoutWidget2);
        combi1CheckBox->setObjectName(QString::fromUtf8("combi1CheckBox"));

        gridLayout_2->addWidget(combi1CheckBox, 0, 2, 1, 1);

        combi2CheckBox = new QCheckBox(layoutWidget2);
        combi2CheckBox->setObjectName(QString::fromUtf8("combi2CheckBox"));

        gridLayout_2->addWidget(combi2CheckBox, 1, 2, 1, 1);

        ionGaugeCheckBox = new QCheckBox(layoutWidget2);
        ionGaugeCheckBox->setObjectName(QString::fromUtf8("ionGaugeCheckBox"));

        gridLayout_2->addWidget(ionGaugeCheckBox, 2, 2, 1, 1);

        layoutWidget3 = new QWidget(tabBakeout);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(450, 10, 72, 22));
        formLayout_9 = new QFormLayout(layoutWidget3);
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        formLayout_9->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(layoutWidget3);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, label_25);

        pressureTimeInterval = new QSpinBox(layoutWidget3);
        pressureTimeInterval->setObjectName(QString::fromUtf8("pressureTimeInterval"));
        pressureTimeInterval->setMinimum(1);

        formLayout_9->setWidget(0, QFormLayout::FieldRole, pressureTimeInterval);

        widget = new QWidget(tabBakeout);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 80, 741, 761));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pressurePlot1 = new trackingPlot(widget);
        pressurePlot1->setObjectName(QString::fromUtf8("pressurePlot1"));
        pressurePlot1->setFrameShape(QFrame::StyledPanel);
        pressurePlot1->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(pressurePlot1);

        pressurePlot2 = new trackingPlot(widget);
        pressurePlot2->setObjectName(QString::fromUtf8("pressurePlot2"));
        pressurePlot2->setFrameShape(QFrame::StyledPanel);
        pressurePlot2->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(pressurePlot2);

        ionGaugePlot = new trackingPlot(widget);
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

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Temp. Channel A :", 0, QApplication::UnicodeUTF8));
        tempValueA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "Temp. Channel B :", 0, QApplication::UnicodeUTF8));
        tempValueB->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        StartPID->setText(QApplication::translate("Form", "Start", 0, QApplication::UnicodeUTF8));
        SavePID->setText(QApplication::translate("Form", "Save", 0, QApplication::UnicodeUTF8));
        StopPID->setText(QApplication::translate("Form", "Stop", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Form", "Heater Output 1", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Form", "Setpoint", 0, QApplication::UnicodeUTF8));
        SetpointA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Form", "Heater Range", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Form", "Heater Output", 0, QApplication::UnicodeUTF8));
        HeaterOutputA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Form", "Proportional", 0, QApplication::UnicodeUTF8));
        ProportionaA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Form", "Integral", 0, QApplication::UnicodeUTF8));
        IntegralA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Form", "Derivative", 0, QApplication::UnicodeUTF8));
        DerivativeA->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Form", "Heater Output 2", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Form", "Setpoint", 0, QApplication::UnicodeUTF8));
        SetpointB->setText(QApplication::translate("Form", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Form", "Heater Range", 0, QApplication::UnicodeUTF8));
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
