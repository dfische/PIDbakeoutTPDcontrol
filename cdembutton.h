#ifndef CDEMBUTTON_H
#define CDEMBUTTON_H

#include <QPushButton>
#include <QTimer>

class dialogRGA ;

class CDEMButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CDEMButton(QWidget *parent);
    void setRGA(dialogRGA *) ;
private:
    dialogRGA *rg ;
signals:
    void CDEMTimeout() ;
public slots:
    void CDEMToggleTimer(bool) ;
private slots:
    void textChange(bool) ;
    
};

#endif // CDEMBUTTON_H
