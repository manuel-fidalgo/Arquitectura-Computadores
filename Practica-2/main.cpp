#include "mainwindow.h"
#include "coche.h"
#include "listavehiculos.h"
#include <QApplication>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    Coche * c = new Coche();
    for (int var = 0; var < 90; ++var) {
        c->generarMatricula();
    }
    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
