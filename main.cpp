#include "mainwindow.h"
#include "globalvariable.h"

#include <QApplication>

Variables *Variables::instance = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
