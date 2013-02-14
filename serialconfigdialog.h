#ifndef SERIALCONFIGDIALOG_H
#define SERIALCONFIGDIALOG_H

#include <QDialog>
#include "serial.h"

namespace Ui {
class serialConfigDialog;
}

class serialConfigDialog : public QDialog
{
    Q_OBJECT
private:
    serial* device ;
    Ui::serialConfigDialog *ui ;
private slots:
    void setDevice() ;
public:
    explicit serialConfigDialog(serial* device = 0, QWidget *parent = 0);
    serialSettings settings() const ;
    QString port() const ;
    ~serialConfigDialog();
};

#endif // SERIALCONFIGDIALOG_H
