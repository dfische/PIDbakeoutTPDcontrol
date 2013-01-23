#ifndef TRACKINGPLOT_H
#define TRACKINGPLOT_H
#include <qwt_plot.h>
#include <QPointF>
#include <QVector>
#include <QTime>

class QMenu ;
class QwtPlotCurve ;
class specZoomer ;

class trackingPlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit trackingPlot(QWidget *parent = 0);
private:
    QVector<QPointF> data ;
    QTime xValue ;
    QwtPlotCurve *curve ;
    void contextMenuEvent(QContextMenuEvent *) ;
    QMenu *contextMenu ;
    void refresh() ;
    specZoomer *getZoomer() ;
signals:
private slots:
    void resetPlot() ;
    void savePlot() ;

public slots:
    void addValue(double yValue) ;
};

#endif // TRACKINGPLOT_H
