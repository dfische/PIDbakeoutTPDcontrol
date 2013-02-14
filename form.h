#ifndef FORM_H
#define FORM_H
#include <QTimer>
#include <QWidget>
#include <QMap>

class combivac ;
class dialog335 ;
class dialogRGA ;
class serialRequest ;
class QCheckBox ;
class trackingPlot ;
class generalPlot ;
class xyPlot ;
class QLabel ;
class serial ;
class heaterOutputRequest ;
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    
public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    
private:
    Ui::Form *ui;
    combivac *cv ;
    QTimer * bakeoutTimer ;
    QTimer *PIDtimer ;
    heaterOutputRequest *heaterOutputRequest1 ;
    heaterOutputRequest *heaterOutputRequest2;
    dialog335 *dl ;
    dialogRGA *rg ;
    QMap<QCheckBox*, serialRequest*> requestMap ;
    serialRequest* initializeRequest(serialRequest*, QLabel *label, trackingPlot *plot, QCheckBox *checkBox) ;
    serialRequest* initializeDoubleRequest(serialRequest*, serialRequest*, QLabel *, QLabel *, xyPlot *plot, QCheckBox *checkBox) ;

private slots:
    void bakeoutTimerIntervalChanged(int) ;
    void getBakeoutValue() ;
    // void getTemperatureValue() ;
    //void PIDtimerIntervalChanged(int) ;
    void heaterOutput(bool) ;
    void on_heaterRange1_currentIndexChanged(int index);
    void on_setpoint1_valueChanged(double arg1);
    void on_setpoint2_valueChanged(double arg1);
    void on_heaterRange2_currentIndexChanged(int index);
    void pidValueChanged1() ;
    void pidValueChanged2() ;
    //void getMassValue() ;
    void checkBoxToggled(bool) ;
};

#endif // FORM_H
