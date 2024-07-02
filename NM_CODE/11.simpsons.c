#include <stdio.h>

// Define the function to integrate here
double function(double x) {
    // Example: integrate f(x) = x^2
    return x * x;
}

// Simpson's 3/8 rule function
double simpsons_38_rule(double a, double b, int n) {
    // Ensure that n is a multiple of 3
    if (n % 3 != 0) {
        printf("Number of intervals must be a multiple of 3.\n");
        return -1; // Error value
    }

    double h = (b - a) / n; // Step size
    double integral = function(a) + function(b);

    // Calculate the sum of the terms
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            integral += 2 * function(x);
        } else {
            integral += 3 * function(x);
        }
    }

    integral *= 3 * h / 8.0; // Multiply by 3h/8
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
    printf("Enter the number of sub-intervals (n, must be a multiple of 3): ");
    scanf("%d", &n);

    // Validate the number of sub-intervals
    if (n <= 0 || n % 3 != 0) {
        printf("The number of sub-intervals must be a positive multiple of 3.\n");
        return 1;
    }

    // Calculate the integral
    double result = simpsons_38_rule(a, b, n);

    // Print the result
    if (result != -1) { // Check for error
        printf("The integral is: %lf\n", result);
    }

    return 0;
}
