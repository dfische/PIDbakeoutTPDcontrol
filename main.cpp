#include <QDebug>
#include <QTest>
#include <QApplication>



int main(int argc, char** argv)
{
    QApplication app(argc, argv) ;
    Dialog.show();
    return app.exec();
}