#ifndef FORM_H
#define FORM_H
#include <QTimer>

#include <QWidget>

class combivac ;

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
    QTimer * timer ;

private slots:
    void timerIntervalChanged(int) ;
    void getValue() ;

};

#endif // FORM_H
