#include "coche.h"

Coche::Coche(){}
Coche::~Coche(){}

/*Constructor que creara un coche a partir de los datos de la ventana*/
Coche::Coche(std::string color, std::string nombre,
             std::string combustible,
             int potencia, int numRuedas,
             bool portavasos, bool variasBocinas,
             bool burbuja){

    this->burbuja = burbuja;
    this->variasBocinas = variasBocinas;
    this->portavasos = portavasos;
    this->numRuedas = numRuedas;
    this->potenciaMotor = potencia;
    this->combustible = combustible;
    this->nombre = nombre;
    this->color = color;
}

std::string Coche::getColor(){
    return this->color;
}
std::string Coche::getNombre(){
    return this->nombre;
}
std::string Coche::getCombustible(){
    return this->combustible;
}
std::string Coche::getMatricula(){
    return this->matricula;
}
int Coche::getPotencia(){
    return this->potenciaMotor;
}
int Coche::getRuedas(){
    return this->numRuedas;
}
bool Coche::tienePortavasos(){
    return this->portavasos;
}
bool Coche::tieneBurbuja(){
    return this->burbuja;
}
bool Coche::tieneBocinas(){
    return this->variasBocinas;
}
void Coche::generarMatricula(){
    std::stringstream os;
    int cout=0;
    int random;
    for (int var = 0; var < 4; ++var) {
        os << rand()%10;
    }
    while(cout<3){
        random = (rand()%25)+65;
        //Excluimos las letas AEIOUQ que son las que no estan incluidas en las matriculas europeas
        if((random=!65) && (random=!69) && (random=!73) && (random=!79) && (random=!81) && (random=!85)){
            os << (char)random;
            cout++;
        }
    }
    std::cout << os.str()<< std::endl;
    this->matricula = os.str();
}
