#ifndef ARITMETHICLOGICUNIT_H
#define ARITMETHICLOGICUNIT_H

#define TEMP sizeof(float) * CHAR_BIT
#define NUM_BITS 32
#define EXP_DESP 127
#define DEBUG 1
#define DESPLAZAMIENTO_EXPONENENTE 23

#include <string>
#include <sstream>
#include <iostream>
#include <QString>
#include <bitset>
#include <math.h>


class AritmethicLogicUnit
{
public:
    struct outPutData{
        std::bitset<TEMP> IEEE_bits;
        std::string IEEE_hex;
    };

    AritmethicLogicUnit();
    AritmethicLogicUnit(float* normal, float * ieee, std::string opertation);
    outPutData solve();
    int tokenizeString(float *n1, float *n2);
private:
    float * normal;
    float * ieee;
    std::string oper;
    //OPERATIONS
    std::bitset<TEMP> suma(std::bitset<TEMP> oper1,std::bitset<TEMP> oper2);
    std::bitset<TEMP> multiplicacion(std::bitset<TEMP> oper1, std::bitset<TEMP> oper2);
    std::bitset<TEMP> division(std::bitset<TEMP> oper1,std::bitset<TEMP> oper2);

    //INTERNAL OPERATIONS
    int getExp(std::bitset<TEMP> binaryNumber);
    void sumaExponentes(std::bitset<TEMP> * res,std::bitset<TEMP> oper1,std::bitset<TEMP> oper2);
    void setExponent(int exp, std::bitset<TEMP> binary);
    int sumarMantisas(std::bitset<TEMP> res,std::bitset<TEMP> oper1,std::bitset<TEMP> oper2 );
    void multiplicarMantisas(std::bitset<TEMP> * res,std::bitset<TEMP> oper1,std::bitset<TEMP> oper2);
    void desplazarMantisa(std::bitset<TEMP> oper,float op1_exp, float op2_exp);
    bool XOR(bool a, bool b);
    //CASTS
    std::bitset<TEMP> toBinary (float num);
    float toDecimal(std::bitset<TEMP> num);
    std::string toHex(std::bitset<TEMP> num);

};

#endif // ARITMETHICLOGICUNIT_H
