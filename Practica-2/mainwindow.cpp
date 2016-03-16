#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coche.h"
#include "listavehiculos.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*Colores*/
    ui->colorComboBox->addItem("Rojo",QVariant("Rojo"));
    ui->colorComboBox->addItem("Verde",QVariant("Verde"));
    ui->colorComboBox->addItem("Azul",QVariant("Azul"));
    ui->colorComboBox->addItem("Amarillo",QVariant("Amarillo"));
    /*Numero de ruedas*/
    ui->numRuedasComboBox->addItem("2",QVariant(2));
    ui->numRuedasComboBox->addItem("3",QVariant(3));
    ui->numRuedasComboBox->addItem("4",QVariant(4));
    /*Combustible*/
    ui->cmbustibleComboBox->addItem("Gasolina",QVariant("Gasolina"));
    ui->cmbustibleComboBox->addItem("Diesel",QVariant("Diesel"));
    ui->cmbustibleComboBox->addItem("Pedales",QVariant("Pedales"));
    getUi()->matriculaTextField->setReadOnly(true);
    getUi()->listaCoches->setReadOnly(true);

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
void MainWindow::setMatricula(){
    getUi()->matriculaTextField->setText(QString::fromStdString(darMatricula()));
}
void MainWindow::agnadirCoche(){
    std::string matricula = getUi()->matriculaTextField->text().toStdString();
    if(matricula.length()!=7){
        QMessageBox message;
        message.setText("Matricula vacia.");
        message.setStandardButtons(QMessageBox::Ok);
        int res = message.exec();
        return;
    }else if(exist(matricula)){
        QMessageBox message;
        message.setText("Matricula repetida.");
        message.setStandardButtons(QMessageBox::Ok);
        int res = message.exec();
        return;
    }

    std::string color = getUi()->colorComboBox->itemData(getUi()->colorComboBox->currentIndex()).toString().toStdString();
    std::string nombre =getUi()->lineEdit->text().toStdString();
    std::string combustible =getUi()->cmbustibleComboBox->itemData(getUi()->cmbustibleComboBox->currentIndex()).toString().toStdString();
    int potencia = atoi(getUi()->potenciaMotorTextField->text().toStdString().c_str());
    int numruedas = getUi()->numRuedasComboBox->itemData(getUi()->numRuedasComboBox->currentIndex()).toInt();
    bool p = getUi()->portaVasosCheckBox->isChecked();
    bool b =  getUi()->bocinasCheckBox->isChecked();
    bool bu = getUi()->burbujaCheckBox->isChecked();
    //std::cout << color << nombre << combustible << potencia << numruedas << p << b << bu << std::endl;
    Coche c = * new Coche(color,nombre,combustible,potencia,numruedas,p,b,bu);
    c.asignarMatricula(matricula);
    std::cout << c.darCadena()<< std::endl;
    getUi()->listaCoches->appendPlainText(QString::fromStdString(c.darCadena()));
    lista.agnadirCoche(c);
}


/*****************************/


/*Slots(Es decir, eventos)*/
void MainWindow::on_genMatriculaButton_clicked()
{
    setMatricula();
}

void MainWindow::on_finalButton_clicked()
{
    agnadirCoche();
}
std::string MainWindow::darMatricula(){
    std::stringstream os;
    int cout=0;
    int random;
    for (int var = 0; var < 4; ++var) {
        os << rand()%10;
    }
    while(cout<3){
        random = (rand()%25)+65;
        //Excluimos las letas AEIOUQ que son las que no estan incluidas en las matriculas europeas
        //(random=!65) && (random=!69) && (random=!73) && (random=!79) && (random=!81) && (random=!85)
        if(random!=65 && random!=69 && random!=73 && random!=79 && random!=81 && random!=85){
            os << (char)random;
            cout++;
        }
    }
    return os.str();
}
bool MainWindow::exist(std::string m){
    int res;
    std::string s1;
    std::vector<Coche> lista = this->lista.getVector();
    for (int var = 0; var < lista.size(); ++var) {
        s1 = lista[var].getMatricula();
         res = strcmp(s1.c_str(),m.c_str());
        if(res==0) return true;
    }
    return false;
}
