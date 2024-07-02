#include <stdio.h>
#include <math.h>

// Define the function to integrate here
double f(double x) {
    return sin(x); // Example: integrating sin(x)
}

// Romberg Integration function
double romberg(double (*func)(double), double a, double b, int n) {
    double h, sum;
    double R[n][n];

    // Initialize R matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            R[i][j] = 0.0;
        }
    }

    // Step size for the trapezoidal rule
    h = b - a;

    // First approximation (R[0][0]) using the trapezoidal rule
    R[0][0] = 0.5 * h * (func(a) + func(b));

    for (int i = 1; i < n; i++) {
        h /= 2.0;
        sum = 0.0;

        // Sum of function values at new points
        for (int k = 1; k <= (1 << (i - 1)); k++) {
            sum += func(a + (k - 0.5) * h);
        }

        // Update R[i,0] with the trapezoidal rule
        R[i][0] = 0.5 * R[i - 1][0] + sum * h;

        // Romberg extrapolation
        for (int j = 1; j <= i; j++) {
            R[i][j] = R[i][j - 1] + (R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }
    }

    // Return the most accurate estimate
    return R[n - 1][n - 1];
}

int main() {
    printf("Sasank Lama \n");
    double a = 0;  // Lower limit
    double b = M_PI;  // Upper limit
    int n = 5;  // Number of rows in Romberg table, can be increased for higher accuracy

    double result = romberg(f, a, b, n);

    printf("Integral value: %lf\n", result);

    return 0;
}
