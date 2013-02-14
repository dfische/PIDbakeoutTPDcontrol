#ifndef GENERALPLOT_H
#define GENERALPLOT_H
#include <qwt_plot.h>
#include <QPointF>
#include <QVector>
#include <QTime>

class QMenu ;
class QwtPlotCurve ;
class specZoomer ;

class generalPlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit generalPlot(QWidget *parent = 0);
    
signals:
protected:
    void addValue(double x, double y) ;
private:
    QVector<QPointF> data ;
    void contextMenuEvent(QContextMenuEvent *) ;
    QMenu *contextMenu ;
    void refresh() ;
    specZoomer *getZoomer() ;
    QString generateTextData() const ;
public slots:
    void resetPlot() ;
    void savePlot() ;
    void copyData() ;
protected:
    virtual void resetEvent() {}
    QwtPlotCurve *curve ;
};

#endif // GENERALPLOT_H
