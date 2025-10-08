

#include <stdio.h>


#include <stdlib.h>


int main(void)
{
    int a = 0, b = 1, c = 2;

    if (a < b) printf("TRUE\n"); else printf("FALSE\n");

    if (a < b - c) printf("TRUE\n"); else printf("FALSE\n");

    if (b < c - 1) printf("TRUE\n"); else printf("FALSE\n");

    if (!c) printf("TRUE\n"); else printf("FALSE\n");
      return 0;
}

   

1. Step-by-step

a < b

0 < 1

Correct answer: True


2. Step-by-step

a < b - c

0 < 1 - 2 

0 < -1

Correct answer: False 


3. Step-by-step

b < c - 1 

1 < 2 - 1 

1 < 1

Correct answer: False 


4. Step-by-step

!c

!2

!0 is 1 (true) 
! of any non-zero number (like 2) is 0 (false) 

Correct answer: False 

