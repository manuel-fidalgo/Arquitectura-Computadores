#ifndef ARITMETHICLOGICUNIT_H
#define ARITMETHICLOGICUNIT_H
#include <string>



class AritmethicLogicUnit
{
public:
    AritmethicLogicUnit();
    AritmethicLogicUnit(int* normal, int * ieee, std::string opertation);
    void solve();
    void tokenizeString(int * n1, int * n2);
private:
    int * normal;
    int * ieee;
    std::string oper;
};

#endif // ARITMETHICLOGICUNIT_H
