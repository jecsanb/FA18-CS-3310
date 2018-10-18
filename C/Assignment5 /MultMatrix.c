#include <stdio.h> 
#include <stdlib.h>

/**
 *  Jecsan Blanco
 *  PROGRAMMING-LANGUAGES-CS-3310
 *  Assignment 5
 *
 *  In this assignment you will store user input two square matrices of size n <= 10
 *  as one dimensional arrays and compute the product of the first matrix times
 *  the second matrix and store as another a single dimensional array and display
 *  the product.
 *
 *  You can use only single dimension arrays for input and product matrices.
 *
 *  Your program must use malloc to allocate block of memory to store input
 *  and product matrices as single dimensional arrays
 *
 * You program must compute product of the input matrices using a function such as:
 * void mult(int * a, int *, int *b, int *c, int n), where matrix array c = matrix array
 * a matrix array b, and n is size of the matrix.
 * @return
 */

int valAt(int const *, int, int, int);

void multMatrix(int const *, int const *, int *, int);

void printMatrix(int const *, int);

void readMatrix(int *, int);

void multMatrix(int const matrix_a[],
                int const matrix_b[],
                int matrix_result[],
                int n) {
    int mult = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                mult += valAt(matrix_a, i, k, n) * valAt(matrix_b, k, j, n);
//                    printf("Mult:%d = a[%d,%d]*b[%d,%d]\n",mult,i,k,k,j);
            }
            matrix_result[l++] = mult;
            mult = 0;
        }

    }

}

//provides abstraction to interact with a 1D array as a 2D array
// retrieves the element at i , j
int valAt(int const array[], int i, int j, int n) {
    return *(array + (i * n + j));
}

void printMatrix(const int array[], int n) {
    for (int i = 1; i <= n * n; i++) {
        printf("%d ", array[i - 1]);
        if (!(i % n))
            printf("\n");
    }
    printf("\n");
}

void readMatrix(int *array, int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        printf("Enter %d numbers for row %d and press enter:", size, i);
        for (int j = 0; j < size; j++)
            scanf("%d", &array[k++]);
    }
}


int main(void) {

    int matrix_dims = 0;
    int array_size = 0;
    int *matrix_0 = NULL;
    int *matrix_1 = NULL;
    int *matrix_result = NULL;

    while (matrix_dims <= 0 || matrix_dims > 10) {
        printf("Enter a value for size of matrix <= 10:");
        scanf("%d", &matrix_dims);
    }
    array_size = matrix_dims * matrix_dims;
    matrix_0 = (int*) malloc(array_size * sizeof(int));
    matrix_1 = (int*) malloc(array_size * sizeof(int));
    matrix_result =(int*)  malloc(array_size * sizeof(int));
//
    printf("Enter your first matrix\n");
    readMatrix(matrix_0, matrix_dims);
    printf("You entered for first matrix:\n");
    printMatrix(matrix_0, matrix_dims);

    readMatrix(matrix_1, matrix_dims);
    printf("You entered for second matrix:\n");
    printMatrix(matrix_1, matrix_dims);
    printf("\n");
    multMatrix(matrix_0, matrix_1, matrix_result, matrix_dims);
    printf("The product is:\n");
    printMatrix(matrix_result, matrix_dims);

    free(matrix_0);
    free(matrix_1);
    free(matrix_result);
    return 0;
}




