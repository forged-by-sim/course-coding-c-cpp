
1. Assume i = 1; j = 2;  

n = (i < j);


Steps:
(i < j) evaluates to true (because 1 < 2).

In C/C++, true is represented by 1, and false is 0.

Correct answer: n is 1



2. Assume i = 1; j = 2;  

n = (i == j)? 4:(i < j)?3:5;


Steps:
i == j is false, so we go to the else part.

Now we evaluate: (i < j) ? 3 : 5;

i < j is true, so result is 3

Correct answer: n is 3



3. Assume i = 1; j = 2;  

n = (i, j);  


Steps:
This uses the comma operator, which evaluates both expressions left to right, but returns the value of the last one.

So (i, j) → evaluates i (1), then evaluates j (2), returns 2.

Correct answer: n is 2



4. Assume i = 1; j = 2;  

n = i, j+1;  


Steps:
Operator precedence matters here. 

Assignment (=) has higher precedence than the comma operator.

So this is interpreted as (n = i), (j + 1);

First n = i; → n = 1

Then j + 1; is evaluated (but discarded)

Final value of n is still 1

Correct answer: n is 1



5. Assume i = 1; j = 2;  

n = (i < j)? 4: 6; 


Steps:
i < j is true, so we take the first option, which is 4

Correct answer: n is 4



