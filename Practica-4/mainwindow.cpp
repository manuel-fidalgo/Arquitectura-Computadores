#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aritmethiclogicunit.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->screen->setTextColor(QColor(200,0,0,255));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
    this->strstm << '1';
    printOnScreen();
}
void MainWindow::on_pushButton_2_clicked()
{
    this->strstm << '2';
    printOnScreen();
}
void MainWindow::on_pushButton_3_clicked()
{
    this->strstm << '3';
    printOnScreen();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->strstm << '4';
    printOnScreen();
}

void MainWindow::on_pushButton_5_clicked()
{
    this->strstm << '5';
    printOnScreen();
}

void MainWindow::on_pushButton_6_clicked()
{
    this->strstm << '6';
    printOnScreen();
}

void MainWindow::on_pushButton_7_clicked()
{
    this->strstm << '7';
    printOnScreen();
}

void MainWindow::on_pushButton_8_clicked()
{
    this->strstm << '8';
    printOnScreen();
}

void MainWindow::on_pushButton_9_clicked()
{
    this->strstm << '9';
    printOnScreen();

}

void MainWindow::on_pushButton_0_clicked()
{
    this->strstm << '0';
    printOnScreen();
}

//OPERATORS

void MainWindow::on_pushButton_coma_clicked()
{
    this->strstm << '.';
    printOnScreen();
}

void MainWindow::on_pushButton_mas_clicked()
{
    this->strstm << '+';
    printOnScreen();
    statusOperationButtons(false);
}

void MainWindow::on_pushButton_menos_clicked()
{
    this->strstm << '-';
    printOnScreen();
    statusOperationButtons(false);
}

void MainWindow::on_pushButton_por_clicked()
{
    this->strstm << '*';
    printOnScreen();
    statusOperationButtons(false);
}

void MainWindow::on_pushButton_entre_clicked()
{
    this->strstm << '/';
    printOnScreen();
    statusOperationButtons(false);
}
void MainWindow::on_pushButton_dot_clicked()
{
    this->strstm << '.';
    printOnScreen();
}

void MainWindow::on_pushButton_igual_clicked()
{
    statusOperationButtons(true);

    std::string operation = this->strstm.str();
    float result_IEEE = 0;
    float result_NORMAL = 0;
    AritmethicLogicUnit * c = new  AritmethicLogicUnit(&result_IEEE,&result_NORMAL,operation);
    AritmethicLogicUnit::outPutData os= c->solve();
    std::stringstream st;
    st <<"\t------Resultados------\n"<< "\n  (" <<operation <<") = "<<"\n\n\tIEEE-> "<<result_IEEE<<"  Normal-> "<<result_NORMAL
       <<"\n\tBinario-> " <<os.IEEE_bits <<"\n\t"<<"Hexadecimal-> 0x" <<os.IEEE_hex<<std::endl;
    ui->screen->setText(QString::fromStdString(st.str()));
    delete c; //Delete the unity aritmethiclogic
    this->strstm.str("");
}

void MainWindow::printOnScreen(){
    ui->screen->setText(QString::fromStdString(this->strstm.str()));
}

void MainWindow::statusOperationButtons(bool status){
    ui->pushButton_entre->setEnabled(status);
    ui->pushButton_mas->setEnabled(status);
    ui->pushButton_menos->setEnabled(status);
    ui->pushButton_por->setEnabled(status);
}

