#include <stdio.h>

#define PI 3.14159

int main(void)
{ 
    double radius;  // use double
    double volume;

    printf("Enter radius: ");
    scanf("%lf", &radius);  // use %lf for double

    volume = (4.0/3.0) * PI * radius * radius * radius;

    printf("Volume is: %.2f\n\n", volume); // %.2f = 2 decimal places
    return 0;
}
