/*
 *           Filename:             Trignometric_functions.c
 *
 *           Description:          C program for calculating values of the angles present in the trignometric table, i.e.
 *                                 0,30,45,60,90. All of these irregular data are customly feeded into 2D Arrays and are            
 *                                 further read from there.
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              8th December, 2019 2: 41 AM (PST)
 *           Revision:             5th
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.5
 * 
 *           Note:                 The program has been reviewed many times because of inaccurate created values. But at
 *                                 present all the values are accurately calculated.
 *                                  
 *                                 For linux users it is advised to use "-lm"  to link with the math library in the step 
 *                                 where you are attempting to generate your executable.
 */



#include<stdio.h>
#include<math.h> //will be used for using sqrt() function and trignometric ratio functions

void drawTable(void); //function for drawing the entire trignometric ratios table

float trig_calculate(char str[10] , int angle); 

float degreeToRadian(double degree) //function for converting the provided degrees into radians for trignometric functions calculation
{
    //its necessary to seperately calculate them or else it'll calculate inaccurate value
    float answer = (degree * 22/7);
    return answer/180;
}

int main(void)
{
    int angle=0;
    int prog_mode_choice=0;
    char prog_run_choice='n';
    char str[10];
    do{
        system("clear");
        printf("<<< Welcome Dear User for calclating trignometric ratios! >>>\n");
        printf("*** Press 1 for calculating a single value using your desired trignometric function ***\n");
        printf("*** Press 2 to view the entire table of trignometric functions ***\n");
        printf("You choice: ");
        scanf("%d", &prog_mode_choice); 
        
        if(prog_mode_choice==1)
        {
            printf("Enter any one trignometric function name from below:");
            printf("\n sin\n cos\n tan\n cosec\n sec\n cot\n");
            printf("Enter your trignometric function name: ");
            scanf("%s", str);//we're using scanf() function here for string because our provided string doesn't have spaces so for this purpose it can be used or else we'd have used gets() or fgets()
            
            printf("\nEnter the angle (must be 0,30,45,60,90): ");
            scanf("%d", &angle);
            
            if(angle==0 || angle==30 || angle==45 || angle==60 ||  angle==90)
            {
               printf("%s of %d is: %.3f\n",str, angle, trig_calculate(str,angle));
            }//end if
            
            else
                printf("\nAngle entered is out of range!!");
        }//end if
        
        else if(prog_mode_choice==2)
            drawTable();
        
        else
            printf("\nIncorrect choice selected!!!");
        
        printf("\nDo you want to run the program again? (Y or N)");
        printf("\nYour decision: ");
        scanf(" %c", &prog_run_choice);
        
    }while(prog_run_choice=='y'|| prog_run_choice=='Y');
        
    printf("\nThank you...");
    
}//end main function

//function for calculation of the trignometric value
float trig_calculate(char str[10], int angle)
{
    /*In this step we cannot use any loop for direct data entry into the arrys because we're feeding irregular data into the arrays, so, 
    row 0 = sin,
    row 1 = cos, 
    row 2 = tan, 
    row 3 = cosec, 
    row 4 = sec, 
    row 5 = cot,
    column 0 = 0 , 
    column 1 = 30, 
    column 2 = 45, 
    column 3 = 60, 
    column 4 = 90 
    */
    float trig_values[6][5];
    int ratio_number=0;
    int angle_number=0;
    /*
    it must be kept in mind that all the programming languages takes input in the form of radian which is why it's necessary to provide values in the form of radians to get accurate answers. For this purpose we'll be converting values into radians using our defined function
    it'll give us the answers as if they were calculated in the form of degrees
    
    */
    
        trig_values[0][0]=sin(degreeToRadian(0));
        trig_values[0][1]=sin(degreeToRadian(30));
        trig_values[0][2]=sin(degreeToRadian(45));
        trig_values[0][3]=sin(degreeToRadian(60));
        trig_values[0][4]=sin(degreeToRadian(90));
        
        //values for cos from 0 degree to 90 degree
        trig_values[1][0]=cos(degreeToRadian(0));
        trig_values[1][1]=cos(degreeToRadian(30));
        trig_values[1][2]=cos(degreeToRadian(45));
        trig_values[1][3]=cos(degreeToRadian(60));
        trig_values[1][4]=cos(degreeToRadian(90));    
        
        //values for tan from 0 degree to 90 degree
        trig_values[2][0]=tan(degreeToRadian(0));
        trig_values[2][1]=tan(degreeToRadian(30));
        trig_values[2][2]=tan(degreeToRadian(45));
        trig_values[2][3]=tan(degreeToRadian(60));
        trig_values[2][4]=tan(degreeToRadian(90));
        
        //values for cosec from 0 degree to 90 degree
        trig_values[3][0]=1/sin(degreeToRadian(0));
        trig_values[3][1]=1/sin(degreeToRadian(30));
        trig_values[3][2]=1/sin(degreeToRadian(45));
        trig_values[3][3]=1/sin(degreeToRadian(60));
        trig_values[3][4]=1/sin(degreeToRadian(90));
        
        //values for sec from 0 degree to 90 degree
        trig_values[4][0]=1/cos(degreeToRadian(0));
        trig_values[4][1]=1/cos(degreeToRadian(30));
        trig_values[4][2]=1/cos(degreeToRadian(45));
        trig_values[4][3]=1/cos(degreeToRadian(60));
        trig_values[4][4]=1/cos(degreeToRadian(90));
        
        //values for cot from 0 degree to 90 degree
        trig_values[5][0]=1/tan(degreeToRadian(0));
        trig_values[5][1]=1/tan(degreeToRadian(30));
        trig_values[5][2]=1/tan(degreeToRadian(45));
        trig_values[5][3]=1/tan(degreeToRadian(60));
        trig_values[5][4]=1/tan(degreeToRadian(90));
        
        
        //following steps made for the purpose of accurately moving through array elements
        if(strcmp(str,"sin")==0)
            ratio_number=0;
        
         if(strcmp(str,"cos")==0)
            ratio_number=1;
        
         if(strcmp(str,"tan")==0)
            ratio_number=2;
        
         if(strcmp(str,"cosec")==0)
            ratio_number=3;
        
         if(strcmp(str,"sec")==0)
            ratio_number=4;
        
         if(strcmp(str,"cot")==0)
            ratio_number=5;
        
       if(angle==0)
           angle_number=0;
       if(angle==30)
           angle_number=1;
       if(angle==45)
           angle_number=2;
       if(angle==60)
           angle_number=3;
       if(angle==90)
           angle_number=4;
       
       return trig_values[ratio_number][angle_number];
}//end function trig_calculate

void drawTable(void)
{
    system("clear");
    printf("\n"
    " _____________________________________________________________________________\n"
    "|            |            |            |            |            |            |\n"
    "|   Angles   |            |            |            |            |            |\n" 
    "|     in     |     00     |     30     |     45     |     60     |     90     |\n"
    "| Degrees(x) |            |            |            |            |            |\n"
    "|____________|____________|____________|____________|____________|____________|\n"
    "|            |            |            |            |            |            |\n"
    "|   sin x    |     01     |     1/2    | sqrt(2)/2  |  sqrt(3)/2 |     01     |\n"
    "|____________|____________|____________|____________|____________|____________|\n"
    "|            |            |            |            |            |            |\n"
    "|   cos x    |     01     | sqrt(3)/2  | sqrt(2)/2  |     1/2    |     00     |\n"
    "|____________|____________|____________|____________|____________|____________|\n"
    "|            |            |            |            |            |            |\n"
    "|   tan x    |     00     | sqrt(3)/3  |     01     |   sqrt(3)  |  undefined |\n"
    "|____________|____________|____________|____________|____________|____________|\n"
    "|            |            |            |            |            |            |\n"
    "|   csc x    |  undefined |     02     |   sqrt(2)  | 2*sqrt(3)/3|     01     |\n" 
    "|____________|____________|____________|____________|____________|____________|\n"
    "|            |            |            |            |            |            |\n"
    "|   sec x    |     01     | 2*sqrt(3)/3|   sqrt(2)  |     02     |  undefined |\n"
    "|____________|____________|____________|____________|____________|____________|\n"
    "|            |            |            |            |            |            |\n"
    "|   cot x    |  undefined |   sqrt(3)  |     01     |  sqrt(3)/3 |     00     |\n"
    "|____________|____________|____________|____________|____________|____________|\n");
    }//end function drawTable
