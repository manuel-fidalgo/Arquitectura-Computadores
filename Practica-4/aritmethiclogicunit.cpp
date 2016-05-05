#include "aritmethiclogicunit.h"

AritmethicLogicUnit::AritmethicLogicUnit(){

}

AritmethicLogicUnit::AritmethicLogicUnit(int *ieee, int *normal, std::string opertation)
{
    this->normal = normal;
    this->ieee = ieee;
    this->oper = opertation;
}
void AritmethicLogicUnit::tokenizeString(int * n1, int * n2){

}

void AritmethicLogicUnit::solve(){
    float oper_1 = 0;
    float oper_2 = 0;
    tokenizeString(&oper_1,&oper_2);

    //Devolvemos los resultados en forma de punteros
    *this->normal = 87;
    *this->ieee = 0;
}
