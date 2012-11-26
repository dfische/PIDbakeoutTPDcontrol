#ifndef DIALOGCOMBIVAC_H
#define DIALOGCOMBIVAC_H
#include <QWidget>
#include <QTimer>
#include <QProgressDialog>
#include <QFile>
#include <QVector>
#include <QTime>
#include <QObject>
class QwtPlot ;
class QwtPlotCurve ;
namespace Ui
{
class GUI ;
}


class dialogCombivac : public QWidget
{
    Q_OBJECT

public:
    dialogCombivac();

private slots:

    void on_startPressureMeasurement_clicked() ;
    void on_stopPressureMeasurement_clicked() ;
    void pressureCombi1(double) ;
    void pressureCombi2(double) ;
    void pressureIonGauge(double) ;


private:




};

#endif // DIALOGCOMBIVAC_H
