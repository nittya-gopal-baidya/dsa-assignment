#include <stdio.h>

// Function to input matrix elements
void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int cols2, int mat2[rows2][cols2], int result[rows1][cols2]) {
    if (cols1 != rows2) {
        printf("Multiplication is not possible due to incompatible dimensions.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Resultant Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions of the first matrix
    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &cols1);

    // Input dimensions of the second matrix
    printf("\nEnter the number of rows for the second matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &cols2);

    // Check if multiplication is possible
    if (cols1 != rows2) {
        printf("Invalid dimensions. Multiplication is not possible.\n");
        return 1; 
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    // Input elements of the first matrix
    printf("\nEnter the first matrix:\n");
    inputMatrix(rows1, cols1, matrix1);

    // Input elements of the second matrix
    printf("\nEnter the second matrix:\n");
    inputMatrix(rows2, cols2, matrix2);

    // Multiply matrices and check if multiplication is possible
    multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

    // Display the resultant matrix
    if (cols1 == rows2) {
        displayMatrix(rows1, cols2, result);
    }

    return 0;
}
