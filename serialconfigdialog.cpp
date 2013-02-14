#include "serialconfigdialog.h"
#include "ui_serialconfigdialog.h"

serialConfigDialog::serialConfigDialog(serial *dev, QWidget *parent)
    : QDialog(parent),
      device(dev),
      ui(new Ui::serialConfigDialog)
{
    ui->setupUi(this);
    connect(this, SIGNAL(accepted()), this, SLOT(setDevice())) ;
    if (device)
    {
        int i = ui->baudRate->findText(QString::number(device->baudRate())) ;
        if (i > -1)
            ui->baudRate->setCurrentIndex(i);
        else
        {
            ui->baudRate->addItem(QString::number(device->baudRate()));
            ui->baudRate->setCurrentIndex(ui->baudRate->count()-1);
        }
        ui->dataBits->setCurrentIndex(ui->dataBits->findText(QString::number(device->dataBits())));
        ui->stopBits->setCurrentIndex(device->stopBits());
        ui->parity->setCurrentIndex(device->parity()) ; // TODO check if correct
        ui->flowControl->setCurrentIndex(device->flowControl()) ;
        ui->minDelay->setValue(device->minimumDelay());
        setWindowTitle("Configuration of "+device->objectName());
    }
}

serialConfigDialog::~serialConfigDialog()
{
    delete ui;
}

serialSettings serialConfigDialog::settings() const
{
    return serialSettings((BaudRateType) ui->baudRate->currentText().toInt(),
                          (DataBitsType) ui->dataBits->currentText().toInt(),
                          (ParityType) ui->parity->currentIndex(),
                          (StopBitsType) ui->stopBits->currentIndex(),
                          (FlowType) ui->flowControl->currentIndex(),
                          -1) ;
}

QString serialConfigDialog::port() const
{
    return QString::number(ui->comPort->value()) ;
}

void serialConfigDialog::setDevice()
{
    if (!device) return ;
    device->setPortName(port());
    serialSettings s = settings() ;
    device->setBaudRate(s.BaudRate);
    device->setDataBits(s.DataBits);
    device->setParity(s.Parity);
    device->setStopBits(s.StopBits);
    device->setFlowControl(s.FlowControl);
    device->setTimeout(s.Timeout_Millisec);
    device->setMinimumDelay(ui->minDelay->value());
    device->close();
    device->open(serial::ReadWrite) ;
}
