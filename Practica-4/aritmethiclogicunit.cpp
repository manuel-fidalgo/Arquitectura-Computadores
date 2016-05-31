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

AritmethicLogicUnit::outPutData AritmethicLogicUnit::solve(){
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
    case 1: res_binario = suma(oper_1, toBinary(-oper_2_decimal));
        res_decimal = oper_1_decimal-oper_2_decimal;
        break;
    case 2: res_binario = multiplicacion(oper_1, oper_2);
        res_decimal = oper_1_decimal*oper_2_decimal;
        break;
    case 3: res_binario = division(oper_1,oper_2);
        res_decimal = oper_1_decimal/oper_2_decimal;
        break;
    }
    outPutData out;
    //Devolvemos los resultados en forma de punteros
    *this->normal = res_decimal;
    *this->ieee = toDecimal(res_binario);
    //Pasamos los parametros al struct que vamos a devolver.
    out.IEEE_bits = res_binario;
    out.IEEE_hex = toHex(res_binario);
    return out;
}
/*
     * resta = expondente es el resultado del mayor
     * signo = singo del mayor(del que tiene mayor exponente)
     * exponente es el de mayor exponente
     * cgemos las mantisas de 24 bits y desplazamos hacia la derecha la amntira del expoente menor tantos lugares como diferncia de exponentes haya
     * si el ultimo acarreo es 1 le sumamos 1 al exponente
     */
std::bitset<TEMP> AritmethicLogicUnit::suma(std::bitset<TEMP> oper1, std::bitset<TEMP> oper2){
    std::bitset<TEMP> res;

    double oper1_exp = getExp(oper1);
    double oper2_exp = getExp(oper2);
    float exp = oper1_exp+oper2_exp;


    if(oper1_exp > oper2_exp){

        res.set(0,oper1[0]);
        desplazarMantisa(oper2,oper1_exp,oper2_exp);
        int ac = sumarMantisas(res,oper1,oper2);
        if(ac==1)
            exp++;

        setExponent(exp,res);

    }
    if(oper2_exp > oper1_exp){

        res.set(0,oper2[0]);
        desplazarMantisa(oper1,oper1_exp,oper2_exp);
        int ac = sumarMantisas(res,oper2,oper1);
        if(ac==1)
            exp++;

        setExponent(exp,res);

    }
    if(oper1_exp==oper2_exp){

    }
    return res;
}
/*Toma ambos numeros, almacena los 24 bits de la mantisa en el resultad y devuelve el accarreo*/
int AritmethicLogicUnit::sumarMantisas(std::bitset<TEMP> res,std::bitset<TEMP> oper1, std::bitset<TEMP> oper2 ){
   bool c=0;

    for (int var = 31; var >= 8; ++var) {
        res.set(var,XOR(XOR(oper1[var],oper2[var]),c));
        c =((oper1[var]&oper2[var])|(oper1[var] & c)|(oper2[var] & c));
    }
    return c;
}

bool AritmethicLogicUnit::XOR(bool a, bool b)
{
    return (a + b) % 2;
}

void AritmethicLogicUnit::desplazarMantisa(std::bitset<TEMP> oper,float op1_exp, float op2_exp){
    int desp = abs(op1_exp-op2_exp);
    int ac;
    /*bits del 8 al 31 inclusive*/
    std::bitset<23> mantisa;
    for (int var = 8; var < 32; ++var) {
        mantisa.set(var-8,oper[var]);
    }
    mantisa << desp; //mantisa desplazada tantas posiciones como es necesario.
    for (int var = 8; var < 32; ++var) {
        oper.set(var,mantisa[var-8]);
    }

}

std::bitset<TEMP> AritmethicLogicUnit::multiplicacion(std::bitset<TEMP> oper1, std::bitset<TEMP> oper2){
    std::bitset<TEMP> * res = new std::bitset<TEMP>();
    res->set(0,!oper1[0] != !oper2[0]); //Bit de signo
    sumaExponentes(res,oper1,oper2); //exponentes
    multiplicarMantisas(res,oper1,oper2);
    return oper1;
}
/*Multiplica las mantisas y las almacena en el resultado*/
void AritmethicLogicUnit::multiplicarMantisas(std::bitset<TEMP> *res, std::bitset<TEMP> oper1, std::bitset<TEMP> oper2){

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
    union{
        long  in;
        float out;
    } current_union;

    current_union.in = num.to_ulong();
    if(DEBUG) std::cout << "toDecimal-> " << current_union.out << std::endl;
    return current_union.out;
}
std::string AritmethicLogicUnit::toHex(std::bitset<TEMP> num){
    std::ostringstream res;
    res << std::hex << std::uppercase << num.to_ulong() << std::endl;
    if(DEBUG) std::cout <<"Hex->"<< res.str();
    return res.str();
}
int AritmethicLogicUnit::getExp(std::bitset<TEMP> binaryNumber){
    double acum = 0;
    double power = 0;
    //Pasamos a decimal interpretanto los bits de menos a mas peso
    for(int i = 8; i > 0; i--){
        if(binaryNumber[i] == 1) acum += pow((double)2, power);
        power++;
    }
    return((int)acum - EXP_DESP);
}
void AritmethicLogicUnit::sumaExponentes(std::bitset<TEMP> * res, std::bitset<TEMP> oper1,std::bitset<TEMP> oper2){
    int exp1 = getExp(oper1);
    int exp2 = getExp(oper2);
    int finalExp = exp1+exp2;
    std::bitset<8> * exponente = new std::bitset<8>;
    for (int var = 0; var < 8; ++var) {
        res->set(var+DESPLAZAMIENTO_EXPONENENTE,exponente->test(var));
    }
    delete exponente;
}
void AritmethicLogicUnit::setExponent(int exp, std::bitset<TEMP> binary){

}

void multiplicarMantisas(std::bitset<TEMP> * res,std::bitset<TEMP> oper1,std::bitset<TEMP> oper2){

}


