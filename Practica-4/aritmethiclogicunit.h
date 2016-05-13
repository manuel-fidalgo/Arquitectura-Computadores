#ifndef ARITMETHICLOGICUNIT_H
#define ARITMETHICLOGICUNIT_H

#define TEMP sizeof(float) * CHAR_BIT
#define NUM_BITS 32

#include <string>
#include <sstream>
#include <iostream>
#include <QString>
#include <bitset>



class AritmethicLogicUnit
{
public:
    AritmethicLogicUnit();
    AritmethicLogicUnit(float* normal, float * ieee, std::string opertation);
    void solve();
    int tokenizeString(float *n1, float *n2);
private:
    float * normal;
    float * ieee;
    std::string oper;
    //OPERATIONS
    std::bitset<TEMP> suma(std::bitset<TEMP> oper1,std::bitset<TEMP> oper2);
    std::bitset<TEMP> resta(std::bitset<TEMP> oper1,std::bitset<TEMP> oper2);
    std::bitset<TEMP> multiplicacion(std::bitset<TEMP> oper1, std::bitset<TEMP> oper2);
    std::bitset<TEMP> division(std::bitset<TEMP> oper1,std::bitset<TEMP> oper2);
    //CASTS
    std::bitset<TEMP> toBinary (float num);
    float toDecimal(std::bitset<TEMP> num);
    std::string toHex(std::bitset<TEMP> num);
};

#endif // ARITMETHICLOGICUNIT_H
