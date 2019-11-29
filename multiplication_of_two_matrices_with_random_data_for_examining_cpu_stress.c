/*
 *           Filename:             multiplication_of_two_matrices_with_random_data_for_examining_cpu_stress.c
 *
 *           Description:          C program for demonstrating the multiplication of two matrices, whose number of columns
 *                                 and rows are fixed the program will show their multiplication. 
 *                                 When the program is in running state the stress on cpu can be           
 *                                 examined using any process monitoring utility.
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              29th November, 2019 9:34 AM (PST)
 *           Revision:             none
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 */
#include<stdio.h>
#include<time.h>
int main(void)
{
    srand(time(NULL));//time seeds that are working as random seeds are provided to rand() function for generation of random numbers.
    //here 590 can be settted as the highest array size for the arrays with long integer as data type if it's increased to any number higher than it, it'll throw error code: "segmentation fault (core dumped)"
    long int userRowsA=590, userColumnsA=590;
    long int userRowsB=590, userColumnsB=590;
    long int row=0, col=0;
    long int i=0;//i variable will be used for counting the values of the resultant matrix
    
    long int matrixA[userRowsA][userColumnsA];
    long int matrixB[userRowsB][userColumnsB];
    long int matrixAnswer[userRowsA][userColumnsB];
    
    printf("<<<<<WELCOME DEAR USER TO MATRIX MULTIPLICATION OF RANDOMLY GENERATED VALUES!>>>>>\n");
    printf("\n***GENERATING RANDOM DATA FOR MATRICES AND MULTIPLYING THEM***\n");
    printf("\n***The data for matrices will be between 1 and 9223372036854775805***\n");
    

        //initializing all the elements of the matrixAnswer to zero
        for(row=0;row<userRowsA;row++)
        {
            for(col=0;col<userColumnsB;col++)
            {
                matrixAnswer[row][col]=0;
            }
        }
        
        //random and automated data entry for Matrix A
        for(row=0;row<userRowsA;row++)
            for(col=0;col<userColumnsA;col++){
                matrixA[row][col]=1 + rand() % 9223372036854775805;
        }
        //random and automated data entry for Matrix B
        for(row=0;row<userRowsB;row++)
            for(col=0;col<userColumnsB;col++) {
                 matrixB[row][col]=1 + rand() % 9223372036854775805;
            }
        
        //data calculation for matrixAnswer/resultant matrix
        for(row=0;row<userRowsA;row++)
        {
            for(col=0;col<userColumnsB;col++)
            {
                for(i=0;i<userColumnsA;i++) //or (i=0;i<userRowsB;i++) as they are both the same values (i.e. userColumnsA == userRowsB). This third loop is used for adding the number values, for the same reason all of its elements have been initialized to zero
                    matrixAnswer[row][col]+= matrixA[row][i]*matrixB[i][col];
            }
        }
        
        //now printing Matrix A, Matrix B and Matrix Answer one by one
        
        printf("<<<Matrix A>>>\n");
        for(row=0;row<userRowsA;row++)
        {
            for(col=0;col<userColumnsA;col++)
            {
                printf("%ld ", matrixA[row][col]);
            }
            printf("\n");
        }
        
        printf("\n<<<Matrix B>>>\n");
        for(row=0;row<userRowsB;row++) 
        {
            for(col=0;col<userColumnsB;col++) 
            {
                printf("%ld ",matrixB[row][col]);
            }
            printf("\n");
        }
        
        printf("\n<<<Matrix A x Matrix B>>>\n");
        for(row=0;row<userRowsA;row++)
        {
            for(col=0;col<userColumnsB;col++)
            {
                printf("%ld ",matrixAnswer[row][col]);
            }
            printf("\n");
        }
    
    return 0;
}//end main
