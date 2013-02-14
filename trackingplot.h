#ifndef TRACKINGPLOT_H
#define TRACKINGPLOT_H
#include <qwt_plot.h>
#include <QPointF>
#include <QVector>
#include <QTime>
#include "generalplot.h"

class QMenu ;
class QwtPlotCurve ;
class specZoomer ;

class trackingPlot : public generalPlot
{
    Q_OBJECT
public:
    explicit trackingPlot(QWidget *parent = 0);

private:
    QVector<QPointF> data ;
    QTime xValue ;
    void resetEvent() ;


signals:

private slots:

public slots:
    void addyValue(double yValue) ;

};

#endif // TRACKINGPLOT_H
