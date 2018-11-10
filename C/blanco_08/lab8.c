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
    const size_t N = 4;
    const size_t M = 4;
    int matrix[N][M];
    get2DIntMatrix(N,M,matrix);
    print2DIntMatrix(N,M,matrix);
    return 0;
}