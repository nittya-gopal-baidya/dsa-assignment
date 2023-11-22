#include <stdio.h>

void multiplyComplexMatrices(int n, double A[][n], double B[][n], double C[][n], double D[][n], double E[][n], double F[][n]) {
    int i, j, k;

    // Multiply matrices to get real and imaginary parts
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            E[i][j] = A[i][j] * C[i][j] - B[i][j] * D[i][j]; // Real part
            F[i][j] = A[i][j] * D[i][j] + B[i][j] * C[i][j]; // Imaginary part
        }
    }
}

int main() {
    int n;
    
    // Input the size of the matrices
    printf("Enter the size of the matrices (n): ");
    scanf("%d", &n);

    double A[n][n], B[n][n], C[n][n], D[n][n], E[n][n], F[n][n];

    // Input values for matrices A and B
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%lf", &B[i][j]);
        }
    }

    // Input values for matrices C and D
    printf("Enter the elements of matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("C[%d][%d]: ", i, j);
            scanf("%lf", &C[i][j]);
        }
    }

    printf("Enter the elements of matrix D:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("D[%d][%d]: ", i, j);
            scanf("%lf", &D[i][j]);
        }
    }

    // Multiply the complex matrices
    multiplyComplexMatrices(n, A, B, C, D, E, F);

    // Display the result
    printf("\nResulting matrix (E):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f + %.2fi\t", E[i][j], F[i][j]);
        }
        printf("\n");
    }

    return 0;
}