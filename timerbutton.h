#ifndef TIMERBUTTON_H
#define TIMERBUTTON_H

#include <QPushButton>
#include <QTimer>

class timerButton : public QPushButton
{
    Q_OBJECT
public:
    explicit timerButton(QWidget *parent = 0);
private:
    QTimer *timer ;
signals:
    void timeout() ;
public slots:
    void setTimerInterval(int) ;
private slots:
    void toggleTimer(bool) ;
};



#endif // TIMERBUTTON_H
