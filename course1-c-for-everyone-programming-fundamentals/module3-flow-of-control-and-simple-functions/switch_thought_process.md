
switch(i){



       case 1: printf(“case 1 \n”); break;

       case 2: printf(“case 2 \n”); 

       case 3: printf(“case 3 \n”);break;

       default: printf(“default case \n”);

      }; 

  Use the code above for all of the questions.


1. If i starts off as 1 then printf will print

Step-by-step
If i = 1
case 1: 
    printf("case 1 \n"); 
    break;


Only case 1 runs.

It prints case 1.

It does not fall through because of the break.

Correct answer: case 1



2. If i starts out as  15  the printf will print  

Step-by-step
If i = 15

There’s no case 15, so it goes to default:

default: 
    printf("default case \n");

Correct answer: default case



3. If i starts out as  2   the printf will print

Step-by-step
If i = 2
case 2: 
    printf("case 2 \n"); 
case 3: 
    printf("case 3 \n");
    break;


case 2 matches.

No break after case 2, so it falls through to case 3.

Both print.

Correct answer: case 2 case 3

