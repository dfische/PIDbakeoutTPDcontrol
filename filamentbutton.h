#ifndef FILAMENTBUTTON_H
#define FILAMENTBUTTON_H

#include <QPushButton>
#include <QTimer>

class dialogRGA ;


class filamentButton : public QPushButton
{
    Q_OBJECT
public:
    explicit filamentButton(QWidget *parent);
    void setRGA(dialogRGA *) ;
private:
    dialogRGA *rg ;
signals:
    void filamentTimeout() ;
    
public slots:
    void FilamentToggleTimer(bool) ;
private slots:
    void textChange(bool) ;
};

#endif // FILAMENTBUTTON_H
