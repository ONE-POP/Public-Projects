#include <stdio.h>

unsigned long matrix1[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

unsigned long matrix2[3][3] = {
    {10, 11, 12},
    {13, 14, 15},
    {16, 17, 18}
};

void matrix_add(unsigned long matrix1[3][3], unsigned long matrix2[3][3], unsigned long result[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    unsigned long result[3][3];
    matrix_add(matrix1, matrix2, result);
    
    printf("Matrix in decimal: \n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%ld ", result[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatrix in hex: \n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%lx ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
