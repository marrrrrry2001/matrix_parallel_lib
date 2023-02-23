#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <time.h>

// matrix generate_random_matrix(int n) {
//     matrix m = matrix_create(n, n);
//     srand(time(NULL));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             double random_number = (double) rand() / RAND_MAX;
//             matrix_set(m, i, j, random_number);
//         }
//     }
//     return m;
// }


int main() {
    // сложение
    matrix a = {10, 10, (double[]) {1, 2, 3, 4}};
    matrix b = {10, 10, (double[]) {4, 3, 2, 1}};
    for (int i = 0; i < a.rows * a.cols; i++) {
        a.data[i] = (double) rand() / RAND_MAX;
    }
    for (int i = 0; i < b.rows * b.cols; i++) {
        b.data[i] = (double) rand() / RAND_MAX;
    }
    int n = 10;
    // matrix a = generate_random_matrix(n);
    // matrix b = generate_random_matrix(n);
    matrix c = matrix_add(a, b);

    // умножение
    srand(time(NULL));
    matrix cc = matrix_multiply(a, b);

    
    printf("Matrix A:\n");
    matrix_print(a);
    printf("Matrix B:\n");
    matrix_print(b);
    printf("Matrix C = A+B:\n");
    printf("%f %f\n", c.data[0], c.data[1]);
    printf("%f %f\n", c.data[2], c.data[3]);
    free(c.data);
    printf("Matrix C = A*B:\n");
    matrix_print(cc);
    matrix_free(&a);
    matrix_free(&b);
    matrix_free(&cc);


    return 0;
}
