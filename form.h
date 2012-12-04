#ifndef FORM_H
#define FORM_H
#include <QTimer>

#include <QWidget>

class combivac ;
class dialog335 ;
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

private slots:
    void bakeoutTimerIntervalChanged(int) ;
    void getBakeoutValue() ;
    void PIDtimerIntervalChanged(int) ;
    void getPIDValue() ;


    void on_heaterRange1_currentIndexChanged(int index);
};

#endif // FORM_H
