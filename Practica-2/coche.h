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

    std::string nombresVehiculos[8]={
        "Homer's pink sedan",
        "Canyonero",
        "The Homer",
        "Lil Bandit",
        "Springfield police Car",
        "Bart's Bike",
        "Skinner's kia",
        "Homer's motorbike"};
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

    int getPotencia();
    int getRuedas();

    bool tienePortavasos();
    bool tieneBurbuja();
    bool tieneBocinas();

    void generarMatricula();
};

#endif // COCHE_H
