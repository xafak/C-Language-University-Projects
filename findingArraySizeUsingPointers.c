/*
 *           Filename:             findingArraySizeUsingPointers.c`
 *
 *           Description:          C program that shows that how can we find the array size by passing its address of initial and final 
 *                                 values to a function and then adding one to the final one and then subtracting final from initial.
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              23rd December, 2019 8:56 PM (PST)
 *           Revision:             none
 *
 *           @Author:              Sanzar Farooq (xafak) - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 */

#include<stdio.h>
#define SIZE 5
void findSize(int *const initial,int *const final);
int main(void)
{
    int a[SIZE]= {1,2,3,4,5};
    findSize(&a[0], &a[4]);
}
void findSize(int *const initial,int *const final)
{
    int size= (*final+1) - *initial;
    printf("\nInitial Value of the array's index is: %p (in hexadecimal), %d (in decimal)", *initial, *initial);
    printf("\nFinal Value of the array's index is: %p (in hexadecimal), %d (in decimal)", *final, *final);
    printf("\n(%p + 1) -%p = %p",*initial, *final,size);
    printf("\nAnd %p in decimal is: %d", size, size);
    printf("\nHence, the size of array is: %d\n", size);
}
