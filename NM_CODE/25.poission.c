#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 10000
#define TOLERANCE 1e-6

void initialize_grid(double **u, double **f, int m, int n) {
    // Initialize the grid with boundary conditions and source term
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                u[i][j] = 0.0; // Boundary conditions
            } else {
                u[i][j] = 0.0; // Initial guess for interior points
            }
            f[i][j] = 1.0; // Example source term, can be modified
        }
    }
}

void solve_poisson(double **u, double **f, int m, int n, double h) {
    int iter = 0;
    double diff;

    do {
        diff = 0.0;
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                double new_value = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1] - h*h*f[i][j]);
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
    double h;
    printf("Enter the grid size (m n): ");
    scanf("%d %d", &m, &n);
    printf("Enter the grid spacing (h): ");
    scanf("%lf", &h);

    // Dynamically allocate memory for the grids
    double **u = (double **)malloc(m * sizeof(double *));
    double **f = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        u[i] = (double *)malloc(n * sizeof(double));
        f[i] = (double *)malloc(n * sizeof(double));
    }

    // Initialize the grid
    initialize_grid(u, f, m, n);

    // Solve Poisson's equation
    solve_poisson(u, f, m, n, h);

    // Print the resulting grid
    printf("Resulting grid:\n");
    print_grid(u, m, n);

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(u[i]);
        free(f[i]);
    }
    free(u);
    free(f);

    return 0;
}
