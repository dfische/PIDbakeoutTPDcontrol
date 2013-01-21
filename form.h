#ifndef FORM_H
#define FORM_H
#include <QTimer>

#include <QWidget>

class combivac ;
class dialog335 ;
class dialogRGA ;
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

    dialog335 *dl ;
    dialogRGA *rg ;

private slots:
    void bakeoutTimerIntervalChanged(int) ;
    void getBakeoutValue() ;   // void getTemperatureValue() ;
    void PIDtimerIntervalChanged(int) ;
    void getPIDValue() ;
    void on_heaterRange1_currentIndexChanged(int index);
    void on_setpoint1_valueChanged(double arg1);
    void on_setpoint2_valueChanged(double arg1);
    void on_heaterRange2_currentIndexChanged(int index);
    void pidValueChanged1() ;
    void pidValueChanged2() ;
    void getMassValue() ;
};

#endif // FORM_H
