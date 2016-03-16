#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "coche.h"
#include "listavehiculos.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    void print();
    Ui::MainWindow * getUi();
    ~MainWindow();
    void setMatricula();
    void agnadirCoche();
    std::string darMatricula();
private slots:
    void on_genMatriculaButton_clicked();
    void on_finalButton_clicked();

private:
    Ui::MainWindow *ui;
    ListaVehiculos lista;
    Coche c;
};

#endif // MAINWINDOW_H
