#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
typedef struct {
    int exponent;
    double coefficient;
} Term;

// Function to add two polynomials
void addPolynomials(int m1, Term poly1[], int m2, Term poly2[], int *resultSize, Term result[]) {
    int i = 0, j = 0, k = 0;

    // Continue until one of the polynomials is exhausted
    while (i < m1 && j < m2) {
        if (poly1[i].exponent > poly2[j].exponent) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exponent < poly2[j].exponent) {
            result[k++] = poly2[j++];
        } else {
            // If exponents are equal, add coefficients
            result[k].exponent = poly1[i].exponent;
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            i++;
            j++;
            k++;
        }
    }

    // Copy remaining terms from the first polynomial, if any
    while (i < m1) {
        result[k++] = poly1[i++];
    }

    // Copy remaining terms from the second polynomial, if any
    while (j < m2) {
        result[k++] = poly2[j++];
    }

    // Set the size of the result polynomial
    *resultSize = k;
}

// Function to print a polynomial
void printPolynomial(int size, Term poly[]) {
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            printf(" + ");
        }
        printf("%.2f * x^%d", poly[i].coefficient, poly[i].exponent);
    }
    printf("\n");
}

int main() {
    int m1, m2;

    // Input the size of the first polynomial
    printf("Enter the size of the first polynomial: ");
    scanf("%d", &m1);

    // Input the terms of the first polynomial
    Term poly1[m1];
    printf("Enter the terms of the first polynomial (exponent coefficient): \n");
    for (int i = 0; i < m1; i++) {
        scanf("%d %lf", &poly1[i].exponent, &poly1[i].coefficient);
    }

    // Input the size of the second polynomial
    printf("Enter the size of the second polynomial: ");
    scanf("%d", &m2);

    // Input the terms of the second polynomial
    Term poly2[m2];
    printf("Enter the terms of the second polynomial (exponent coefficient): \n");
    for (int i = 0; i < m2; i++) {
        scanf("%d %lf", &poly2[i].exponent, &poly2[i].coefficient);
    }

    // Calculate the result polynomial
    int resultSize;
    Term result[m1 + m2];
    addPolynomials(m1, poly1, m2, poly2, &resultSize, result);

    // Print the input polynomials and the result
    printf("\nPolynomial 1: ");
    printPolynomial(m1, poly1);

    printf("Polynomial 2: ");
    printPolynomial(m2, poly2);

    printf("Result: ");
    printPolynomial(resultSize, result);

    return 0;
}
