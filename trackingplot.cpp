#include "trackingplot.h"
#include <QTime>
#include <qwt_plot_curve.h>
#include <QMenu>
#include <QContextMenuEvent>
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

trackingPlot::trackingPlot(QWidget *parent) :
    QwtPlot(parent),
    curve(0),
    zoomer(0),
    contextMenu(0)
{
    xValue.start() ;
    curve = new QwtPlotCurve ;
    curve->attach(this) ;
    zoomer = new specZoomer(canvas()) ;
    zoomer->setZoomBase(canvas()->rect());
    contextMenu = new QMenu(this) ;
    QAction *resetAction = new QAction("Reset", this) ;
    QAction *saveAction = new QAction("Save", this) ;
    connect(resetAction, SIGNAL(triggered()), this, SLOT(resetPlot())) ;
    connect(saveAction, SIGNAL(triggered()), this, SLOT(savePlot())) ;
    contextMenu->addAction(resetAction) ;
    contextMenu->addAction(saveAction) ;

}

void trackingPlot::contextMenuEvent(QContextMenuEvent *e)
{
    contextMenu->exec(e->globalPos()) ;
    e->accept() ;
}

void trackingPlot::savePlot()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Plot") ;
    QFile file(fileName) ;
    if (!file.open(QFile::Append))
    {
        QMessageBox::warning(this, "Error", "Save Error") ;
        return ;
    }
    QTextStream out(&file) ;
    foreach (QPointF xy, data)
        out << xy.x() << "\t" << xy.y() << endl ;
    file.close() ;
}

void trackingPlot::refresh()
{
    uint oldZoomIndex = zoomer->zoomRectIndex() ;
    curve->setSamples(data) ;
    QRectF rectangle = curve->boundingRect() ;
    rectangle.translate(-rectangle.width()*.05, -rectangle.height()*.05);
    rectangle.setSize(1.1*rectangle.size()) ;
    zoomer->setZoomBase(rectangle);
    if (!oldZoomIndex) zoomer->zoom(0);
    QwtPlot::replot() ;
}

void trackingPlot::resetPlot()
{
    data.clear() ;
    xValue.restart() ;
    zoomer->setZoomBase(QRectF());
    refresh() ;
}



void trackingPlot::addValue(double yValue)
{
    data += QPointF(xValue.elapsed()/1000., yValue) ;
    refresh() ;
}

//void trackingPlot::addmassValue(double massValue, double tempValue)
//{
//    data += QPointF(massValue, tempValue) ;
//    refresh ;

//}


 trackingPlot::~trackingPlot()
 {
     delete zoomer ;
 }



