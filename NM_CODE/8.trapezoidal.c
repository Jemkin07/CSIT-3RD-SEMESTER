#include <stdio.h>

// Define the function to integrate here
double function(double x) {
    // Example: integrate f(x) = x^2
    return x * x;
}

// Trapezoidal rule function
double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double integral = 0.0;

    // Sum the first and last terms
    integral += (function(a) + function(b)) / 2.0;

    // Sum the middle terms
    for (int i = 1; i < n; i++) {
        integral += function(a + i * h);
    }

    integral *= h; // Multiply by step size
    return integral;
}

int main() {
    printf("Sasank Lama \n");
    double a, b;
    int n;

    // Get user input
    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of sub-intervals (n): ");
    scanf("%d", &n);

    // Calculate the integral
    double result = trapezoidal_rule(a, b, n);

    // Print the result
    printf("The integral is: %lf\n", result);

    return 0;
}
