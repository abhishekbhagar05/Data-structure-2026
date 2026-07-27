#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int first[10][10], int second[10][10], int result[10][10],
                      int r1, int c1, int r2, int c2) {
    // Initialize result matrix to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int main() {
    int first[10][10], second[10][10], result[10][10];
    int r1, c1, r2, c2;

    // Input dimensions
    printf("Enter rows and columns for first matrix (max 10x10): ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 <= 0 || c1 <= 0 || r1 > 10 || c1 > 10) {
        printf("Invalid dimensions for first matrix.\n");
        return 1;
    }

    printf("Enter rows and columns for second matrix (max 10x10): ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 <= 0 || c2 <= 0 || r2 > 10 || c2 > 10) {
        printf("Invalid dimensions for second matrix.\n");
        return 1;
    }

    if (c1 != r2) {
        printf("Matrix multiplication not possible. Columns of first must equal rows of second.\n");
        return 1;
    }

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (scanf("%d", &first[i][j]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            if (scanf("%d", &second[i][j]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }
    }

    multiplyMatrices(first, second, result, r1, c1, r2, c2);
    printf("Resultant matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
