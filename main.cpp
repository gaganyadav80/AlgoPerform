#include "mainwindow.h"
#include "globalvariable.h"

#include "stdlib.h"
#include "time.h"

#include <QApplication>

#define MAX 500

Variables *Variables::instance = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void Ui::genRand(int *list, int count)
{
    int numRand = 0;

    //seed the random number generator
    srand(time(0));

    while (numRand < count) {
        list[numRand] = rand()%MAX;
        numRand++;
    }

}
