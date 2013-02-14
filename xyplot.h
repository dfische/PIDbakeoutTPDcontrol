#ifndef XYPLOT_H
#define XYPLOT_H
#include "generalplot.h"


class xyPlot : public generalPlot
{
    Q_OBJECT
public:
    explicit xyPlot(QWidget *parent = 0);
private:
    double Value ;
    enum {xPrevious, yPrevious, noincome} status ;
signals:
    
public slots:
    void addxValue(double Value) ;
    void addyValue(double y) ;
    
};

#endif // XYPLOT_H
