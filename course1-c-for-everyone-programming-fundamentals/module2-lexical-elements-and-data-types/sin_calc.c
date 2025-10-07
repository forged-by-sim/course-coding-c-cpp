#include <stdio.h>
#include <math.h>

int main() {
    double x;
    printf("Enter a value between 0 and 1 (non-inclusive): ");
    scanf("%lf", &x);
    if (x <= 0.0 || x >= 1.0) {
        printf("Error: Value must be between 0 and 1 (exclusive).\n");
        return 1; // Exit with error
    }

    double result = sin(x);
    printf("sin(%.6f) = %.6f\n", x, result);
    return 0;
}
