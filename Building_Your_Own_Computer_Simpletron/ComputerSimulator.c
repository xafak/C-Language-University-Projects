/*
 *           Filename:             ComputerSimulator.c
 *
 *           Description:          C program for software-based simulation for creating Simpletron
 *
 *           Programming Language: C-Programming Language
 *
 *           Created:              23rd January, 2019 7:45 pm (PST)
 *           Revision:             0.5
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 *	    
 * 	     Note:		   THIS PROGRAM IS STILL IN DEVELOPMENT STAGE
 */
#include<stdio.h>

//I/O Operations
#define READ       10
#define WRITE      11
//Load/Store Operations
#define LOAD       20
#define STORE      21
//Arithmetic Operations
#define ADD        30
#define SUBTRACT   31
#define DIVIDE     32
#define MULTIPLY   33
//Transfer of control Operations
#define BRANCH     40
#define BRANCHNEG  41
#define BRANCHZERO 42
#define HALT       43

#define MEMORY_SIZE 100
#define SENTINEL   -99999
#define TRUE 1; //will be used for FATAL execution
#define FALSE 0;

void loadProg(int *memory);
void executeProg(int *memory, int *acmltrPtr, int *insCounPtr, int *oprtnCodPtr, int *oprndPtr, int *insRegPtr);
int wordInRange(int instruction);
void dump( int *memory, int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand );


int main(void)
{
    //variables
    int memory[MEMORY_SIZE];
    int accumulator=0; //representing the accumulator register
    int instructionCounter=0; //for keeping track of the instruction's location in memory, instruction that is being performed
    //instructionCounter is also used as a transfer of control
    int operationCode=0; //for indicating the operation being performed(the first two numbers in WORD)
    int operand=0;//for indicating the memory location on which the operation is being performed (the last two numbers in WORD)
    int instructionRegister=0; //instruction to be executed next from memory array will be transferred here first and then ran
    int i;
   

    //first initializing all the elements of the memory array to 0
    for(i=0;i<MEMORY_SIZE;i++)
        memory[i] = 0;
    
    loadProg(memory);
    executeProg(memory, &accumulator, &instructionCounter, &operationCode, &operand,&instructionRegister);
    dump(*memory,accumulator, instructionCounter, instructionRegister, operationCode, operand);

    return 0;
}//end function main

void loadProg(int *memory)
{
    long int currentInstruction=0; //for storing the current instruction
    int i=0; //for counter-controlled loop 

      printf("\n*** Welcome to Simpletron! ***\n"
    "*** Please enter your program one instruction  ***\n"
    "*** (or data word) at a time. I will type the ***\n"
    "*** location number and a question mark (?)    ***\n"
    "*** You then type the word for that location.  ***\n"
    "*** Type the sentinel -99999 to stop entering  ***\n"
    "*** your program. ***\n");

    

    //taking instructions from user and storing them in array memory

    printf("00 ? ");
    scanf("%ld",&currentInstruction);
   
    while(currentInstruction!=SENTINEL)
    {
        if(!wordInRange(currentInstruction))
            printf("\nPlease re-enter the number in the range between -99999 and 99999");
        else
            memory[i++] = currentInstruction;

        printf("\n%02d ? ",i);
        scanf("%ld",&currentInstruction);
    }//end while

 printf("\n*** Program loading completed ***\n");

}//end function loadProg

void executeProg(int *memory, int *acmltrPtr, int *insCounPtr, int *oprtnCodPtr, int *oprndPtr, int *insRegPtr)
{
    int fatal=FALSE; //initially initialized to 0 i.e. FALSE
    int temp; //will be used for temporary storage and later for validation of data
    int i;
    printf("*** Program execution begins ***\n");
    //now program execution begins
    
    //first we'll separate the operation code and*oprndPtr as instructed
    *insRegPtr = memory[*insCounPtr];
    *oprtnCodPtr = *insCounPtr/100;
    *oprndPtr = *insRegPtr%100;
    

    /* now determining what the instruction code is (like if it's READ, WRITE etc. as defined)
    using the switch statement
    we'll be using the while statement and will make sure that the opeartion code is not halt or fatal*/
    while(*oprtnCodPtr!=HALT && !fatal)
    {
        switch(*oprtnCodPtr)
        {
            case READ://for taking input from terminal and saving it in array memory
                printf("Enter an integer: ");
                scanf("%d",&temp);

                while(!wordInRange(temp)) //check if this line is fine
                {
                    printf("nPlease re-enter the number in the range between -99999 and 99999");
                    scanf("%d",&temp);
                }
            
                memory[*oprndPtr] = temp;
                (*insCounPtr)++; //used as a transfer of control
                break;
       
            case WRITE:
                printf("\nMemory at %d contains: %d",*oprndPtr,memory[*oprndPtr]);
                (*insCounPtr)++;
                break;
     
            case LOAD:
                *acmltrPtr=memory[*oprndPtr];
                (*insCounPtr)++;
                break;
       
            case STORE:
                memory[*oprndPtr]=*acmltrPtr;
                (*insCounPtr)++;
                break;
       
            case ADD:
                temp = *acmltrPtr+memory[*oprndPtr]; /*here we're adding value present in *acmltrPtr with 
                                                //the value stored in memory and then keeping it in variable temp*/
                if(!wordInRange(temp))
                {
                    printf("\n*** FATAL ERROR: Value in *acmltrPtr out of range!!! ***");
                    printf("\n*** Simpletron execution abnormally terminated ***");
                    fatal = TRUE;
                }
                else
                {
                    *acmltrPtr=temp; //else *acmltrPtr will store the new value 
                    (*insCounPtr)++;
                }
                break;
       
                case SUBTRACT: 
                temp = *acmltrPtr-memory[*oprndPtr];
                if(!wordInRange(temp))
                {
                    printf("\n*** FATAL ERROR: Value in *acmltrPtr out of range!!! ***");
                    printf("\n*** Simpletron execution abnormally terminated ***");
                    fatal = TRUE;
                }
                else
                {
                    *acmltrPtr=temp; 
                    (*insCounPtr)++;
                }
                break;
       
                case DIVIDE: //in this case we'll be checking if 0 is stored in the very specific memory location
                if(memory[*oprndPtr] == 0)
                {
                    printf("\n*** Attempt to divide by zero ***");
                    printf("\n*** Simpletron execution abnormally terminated ***");
                    fatal = TRUE;
                }
                else
                {
                    *acmltrPtr=temp; 
                    (*insCounPtr)++;
                }
                break;
       
                case MULTIPLY:
                    temp=*acmltrPtr*memory[*oprndPtr];
            
                if(!wordInRange(temp))
                 {
                    printf("\n*** FATAL ERROR: Value in *acmltrPtr out of range!!! ***");
                printf("\n*** Simpletron execution abnormally terminated ***");
                fatal = TRUE;
            }
            else
            {
                *acmltrPtr=temp; 
                (*insCounPtr)++;
            }
            break;
       
        case BRANCH: //case used for moving to a certain memory location
                     //in this case we're required store*oprndPtr's value in *insCounPtr as
                     //*insCounPtr stores the value of the instruction's location in memory
            *insCounPtr=*oprndPtr;
            break;
       
        case BRANCHNEG: //for checking if *acmltrPtr has a negative value in it
            if(*acmltrPtr<0)
                *insCounPtr=*oprndPtr;
            else
                (*insCounPtr)++;
            break;
       
        case BRANCHZERO: //for checking if *acmltrPtr has 0 value stored in it
            if(*acmltrPtr==0)
                *insCounPtr=*oprndPtr;
            else
                (*insCounPtr)++;
            break;
       
        case HALT:
            printf("\n*** Simpletron execution terminated ***\n");
            break;

        default://in case of operation codes entered without those that are pre-defined
            printf("\n*** FATAL ERROR: Invalid Operation Code Detected ***");
            printf("\n*** Simpletron execution abnormally terminated ***");
            fatal = TRUE;
            break; //optional to put break here

        //again making next operation's code ready by seperating its operation and operation code;

        *insRegPtr=memory[*insCounPtr];
        *oprtnCodPtr=*insCounPtr/100;
        *oprndPtr=*insRegPtr%100;
        
    }
    printf("\n*** END SIMPLETRON EXECUTION ***");
}//end function execProg

void dump( int *memory, int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand )
{
    int i; /* counter */
    printf( "\n%s\n%-23s%+05d\n%-23s%5.2d\n%-23s%+05d\n%-23s%5.2d\n%-23s%5.2d",
    "REGISTERS:", "accumulator", accumulator, "instructioncounter",
    instructionCounter, "instructionregister", instructionRegister,
    "operationcode", operationCode, "operand", operand );
    printf( "\n\nMEMORY:\n" );
    
    /* print column headers */
    for ( i = 0; i <= 9; i++ ) {
    printf( "%5d ", i );
    } /* end for */
    
    /* print row headers and memory contents */
    for ( i = 0; i < MEMORY_SIZE; i++ ) {
    
    /* print in increments of 10 */
    if ( i % 10 == 0 ) {
    printf( "\n%2d ", i );
    } /* end if */
    printf( "%+05d ", memory[ i ] );
    } /* end for */
}

int wordInRange(int instruction)
{
    return instruction>=-9999 && instruction<=9999;
}
