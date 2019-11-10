/*
 *           Filename:             FibonacciSequence.c
 *
 *           Description:          C program for printing Fibonacci sequence numbers uptill the number told by the user
 *
 *           Programming Language: C-Programming Language
 *
 *           Created:              10th November, 2019
 *           Revision:             none
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 */

#include<stdio.h>
int main(void) {
int valueToShow=0, valueToHold=1, valueToCalculate, numberOfTerms;

printf("How many terms of Fibonacci Sequence values you want to print?\n");
printf("You answer: ");
scanf("%d", &numberOfTerms);
printf("Numbers of Fibonacci Sequence uptill %d are: \n",numberOfTerms);

for(int i=1;i<=numberOfTerms;i++)
    {
        printf("%d ", valueToShow);

        valueToCalculate=valueToShow+valueToHold; //will calculate value for "valueToHold"

        valueToShow=valueToHold; //will hold the previous value of valueToHold

        valueToHold=valueToCalculate; //will save the newly calculated value
    }//end for
return 0;
} //end main
