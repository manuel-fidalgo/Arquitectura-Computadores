#ifndef ARITMETHICLOGICUNIT_H
#define ARITMETHICLOGICUNIT_H
#include <string>
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
    float suma(float oper1,float oper2);
    float resta(float oper1,float oper2);
    float multiplicacion(float oper1,float oper2);
    float division(float oper1,float oper2);
    float toBinaryIEEE(float number);
    float toBinary (float num);
};

#endif // ARITMETHICLOGICUNIT_H
