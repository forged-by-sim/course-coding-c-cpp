1. True: switch is a reserved keyword in C and many other programming languages.


2. False: printf is a standard library function, not a keyword.


3. False:  || is the logical OR operator; the address operator is &.


4. False: EOF (End Of File) is a macro constant, not a keyword.


5. False: malloc is not an operator — it’s a function (from <stdlib.h>) used to dynamically allocate memory in C.


6. 
typedef enum choices { left, left_center = 2, right_center, right = 5 } choices;

Step-by-step:

left → The first enumerator with no assigned value starts at 0 by default.
left = 0

left_center = 2 → Explicitly assigned.
left_center = 2

right_center → Gets the next integer value after left_center, so
right_center = 3

right = 5 → Explicitly assigned.
right = 5

Final Answers:

left → 0

right_center → 3



7.
#include<stdio.h> 
int main() 
{ 
 int a = 2, b = 5, c = 8; 
 printf(" a && b = %d \n ", a && b); 
 printf(" b %% a = %d \n ", b % a ); 
 printf(" a / b = %d \n " , a/b); 
 printf(" 2 * a + 1 < b = %d \n ", 2*a + 1 < b); 
 printf(" b <= c = %d \n " , b<= c);


8. a && b

Both a and b are non-zero, so logical AND (&&) gives 1.
Result: 1


9. b % a

5 % 2 = 1 (remainder when 5 is divided by 2).
Result: 1


10. a / b

Integer division: 2 / 5 = 0 (since result is truncated).
Result: 0


11. 2 * a + 1 < b

2 * 2 + 1 = 5 → 5 < 5 → false (0)
Result: 0


12. b <= c

5 <= 8 → true (1)
Result: 1


13. !!c

c = 8 → first !c = 0 (since 8 is non-zero)
then !!c = 1
Result: 1


14. c > 2 && a > 6

c > 2 → 8 > 2 → true (1)

a > 6 → 2 > 6 → false (0)

1 && 0 → 0
Result: 0


15.  b == 2 || a != 4

b == 2 → false (0)

a != 4 → true (1)

0 || 1 → 1
Result: 1


16.  (a + b) * c--

(a + b) = 2 + 5 = 7

c-- uses current value (8), then decrements c to 7 after evaluation.

Result = 7 * 8 = 56
Result: 56
(Now c = 7 after this line.)


17. c = ++b

++b increments b to 6, then assigns that to c.

So b = 6, c = 6
Result: 6


18. The sqrt() function returns?

sqrt(x) computes the square root of x.

It returns a double value (floating-point).

Answer: A value of type double



19. The rand() function is declared in?

The rand() function is used to generate pseudo-random numbers.

It is declared in the <stdlib.h> header file.

Answer: <stdlib.h>


20. The malloc() function returns?

malloc() dynamically allocates memory.

It returns a pointer to void (void *), which can be typecast to any other pointer type.

Answer: A void pointer (void *)


21. The array declaration double data[5][4]; will allocate storage for?

This is a 2D array with 5 rows and 4 columns.

Total elements = 5 × 4 = 20

Each element is of type double.

Answer: Storage for 20 elements of type double


22. 
enum myfoods { butter = 2, milk = 5, cheese = 8, eggs };

butter = 2

milk = 5

cheese = 8

eggs has no explicit value, so it takes the next integer value after cheese, which is 8 + 1 = 9.

Answer: eggs = 9



23. 
struct complex { 
    double real;  
    double imaginary;
} c1 = { 1.5, -2.0 }, c2; 

struct complex *ptr_c = &c1;


ptr_c points to c1. So c1.real can also be accessed using the arrow operator via the pointer ptr_c->real or equivalently using dereferencing (*ptr_c).real



24. The precedence of the operator -> is?

The arrow operator (->) is used for member access through a pointer.

It has very high precedence, the same as the dot (.) operator.

It ranks above arithmetic, relational, and logical operators, just below function calls and array subscripts.



25. Finding the kth element in an array vs. a linear list

Array:
Accessing the kth element is O(1) (constant time) because of direct indexing using memory offsets.

Linear list (linked list):
Accessing the kth element requires traversing from the head node to the kth node — O(k) time.

Correct answer: the array element look-up is faster by approximately some proportion to k



26. 

int mystery(LINK head)
{
    if (head == NULL)
        return 0;
    else
        return (1 + count(head -> next));
}


Let’s analyze:

It checks if head is NULL, then returns 0.

Otherwise, it returns 1 + count(head->next).

The function count() here is likely intended to be mystery() itself (a recursive call).
If that’s just a naming typo, the intent is clear — it recursively counts nodes in a linked list until the end (NULL) is reached.



27. 

FILE *ofp;
fopen("temp", "w+");


The string "temp" represents the filename.

When no path is given, it refers to a file in the current (local) working directory.

The mode "w+" means:

Open for reading and writing.

If the file doesn’t exist, create it.

If it exists, its contents are erased (truncated).

Correct Answer: temp is a file in the local directory



29. In C++ which keyword has a significantly different meaning than in C?

In C,

The keyword auto specifies automatic storage duration, meaning the variable is stored on the stack.

However, this is the default behavior, so auto in C is rarely used and has no practical effect.

auto int x = 5;  // same as just int x = 5;


In C++ (since C++11),

auto has a completely different and powerful meaning — it tells the compiler to deduce the variable’s type automatically from its initializer.

auto x = 5;        // x is int
auto y = 3.14;     // y is double
auto p = new int;  // p is int*



30.
In the conversion specification 
%6lf 
The 6 means

In the format specifier:

%6lf



lf → specifies a double type (long float) in printf or scanf.

6 → minimum field width. This means the output will take at least 6 spaces, padding with spaces if necessary.

Important notes:

It does not set precision (number of digits after the decimal).

It does not mean 6 arguments or significant figures.

For precision (decimal places), you would use:

%.6lf   // 6 digits after decimal



