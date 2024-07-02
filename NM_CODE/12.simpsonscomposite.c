#include <stdio.h>

// Define the function to integrate here
double function(double x) {
    // Example: integrate f(x) = x^2
    return x * x;
}

// Composite Simpson's 1/3 rule function
double composite_simpsons_rule(double a, double b, int n) {
    // Ensure that n is even
    if (n % 2 != 0) {
        printf("Number of intervals must be even.\n");
        return -1; // Error value
    }

    double h = (b - a) / n; // Step size
    double integral = function(a) + function(b);

    // Calculate the sum of the terms
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            integral += 2 * function(x);
        } else {
            integral += 4 * function(x);
        }
    }

    integral *= h / 3.0; // Multiply by step size / 3
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
    printf("Enter the number of sub-intervals (n, must be even): ");
    scanf("%d", &n);

    // Validate the number of sub-intervals
    if (n <= 0 || n % 2 != 0) {
        printf("The number of sub-intervals must be a positive even integer.\n");
        return 1;
    }

    // Calculate the integral
    double result = composite_simpsons_rule(a, b, n);

    // Print the result
    if (result != -1) { // Check for error
        printf("The integral is: %lf\n", result);
    }

    return 0;
}
