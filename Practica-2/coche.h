#ifndef COCHE_H
#define COCHE_H

#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

class Coche
{
private:

    std::string nombresVehiculos[9]={
        "Homer's pink sedan",    //0 /
        "Canyonero",             //1 /
        "The Homer",             //2 /
        "Lil Bandit",            //3 /
        "Springfield police Car",//4 /
        "Lisa's Bike",           //5 /
        "Skinner's kia",         //6
        "Homer's motorbike",     //7 /
        "Bart's rocket"};        //8 /
    std::string color;
    std::string nombre;
    std::string combustible;
    std::string matricula;

    int potenciaMotor;
    int numRuedas;

    bool portavasos;
    bool burbuja;
    bool variasBocinas;


public:

    Coche();
    ~Coche();
    Coche(std::string color, std::string nombre,std::string combustible,int potencia, int numRuedas,bool portavasos, bool variasBocinas,bool burbuja);

    std::string getColor();
    std::string getNombre();
    std::string getCombustible();
    std::string getMatricula();
    std::string darTipoCoche();
    std::string darCadena();

    int getPotencia();
    int getRuedas();

    bool tienePortavasos();
    bool tieneBurbuja();
    bool tieneBocinas();

    void asignarMatricula(std::string s);
};

#endif // COCHE_H
