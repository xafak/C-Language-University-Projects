/*
 *           Filename:             multiplication_of_two_matrices.c
 *
 *           Description:          C program for demonstrating the multiplication of two matrices, whose number of columns
 *                                 and rows will be entered by the user and the program will show it the original matrices 
 *                                 and their multiplication.
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              29th November, 2019 2:12 AM (PST)
 *           Revision:             second
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 * 
 *           Note:                 Detailed comments have been provided to facilitate reader with the functionality of the      
 *                                 program.
 */
 #include<stdio.h>
int main(void)
{
    int userRowsA=0, userColumnsA=0;
    int userRowsB=0, userColumnsB=0;
    int row=0, col=0;
    int i=0;//i variable will be used for counting the values of the resultant matrix
    
    printf("<<<<<WELCOME DEAR USER TO MATRIX MULTIPLICATION!>>>>>\n");
    
    //entering data for number of rows and columns for Matrix A
    printf("Enter number of rows for matrix A: ");
    scanf("%d",&userRowsA);
    printf("Now enter number of columns for matrix A: ");
    scanf("%d",&userColumnsA);
    
    //entering data for number of rows and columns for Matrix B
    printf("Enter number of rows for matrix B: ");
    scanf("%d", &userRowsB);
    printf("Now enter number of columns for matrix B: ");
    scanf("%d",&userColumnsB);
   
    //checking for matrix mutiplication validity
    if(userColumnsA==userRowsB)
    {
        //the reason behind declaring these arrays here is that it will store and show values correctly after the variables have been initialized to an accurate value. As I have tried many times declaring it above but it shows inaccurate value there so it has been declared here.
        int matrixA[userRowsA][userColumnsA];
        int matrixB[userRowsB][userColumnsB];
        int matrixAnswer[userRowsA][userColumnsB]; //we've assigned these values to the resultant array because according to the rule of matrix multiplication, the number of rows of the first matrix will always be the same as the columns of the seond matrix so, hence they are used here in the same way.
        
        //initializing all the elements of the matrixAnswer to zero
        for(row=0;row<userRowsA;row++)
        {
            for(col=0;col<userColumnsB;col++)
            {
                matrixAnswer[row][col]=0;
            }
        }
        
        system("clear");
        printf("Matrices successfully qualify for multiplication!\n");
        printf("Commencing Data entry for: \n");
        
        //data entry for Matrix A
        printf("***Matrix A***\n");
        for(row=0;row<userRowsA;row++)
            for(col=0;col<userColumnsA;col++){
                printf("Enter data for A[%d][%d]: ", row,col);
                scanf("%d", &matrixA[row][col]);
        }
        
        //data entry for Matrix B
        system("clear");
        printf("Commencing Data entry for: \n");
        printf("***Matrix B***\n");
        for(row=0;row<userRowsB;row++)
            for(col=0;col<userColumnsB;col++) {
                printf("Enter data for B[%d][%d]: ", row,col);
                scanf("%d", &matrixB[row][col]);
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
        system("clear");
        
        printf("<<<Matrix A>>>\n");
        for(row=0;row<userRowsA;row++)
        {
            for(col=0;col<userColumnsA;col++)
            {
                printf("%d ", matrixA[row][col]);
            }
            printf("\n");
        }
        
        printf("\n<<<Matrix B>>>\n");
        for(row=0;row<userRowsB;row++) 
        {
            for(col=0;col<userColumnsB;col++) 
            {
                printf("% d",matrixB[row][col]);
            }
            printf("\n");
        }
        
        printf("\n<<<Matrix A x Matrix B>>>\n");
        for(row=0;row<userRowsA;row++)
        {
            for(col=0;col<userColumnsB;col++)
            {
                printf("%d ",matrixAnswer[row][col]);
            }
            printf("\n");
        }
        
    }//end if
    else
        printf("\nSorry matrices do not qualify for multiplication, hence you cannot continue...\n");
    
    return 0;
}//end main
