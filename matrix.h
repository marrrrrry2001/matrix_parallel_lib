#ifndef MATRIX_H
#define MATRIX_H
#include <time.h>
#include "matrix.h"

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix;

matrix matrix_add(matrix a, matrix b);
matrix matrix_create(int rows, int cols);
void matrix_destroy(matrix m);
void matrix_set(matrix m, int row, int col, double value);
double matrix_get(matrix m, int row, int col);
matrix matrix_add(matrix a, matrix b);
matrix matrix_multiply(matrix a, matrix b);
void matrix_print(matrix a);
void matrix_free(matrix* a);



#endif
