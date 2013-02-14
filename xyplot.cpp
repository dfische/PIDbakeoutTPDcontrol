#include "xyplot.h"
#include "generalplot.h"
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <QBrush>
#include <QPen>

xyPlot::xyPlot(QWidget *parent) :
    generalPlot(parent),
    Value(0),
    status(noincome)
{
    curve->setStyle(QwtPlotCurve::NoCurve) ;
    curve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, QBrush(Qt::black), QPen(Qt::black), QSize(4,4))) ;
}
void xyPlot::addxValue(double xin)
{
    switch(status)
    {
    case noincome:
    case xPrevious:
        Value = xin ;
        status = xPrevious ;
        return ;
    case yPrevious:
        addValue(xin, Value) ;
        status = noincome ;
        return ;
    }
}

void xyPlot::addyValue(double yin)
{
    switch(status)
    {
    case noincome:
    case yPrevious:
        Value = yin ;
        status = yPrevious ;
        return ;
    case xPrevious:
        addValue(Value, yin) ;
        status = noincome ;
        return ;
    }
}
