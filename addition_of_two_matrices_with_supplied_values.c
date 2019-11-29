/*
 *           Filename:             addition_of_two_matrices_with_supplied_values.c
 *
 *           Description:          C program for showing the addtion of two matrices that have been already declared and 
 *                                 initialzied to a value. This program will add the two declared matrices and show the 
 *                                 outputed in a proper formated way.
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              29th November, 2019 7:40 PM (PST)
 *           Revision:             none
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 */
#include<stdio.h>
int main(void)
{
    int matrixA[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matrixB[3][3]={{9,8,7},{6,5,4},{3,2,1}};
    int matrixSum[3][3];
    int row, col;
    
    //adding the values of the 2 matrices and saving them in the third matrix i.e. matrixSum
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++)
        {
            matrixSum[row][col]=matrixA[row][col]+matrixB[row][col];
        }
    }
    
    //printing the values of all the matrices in formated order
    printf("Sum of matrices is: \n");
    printf("    A     +    B    =    SUM\n");
    for(row=0;row<3;row++)
    {
        for(col=0;col<3;col++) 
            printf("%2d ",matrixA[row][col]);
            
            printf("  ");
        
        for(col=0;col<3;col++)
            printf("%2d ",matrixB[row][col]);
        
            printf("  ");
        
        for(col=0;col<3;col++)
            printf("%2d ",matrixSum[row][col]);
        
        printf("\n");
        
    }//end for (row) loop
    
    return 0;
    
}//end main function
