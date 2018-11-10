/**
 * Jecsan Blanco
 * 2018FA PROGRAMMING LANGUAGES (CS-3310-01)
 * Write a C Linux program to multiply two square matrices of size <= 10 using
 * three different multiplication functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


void mult2DIntMatrix(size_t N,size_t M, int matrixA[N][M], int matrixB[N][M], int product[N][M]) {
    int mult = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                mult += matrixA[i][k] * matrixB[k][j];
//                printf("[%d] * [%d]=[%d]\n",matrixA[i][k],matrixB[k][j],matrixA[i][k]*matrixB[k][j]);
//                printf(" + ");
            }
            product[i][j] = mult;
//            printf("=[%d]\n",mult);
            mult = 0;
        }
    }

}
void print2DIntMatrix(size_t N,size_t M,int matrix[N][M]) {
    for(int i = 0; i < N; ++i){
        printf("[");
        for (int j = 0; j < M; ++j) {
            printf(" %-1d ",matrix[i][j]);
        }
        printf("]\n");
    }
}
void get2DIntMatrix(size_t N,size_t M, int matrix[N][M]){
    int upper = 50, lower = 10, num = 0;
    for(int i = 0; i < N; ++i){
          for (int j = 0; j < M; ++j) {
              num = (rand() %
                         (upper - lower + 1)) + lower;
//                printf("[%d][%d] = %d \n",i,j,num);
                matrix[i][j] = num;
          }
      }
}
int main(int argc, char** argsv) {

    srand(time(NULL));   // Initialization, should only be called once.
    const size_t N = 2;
    const size_t M = 2;
    int matrixA[N][M] ={
            {23,34},
            {11,22}
    };
    int matrixB[N][M]={
            {14,15},
            {12,22}
    };

    int product[N][M];

//    get2DIntMatrix(N,M,matrixA);
    printf("Matrix a:\n");
    print2DIntMatrix(N,M,matrixA);

//    get2DIntMatrix(N,M,matrixB);
    printf("Matrix b:\n");
    print2DIntMatrix(N,M,matrixB);

    mult2DIntMatrix(N,M,matrixA,matrixB,product);
    printf("Product b:\n");
    print2DIntMatrix(N,M,product);
    return 0;
}