#ifndef MATRIX_TEST_H
#define MATRIX_TEST_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>


class Matrix_test
{
private:
    int *** matrix;
    double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b);
    int nTest;
public:
    Matrix_test();
    int*** getMatrix();
    double init(int DIMENSIONS);
    int getNTest();
};

#endif // MATRIX_TEST_H
