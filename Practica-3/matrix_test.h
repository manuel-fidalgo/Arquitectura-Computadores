#ifndef MATRIX_TEST_H
#define MATRIX_TEST_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include "chronometer.h"


class Matrix_test
{
private:
    int *** matrix;
    int nTest;
    Chronometer * crono;

public:
    Matrix_test();
    int*** getMatrix();
    double init(int DIMENSIONS);
    int getNTest();
    //void liberarMemoria(int *** matrix, int *** trans, int DIMENSIONS);
};

#endif // MATRIX_TEST_H
