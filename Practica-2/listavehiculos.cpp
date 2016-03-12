#include "listavehiculos.h"

ListaVehiculos::ListaVehiculos(){}
void ListaVehiculos::agnadirCoche(Coche c){
    this->cochesCreados.push_back(c);
}
