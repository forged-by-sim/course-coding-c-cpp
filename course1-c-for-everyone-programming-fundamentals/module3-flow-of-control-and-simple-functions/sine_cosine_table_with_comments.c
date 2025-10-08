#include <stdio.h>
#include <math.h>

// Function to print a table of sine and cosine values between start and end
void print_sine_cosine_table(double start, double end, double step) {
    double x;

    // Print table header
    printf("x\t\tsin(x)\t\tcos(x)\n");
    printf("----------------------------------------\n");

    // Loop through the interval and print sine and cosine values
    for (x = start; x < end; x += step) {
        printf("%.2f\t\t%.6f\t%.6f\n", x, sin(x), cos(x));
    }
}

int main(void) {
    // Define range and step size
    double start = 0.1;
    double end = 1.0;
    double step = 0.1;

    // Call the function to print the table
    print_sine_cosine_table(start, end, step);

    return 0;
}
