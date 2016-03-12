#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::print(){
    std::cout << "Se ha creado un coche"<<std::endl;
}
Ui::MainWindow * MainWindow::getUi(){
    return this->ui;
}

