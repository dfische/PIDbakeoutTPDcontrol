#include "generalplot.h"
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
#include <QApplication>
#include <QClipboard>

generalPlot::generalPlot(QWidget *parent) :
    QwtPlot(parent),
    curve(0),
    contextMenu(0)
{
    curve = new QwtPlotCurve ;
    curve->attach(this) ;
    specZoomer* zoomer = new specZoomer(canvas()) ;
    zoomer->setZoomBase(canvas()->rect());
    contextMenu = new QMenu(this) ;
    QAction *resetAction = new QAction("Reset", this) ;
    QAction *saveAction = new QAction("Save", this) ;
    QAction *copyAction = new QAction("Copy", this) ;
    connect(resetAction, SIGNAL(triggered()), this, SLOT(resetPlot())) ;
    connect(saveAction, SIGNAL(triggered()), this, SLOT(savePlot())) ;
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copyData())) ;
    contextMenu->addAction(resetAction) ;
    contextMenu->addAction(saveAction) ;
    contextMenu->addAction(copyAction) ;
}

void generalPlot::addValue(double x, double y)
{
    data += QPointF(x,y) ;
    refresh() ;
}

QString generalPlot::generateTextData() const
{
    QString a ;
    QTextStream out(& a) ;
    foreach (QPointF xy, data)
        out << xy.x() << "\t" << xy.y() << endl ;
    return a ;
}

void generalPlot::copyData()
{
    QClipboard *cb = QApplication::clipboard() ;
    cb->setText(generateTextData()) ;
}

void generalPlot::contextMenuEvent(QContextMenuEvent *e)
{
    contextMenu->exec(e->globalPos()) ;
    e->accept() ;
}

void generalPlot::savePlot()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Plot") ;
    QFile file(fileName) ;
    if (!file.open(QFile::Append))
    {
        QMessageBox::warning(this, "Error", "Save Error") ;
        return ;
    }
    QTextStream out(&file) ;
    out << generateTextData() ;
    file.close() ;
}

void generalPlot::refresh()
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

specZoomer* generalPlot::getZoomer()
{
    return canvas()->findChild<specZoomer*>() ;
}

void generalPlot::resetPlot()
{
    data.clear() ;
    resetEvent() ;
    if (specZoomer *zoomer = getZoomer())
        zoomer->setZoomBase(QRectF());
    refresh() ;
}
