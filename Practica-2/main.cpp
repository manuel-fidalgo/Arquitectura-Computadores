#include "mainwindow.h"
#include "coche.h"
#include "listavehiculos.h"
#include <QApplication>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
