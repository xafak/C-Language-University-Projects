/*
 *           Filename:             findingMaxAndMinIntegerValuesOfIntDataType.c
 *
 *           Description:          C program for demonstrating the maximum positive and negative integer value that can be
 *                                 stored in "int" data type
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              10th November, 2019
 *           Revision:             none
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 * 
 *           Note:                 Please keep in mind that when you've compiled and ran this program it'll take few seconds 
 *                                 for calculation.
 */

#include<stdio.h>
int main(void) {
int testValue_positive=0;
int testValue_negative=0;
int maxValue=0;
int minValue=0;
char ch ='y';
while(ch=='y')
    {
        testValue_positive+=1;
        testValue_negative-=1;
        
        //test for +ve value
        if(testValue_positive>maxValue)
            maxValue=testValue_positive;
        
        //test for -ve value
        if(testValue_negative<minValue)
            minValue=testValue_negative;
        
        if(testValue_negative>0) //used for breaking the loop when testValue_negative approaches 0;
            break;
    }//end while
printf("Maximum Positive value that can be stored in \"Integer Data Type\" is: %d\n",maxValue);
printf("Minimum Negative value that can be stored in \"Integer Data Type\" is: %d\n",minValue);
return 0;
}//end main
