#include "aritmethiclogicunit.h"


AritmethicLogicUnit::AritmethicLogicUnit(){

}

AritmethicLogicUnit::AritmethicLogicUnit(float *ieee, float *normal, std::string opertation)
{
    this->normal = normal;
    this->ieee = ieee;
    this->oper = opertation;
}
int AritmethicLogicUnit::tokenizeString(float * n1, float * n2){
    //Descomponemos la cadena
    std::string oper[4] = {"+","-","*","/"};
    int oper_position;
    int var;
    for (var = 0; var < 4; ++var) {
        oper_position = this->oper.find(oper[var]);
        if(oper_position != std::string::npos){
            break;
        }
    }
    std::string first = this->oper.substr(0,oper_position);
    std::string second = this->oper.substr(oper_position+1,this->oper.length());
    QString f = QString::fromStdString(first);
    QString s = QString::fromStdString(second);
    *n1 = f.toFloat();
    *n2 = s.toFloat();
    return var;

}

void AritmethicLogicUnit::solve(){
    float oper_1_decimal = 0;
    float oper_2_decimal = 0;
    int  op = tokenizeString(&oper_1_decimal,&oper_2_decimal);

    float oper_1 = toBinaryIEEE(oper_1);
    float oper_2 = toBinaryIEEE(oper_1);

    float res_binario;
    float res_decimal;
    switch(op){
    case 0: res_binario = suma(oper_1, oper_2);
        res_decimal = oper_1_decimal+oper_2_decimal;
        break;
    case 1: res_binario = resta(oper_1, oper_2);
        res_decimal = oper_1_decimal-oper_2_decimal;
        break;
    case 2: res_binario = multiplicacion(oper_1, oper_2);
        res_decimal = oper_1_decimal*oper_2_decimal;
        break;
    case 3: res_binario = division(oper_1,oper_2);
        res_decimal = oper_1_decimal/oper_2_decimal;
        break;
    }

    //Devolvemos los resultados en forma de punteros
    *this->normal = res_decimal;
    *this->ieee = 0;
}
float AritmethicLogicUnit::suma(float oper1, float oper2){

}
float AritmethicLogicUnit::resta(float oper1, float oper2){

}
float AritmethicLogicUnit::multiplicacion(float oper1, float oper2){

}
float AritmethicLogicUnit::division(float oper1, float oper2){

}
float AritmethicLogicUnit::toBinaryIEEE(float number){

}
float AritmethicLogicUnit::toBinary (float num){
    if (num < 2){
        return num;
    }
    else {
        return num%2 + ( 10 * toBinary(num/2));
    }
}
