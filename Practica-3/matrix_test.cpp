#include "matrix_test.h"
Matrix_test::Matrix_test(){
    this->nTest=0;
}

int*** Matrix_test::getMatrix(){
    return this->matrix;
}
double Matrix_test::init(int DIMENSIONS){
    srand(time(NULL));
    this->nTest++;

    LARGE_INTEGER t_ini, t_fin;
    QueryPerformanceCounter(&t_ini);

    matrix = (int ***)malloc(DIMENSIONS*sizeof(int **));

    for(int i=0; i<DIMENSIONS; i++){
        matrix[i]=(int **)malloc(DIMENSIONS*sizeof(int *));
    }
    for(int i=0; i<DIMENSIONS; i++){
        for (int j = 0; j < DIMENSIONS; ++j) {
            matrix[i][j]=(int *)malloc(DIMENSIONS*sizeof(int));
        }
    }
    for (int x = 0; x < DIMENSIONS; ++x) {
        for (int y = 0; y < DIMENSIONS; ++y) {
            for (int z = 0;  z< DIMENSIONS; z++) {
                matrix[x][y][z] = (int)(rand()*100);
            }
        }
    }
    QueryPerformanceCounter(&t_fin);
    return performancecounter_diff(&t_fin, &t_ini);
}
double Matrix_test::performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
int Matrix_test::getNTest(){
    return this->nTest;
}
