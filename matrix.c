#include "matrix.h"
#include <stdlib.h>
#include <omp.h>
#include <stdio.h>


void matrix_print(matrix a) {
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            printf("%f ", a.data[i * a.cols + j]);
            }
            printf("\n");
    }
}

void matrix_free(matrix* a) {
    free(a->data);
    a->rows = 0;
    a->cols = 0;
}

matrix matrix_add(matrix a, matrix b) {
    matrix c = {a.rows, a.cols, malloc(a.rows * a.cols * sizeof(double))};
    #pragma omp parallel for
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            int index = i * a.cols + j;
            c.data[index] = a.data[index] + b.data[index];
        }
    }
    return c;
}

matrix matrix_multiply(matrix a, matrix b) {
matrix c = {a.rows, b.cols, malloc(a.rows * b.cols * sizeof(double))};

    #pragma omp parallel for
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < a.cols; k++) {
                sum += a.data[i * a.cols + k] * b.data[k * b.cols + j];
            }
            c.data[i * c.cols + j] = sum;
        }
    }

    return c;
}