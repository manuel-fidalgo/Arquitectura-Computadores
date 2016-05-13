#include "aritmethiclogicunit.h"
#define DEBUG 1

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
    uint oper_position;
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
    /*Creamos los bitset*/
    std::bitset<TEMP> oper_1 = toBinary(oper_1_decimal);
    std::bitset<TEMP> oper_2 = toBinary(oper_2_decimal);

    std::bitset<TEMP> res_binario;
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
    std::string s = toHex(oper_1);
    //Devolvemos los resultados en forma de punteros
    *this->normal = res_decimal;
    *this->ieee = toDecimal(res_binario);
}
std::bitset<TEMP> AritmethicLogicUnit::suma(std::bitset<TEMP> oper1, std::bitset<TEMP> oper2){
    return oper1;
}
std::bitset<TEMP> AritmethicLogicUnit::resta(std::bitset<TEMP> oper1, std::bitset<TEMP> oper2){
    return oper1;
}
std::bitset<TEMP> AritmethicLogicUnit::multiplicacion(std::bitset<TEMP> oper1, std::bitset<TEMP> oper2){
    return oper1;
}
std::bitset<TEMP> AritmethicLogicUnit::division(std::bitset<TEMP> oper1, std::bitset<TEMP> oper2){
    return oper1;
}

std::bitset<TEMP> AritmethicLogicUnit::toBinary (float num){
    union{
        int integer_val;
        float float_val;
    } current_union;
    current_union.float_val = num;
    std::bitset<TEMP>  bits(current_union.integer_val);
    if(DEBUG) std::cout << num <<"\t--->" << bits << std::endl;
    return bits;

}
float AritmethicLogicUnit::toDecimal(std::bitset<TEMP> num){
    return 0;
}
std::string AritmethicLogicUnit::toHex(std::bitset<TEMP> num){
    std::ostringstream res;
    res << std::hex << std::uppercase << num.to_ulong() << std::endl;
    if(DEBUG) std::cout << res.str();
    return res.str();
}
