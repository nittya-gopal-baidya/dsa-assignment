#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("\nEnter element at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}


void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}


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
    int rows, cols;

    // Input dimensions of the matrices
    printf("\nEnter the number of rows for the matrices: ");
    scanf("%d", &rows);
    printf("\nEnter the number of columns for the matrices: ");
    scanf("%d", &cols);

    // Check if subtraction is possible
    if (rows <= 0 || cols <= 0) {
        printf("\n\t\t--------------------------------------------------------------");
        printf("\n\t\t\tInvalid dimensions. Subtraction is not possible.\n");
        printf("\n\t\t--------------------------------------------------------------");
        return 1; // Exit with an error code
    }

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    // Input elements of the first matrix
    printf("\n\t\t---------------------------------------------");
    printf("\n\t\t\tEnter the data for first matrix\n");
    printf("\n\t\t---------------------------------------------");
    inputMatrix(rows, cols, matrix1);

    // Input elements of the second matrix
    printf("\n\t\t-------------------------------------------------");
    printf("\n\t\t\tEnter the data for second matrix:\n");
    printf("\n\t\t-------------------------------------------------");
    inputMatrix(rows, cols, matrix2);

    // Subtract matrices and check if subtraction is possible
    subtractMatrices(rows, cols, matrix1, matrix2, result);

    // Display the resultant matrix
    displayMatrix(rows, cols, result);

    return 0;
}
