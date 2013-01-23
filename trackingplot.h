#ifndef TRACKINGPLOT_H
#define TRACKINGPLOT_H
#include <qwt_plot.h>
#include <QPointF>
#include <QVector>
#include <QTime>
#include <speczoomer.h>


class QMenu ;
class QwtPlotCurve ;

class trackingPlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit trackingPlot(QWidget *parent = 0);
    ~trackingPlot() ;
private:
    QVector<QPointF> data ;
    QTime xValue ;
    QwtPlotCurve *curve ;
    specZoomer *zoomer ;
    void contextMenuEvent(QContextMenuEvent *) ;
    QMenu *contextMenu ;
    void refresh() ;
signals:
private slots:
    void resetPlot() ;
    void savePlot() ;

public slots:
    void addValue(double yValue) ;
    void addmassValue(double , double) ;
};

#endif // TRACKINGPLOT_H
