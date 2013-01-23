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
#include <speczoomer.h>

trackingPlot::trackingPlot(QWidget *parent) :
    QwtPlot(parent),
    curve(0),
    contextMenu(0)
{
    xValue.start() ;
    curve = new QwtPlotCurve ;
    curve->attach(this) ;
    specZoomer* zoomer = new specZoomer(canvas()) ;
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
    specZoomer* zoomer = getZoomer() ;
    uint oldZoomIndex = (zoomer ? zoomer->zoomRectIndex() : 0) ;
    curve->setSamples(data) ;
    QRectF rectangle = curve->boundingRect() ;
    rectangle.translate(-rectangle.width()*.05, -rectangle.height()*.05);
    rectangle.setSize(1.1*rectangle.size()) ;
    if (zoomer) zoomer->setZoomBase(rectangle);
    if (zoomer && !oldZoomIndex) zoomer->zoom(0);
    QwtPlot::replot() ;
}

specZoomer* trackingPlot::getZoomer()
{
    return canvas()->findChild<specZoomer*>() ;
}

void trackingPlot::resetPlot()
{
    data.clear() ;
    xValue.restart() ;
    if (specZoomer *zoomer = getZoomer())
        zoomer->setZoomBase(QRectF());
    refresh() ;
}



void trackingPlot::addValue(double yValue)
{
    data += QPointF(xValue.elapsed()/1000., yValue) ;
    refresh() ;
}



