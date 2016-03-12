#ifndef LISTAVEHICULOS_H
#define LISTAVEHICULOS_H

#include <coche.h>
#include <vector>

class ListaVehiculos
{
private:
    std::vector<Coche> cochesCreados;
public:
    ListaVehiculos();
    void agnadirCoche(Coche c);
};

#endif // LISTAVEHICULOS_H
