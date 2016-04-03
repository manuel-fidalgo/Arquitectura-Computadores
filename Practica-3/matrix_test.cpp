#include "matrix_test.h"
Matrix_test::Matrix_test(){
    this->nTest=0;
    crono = new Chronometer();
}

int *** Matrix_test::getMatrix(){
    return this->matrix;
}
/**
 * @brief Matrix_test::init
 * @param DIMENSIONS
 * @return Time of the test
 * ERROR EN POSIBLE FALLO DE ALOJAMIENTO DE MEMORIA!
 */
double Matrix_test::init(int DIMENSIONS){
    int *** trans;

    /**/
    crono->init();
    /**/
    srand(time(NULL));
    this->nTest++;

    matrix = (int ***)malloc(DIMENSIONS*sizeof(int **));
    trans = (int ***)malloc(DIMENSIONS*sizeof(int **));
    if(matrix==NULL)return -1;
    if(trans==NULL)return -1;

    for(int i=0; i<DIMENSIONS; i++){
        matrix[i]=(int **)malloc(DIMENSIONS*sizeof(int *));
        trans[i]=(int **)malloc(DIMENSIONS*sizeof(int *));
        if(matrix[i]==NULL) return -1;
        if(trans[i]==NULL) return -1;
    }
    for(int i=0; i<DIMENSIONS; i++){
        for (int j = 0; j < DIMENSIONS; ++j) {
            matrix[i][j]=(int *)malloc(DIMENSIONS*sizeof(int));
            trans[i][j]=(int *)malloc(DIMENSIONS*sizeof(int));
            if(matrix[i][j] == NULL)return -1;
            if(trans[i][j] == NULL)return -1;
        }
    }
    for (int x = 0; x < DIMENSIONS; ++x) {
        for (int y = 0; y < DIMENSIONS; ++y) {
            for (int z = 0;  z< DIMENSIONS; z++) {
                matrix[x][y][z] = (int)(rand()*100);
            }
        }
    }

    for (int x = 0; x < DIMENSIONS; ++x) {
        for (int y = 0; y < DIMENSIONS; ++y) {
            for (int z = 0;  z< DIMENSIONS; z++) {
               trans[y][x][z]=matrix[x][y][z];
            }
        }
    }
    free(matrix);
    free(trans);
   // liberarMemoria(matrix,trans,DIMENSIONS);
    return crono->end();
}

int Matrix_test::getNTest(){
    return this->nTest;
}
/*
void Matrix_test::liberarMemoria(int ***matrix, int*** trans, int DIMENSIONS){
    for (int x = 0; x < DIMENSIONS; ++x) {
        for (int y = 0; y < DIMENSIONS; ++y) {
            for (int z = 0;  z< DIMENSIONS; z++) {
              // free(matrix[x][y][z]);
              // free(trans[x][y][z]);
            }
       }
    }
}
*/
