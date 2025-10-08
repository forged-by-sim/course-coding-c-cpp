#include <stdio.h>
#include <math.h>  /* fabs() works for double values */

int main(void)
{
    double interval;
    int i;

    for (i = 0; i < 30; i++)
    {
        interval = i / 10.0;
        printf("sin(%4.1f) = %6.3f \t fabs(sin(x)) = %6.3f\n", interval, sin(interval), fabs(sin(interval)));
    }

    printf("\n++++++++++\n");
    return 0;
}
