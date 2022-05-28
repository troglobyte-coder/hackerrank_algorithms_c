//
// HackerRank folio
// solved by Michael Gene Brockus
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//
// Should add the value of 'a' and 'b' and
// return the sum of two.
//
// arg-list:
//  -> a: first integer value being passed in
//  -> b: second integer value being passed in
//
int solveMeFirst(int a, int b)
{
    return a + b;
} // end of func

//
// main is where all C++ programs start
//
int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int sum; 
    sum = solveMeFirst(num1, num2);
    printf("%d", sum);
    return 0;
} // end of func
