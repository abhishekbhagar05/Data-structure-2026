#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter the size of the square matrix (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int matrix[n][n];
    int i, j;
    int primarySum = 0, secondarySum = 0;

    printf("Enter %d elements of the matrix:\n", n * n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        primarySum += matrix[i][i];         
        secondarySum += matrix[i][n - 1 - i]; 
    }

    int difference = abs(primarySum - secondarySum);
    printf("Sum of primary diagonal: %d\n", primarySum);
    printf("Sum of secondary diagonal: %d\n", secondarySum);
    printf("Absolute difference between sums: %d\n", difference);

    return 0;
}
