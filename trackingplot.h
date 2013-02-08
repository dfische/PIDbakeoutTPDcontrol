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
    QString generateTextData() const ;
signals:
private slots:
    void resetPlot() ;
    void savePlot() ;
    void copyData() ;

public slots:
    void addValue(double yValue) ;
   // void addmassValue(double , double) ;
};

#endif // TRACKINGPLOT_H
