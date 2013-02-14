#include "trackingplot.h"
#include <QTime>
#include <qwt_plot_curve.h>
#include "generalplot.h"


trackingPlot::trackingPlot(QWidget *parent) :
    generalPlot(parent)
{
    xValue.start() ;    
}

void trackingPlot::addyValue(double yValue)
{
    addValue(xValue.elapsed()/1000, yValue) ;
}

void trackingPlot::resetEvent()
{
    xValue.restart() ;
}





