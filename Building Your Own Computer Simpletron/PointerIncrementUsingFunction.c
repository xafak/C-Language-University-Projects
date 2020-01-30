/*
 *           Filename:             ComputerSimulator.c
 *
 *           Description:          C program for demonstrating how increment on a pointer works when it's sent to another function
 *
 *           Programming Language: C-Programming Language
 *
 *           Created:              22nd January, 2020 03:30 pm (PST)
 *           Revision:             2nd
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.2
 *	    
 */


#include<stdio.h>
void testFunction(int *number);
void incrementFunction(int *num);
int main(void)
{
    int a, *aPtr;
    int b, *bPtr;
    a = 5;
    aPtr = &a;

    b = 8;
    bPtr = &b;

    printf("\nValue of a is: %d\n"
    "Value of aPtr is: %d\n", a, *aPtr);
   
    printf("\nValue of b is: %d\n"
    "Value of bPtr is: %d\n", b, *bPtr);
   
    incrementFunction(aPtr);
    incrementFunction(bPtr);
    printf("\nIncremented value of aPtr is: %d\n",*aPtr);
    printf("Incremented value of b is: %d\n",b);
    return 0;
}
void incrementFunction(int *num)
{
    (*num)++;
}
