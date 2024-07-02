#include <stdio.h>
#include <stdlib.h>

// Function to perform Doolittle LU decomposition
void doolittleLU(double **A, double **L, double **U, int n) {
    for (int i = 0; i < n; i++) {
        // Calculate U[i][j]
        for (int j = i; j < n; j++) {
            U[i][j] = A[i][j];
            for (int k = 0; k < i; k++) {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        // Calculate L[i][j]
        for (int j = i; j < n; j++) {
            if (i == j) {
                L[i][i] = 1.0; // Diagonal as 1
            } else {
                L[j][i] = A[j][i];
                for (int k = 0; k < i; k++) {
                    L[j][i] -= L[j][k] * U[k][i];
                }
                L[j][i] /= U[i][i];
            }
        }
    }
}

int main() {
    printf("Sasank Lama \n");
    int n;
    printf("Enter the dimension of the square matrix: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the matrices
    double **A = (double **)malloc(n * sizeof(double *));
    double **L = (double **)malloc(n * sizeof(double *));
    double **U = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        L[i] = (double *)malloc(n * sizeof(double));
        U[i] = (double *)malloc(n * sizeof(double));
    }

    // Input the matrix A
    printf("Enter the elements of the matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
            L[i][j] = 0.0; // Initialize L matrix to 0
            U[i][j] = 0.0; // Initialize U matrix to 0
        }
    }

    // Perform Doolittle LU decomposition
    doolittleLU(A, L, U, n);

    // Output the matrices L and U
    printf("The Lower Triangular matrix L is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", L[i][j]);
        }
        printf("\n");
    }

    printf("The Upper Triangular matrix U is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", U[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(L[i]);
        free(U[i]);
    }
    free(A);
    free(L);
    free(U);

    return 0;
}

