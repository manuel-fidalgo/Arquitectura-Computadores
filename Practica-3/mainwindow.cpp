#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <iostream>
#include <ostream>
#include <sstream>
#include <QImage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    matrix_test = * new Matrix_test();
    image_test = * new Image_test();
    ui->setupUi(this);
    ui->Selection_1->addItem("1M",QVariant());//100
    ui->Selection_1->addItem("27M",QVariant());//300
    ui->Selection_1->addItem("343M",QVariant());//700
    ui->Selection_1->addItem("1000M",QVariant());//100
    QPalette p = this->palette();
    p.setColor(backgroundRole(), QColor(255,255,255));
    this->setPalette(p);
}

MainWindow::~MainWindow(){
    delete ui;
}
Ui::MainWindow * MainWindow::getUi(){
    return this->ui;
}

void MainWindow::on_Ok_1_clicked(){
    int DIMENSIONS;
    double resultado;
    std::ostringstream os;
    int opcion = ui->Selection_1->currentIndex();

    if(opcion==0){
        DIMENSIONS=100;
    }else if(opcion==1){
        DIMENSIONS=300;
    }else if(opcion==2){
        DIMENSIONS = 700;
    }else{
        DIMENSIONS = 1000;
    }

    resultado = this->matrix_test.init(DIMENSIONS);
    os << "Test " << this->matrix_test.getNTest() << " tiempo: "
       << resultado << "s" << std::endl;
    ui->Log_1->appendPlainText(QString::fromStdString(os.str()));
}

void MainWindow::on_Ok_2_clicked()
{
    double resultado;
    std::ostringstream os;
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
    QImage img = QImage(fileName);
    ui->path->setText(fileName);
    ui->path->setToolTip(ui->path->text());
    resultado = this->image_test.init(img);
    os << "Test " << this->image_test.getNTest() << " tiempo: "
       << resultado << "s" << std::endl;
    ui->Log_2->appendPlainText(QString::fromStdString(os.str()));
}
