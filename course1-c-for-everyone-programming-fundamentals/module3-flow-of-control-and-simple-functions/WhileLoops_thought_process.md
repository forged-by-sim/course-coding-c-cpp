

1.

while (i < 5){
    i = i – 1;
    printf(" i = %d", i);
}


If i starts off as 2 (assume int i = 2 declared at the beginning of the code) then...


Step-by-step:

i = 2

Loop condition: 2 < 5 → true

Inside loop: i = 2 - 1 = 1, prints i = 1

Next iteration: i = 1 → 1 < 5 → true

i = 0, print i = 0

i = -1, print i = -1

...

i keeps decreasing → always less than 5 → infinite loop

Correct answer: printf will print continuously



2.

while (i < 5){
    i = i – 1;
    printf(" i = %d", i);
}


If i starts off as 2 (assume int i = 2 declared at the beginning of the code) and the loop statement was i = i +1; printf will print ...


Step-by-step:

i = 2

i < 5 → true

i = 3, print i = 3

i = 4, print i = 4

i = 5, print i = 5

Now i = 5, loop condition 5 < 5 → false → loop ends

Correct answer: i = 3 i = 4 i = 5



3.

while (i < 5){
    i = i – 1;
    printf(" i = %d", i);
}


If i starts off as 15 (assume int i = 15 declared at the beginning of the code), printf will print ...


Step-by-step:

i = 15

15 < 5 → false

Loop never executes.

Correct answer: will not print






