#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000
#define TOLERANCE 1e-6

void initialize_grid(double **u, int m, int n) {
    // Initialize the grid with boundary conditions
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0)
                u[i][j] = 100.0; // Top boundary
            else if (i == m-1)
                u[i][j] = 0.0; // Bottom boundary
            else if (j == 0)
                u[i][j] = 0.0; // Left boundary
            else if (j == n-1)
                u[i][j] = 0.0; // Right boundary
            else
                u[i][j] = 0.0; // Initial guess for interior points
        }
    }
}

void solve_laplace(double **u, int m, int n) {
    int iter = 0;
    double diff;

    do {
        diff = 0.0;
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                double new_value = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]);
                diff = fmax(diff, fabs(new_value - u[i][j]));
                u[i][j] = new_value;
            }
        }
        iter++;
    } while (diff > TOLERANCE && iter < MAX_ITER);

    printf("Converged in %d iterations with max diff = %e\n", iter, diff);
}

void print_grid(double **u, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.4f ", u[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Sasank Lama \n");
    int m, n;
    printf("Enter the grid size (m n): ");
    scanf("%d %d", &m, &n);

    // Dynamically allocate memory for the grid
    double **u = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        u[i] = (double *)malloc(n * sizeof(double));
    }

    // Initialize the grid
    initialize_grid(u, m, n);

    // Solve Laplace's equation
    solve_laplace(u, m, n);

    // Print the resulting grid
    printf("Resulting grid:\n");
    print_grid(u, m, n);

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(u[i]);
    }
    free(u);

    return 0;
}
