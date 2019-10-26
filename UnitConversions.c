/*
 *           Filename:             UnitConversions.c
 *
 *           Description:          A simple program for converting values from one unit to another
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              26th October, 2019
 *           Revision:             none
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 *
 */
#include<stdio.h>
int main(void) {

    int choice;
    char userContinues;
    float value, convertedValue=0;
    
    do{
 system("clear");
 printf("\n<<<<<Welcome to the C Program for Unit Conversion!>>>>>\n\n");
 printf("Please proceed ahead by selecting an option for conversion of your data: \n");
 printf("Press 1 to convert units in \"Distance\"\n");
 printf("Press 2 to convert units in \"Weight\"\n");
 printf("Press 3 to convert units in \"Temperature\"\n");
 printf("Press 4 to convert units in \"Time\"\n");
 printf("Press 5 to convert units in \"Digital Storage\"\n");
 printf("Press 6 to convert units in \"Volume\"\n\n");
 printf("Your Choice: ");
 scanf("%d",&choice);

 if(choice==1) {
     system("clear");
     printf("<<<<<You've selected data conversion in terms of distance!>>>>>\n\n");
     printf("Press 1 to convert from kilometer to meter\n");
     printf("Press 2 to convert from meter to kilometer\n");
     printf("Press 3 to convert from meter to inches\n");
     printf("Press 4 to convert from inches to meter\n");
     printf("Press 5 to convert from inches to centimeter\n");
     printf("Press 6 to convert from centimeter to inches\n");
     printf("Enter your selection: ");
     scanf("%d",&choice);
     printf("Enter a value to convert: ");
     scanf("%f",&value);
     switch(choice) {
         case 1: convertedValue=value*1000;
         break;
         case 2: convertedValue=value/1000;
         break;
         case 3: convertedValue=value*39.37;
         break;
         case 4: convertedValue=value/39.37;
         break;
         case 5: convertedValue=value*2.54;
         break;
         case 6: convertedValue=value/2.54;
         break;
         default : printf("Wrong input in selection of choice!\n");
         break;
} //end switch

    printf("Converted value is: %.2f\n",convertedValue);
    printf("Do you wish to do another conversion? (Y or N): ");
    scanf(" %c",&userContinues);
 }//end else if
 
 else if(choice==2) {
    system("clear");
     printf("<<<<<You've selected data conversion in terms of Weight!>>>>>\n\n");
     printf("Press 1 to convert from pound to kilogram\n");
     printf("Press 2 to convert from kilogram to pound\n");
     printf("Press 3 to convert from kilogram to gram\n");
     printf("Press 4 to convert from gram to kilogram\n");
     printf("Enter your selection: ");
     scanf("%d",&choice);
     printf("Enter a value to convert: ");
     scanf("%f",&value);
     switch(choice) {
         case 1: convertedValue=value/2.205;
         break;
         case 2: convertedValue=value*2.205;
         break;
         case 3: convertedValue=value*1000;
         break;
         case 4: convertedValue=value/1000;
         break;
         default : printf("Wrong input in selection of choice!\n");
         break;
} //end switch

    printf("Converted value is: %.2f\n",convertedValue);
    printf("Do you wish to do another conversion? (Y or N): ");
    scanf(" %c",&userContinues);

 }//end else if

 else if(choice==3) {
    system("clear");
     printf("<<<<<You've selected data conversion in terms of Temperature!>>>>>\n\n");
     printf("Press 1 to convert from Fahrenheit to Celcius\n");
     printf("Press 2 to convert from Celcius to Fahrenheit\n");
     printf("Press 3 to convert from Celcius to Kelvin\n");
     printf("Press 4 to convert from Kelvin to Celcius\n");
     printf("Enter your selection: ");
     scanf("%d",&choice);
     printf("Enter a value to convert: ");
     scanf("%f",&value);
     switch(choice) {
         case 1: convertedValue=(value-32)*5/9;
         break;
         case 2: convertedValue=(value*9/5)+32;
         break;
         case 3: convertedValue=value+273.15;
         break;
         case 4: convertedValue=value-273.15;
         break;
         default : printf("Wrong input in selection of choice!\n");
         break;
} //end switch

    printf("Converted value is: %.2f\n",convertedValue);
    printf("Do you wish to do another conversion? (Y or N): ");
    scanf(" %c",&userContinues);
 }//end else if

 else if(choice==4) {
    system("clear");
     printf("<<<<<You've selected data conversion in terms of Time!>>>>>\n\n");
     printf("Press 1 to convert from Hour to Minute\n");
     printf("Press 2 to convert from Minute to Hour\n");
     printf("Press 3 to convert from Minute to Second\n");
     printf("Press 4 to convert from Second to Minute\n");
     printf("Enter your selection: ");
     scanf("%d",&choice);
     printf("Enter a value to convert: ");
     scanf("%f",&value);
     switch(choice) {
         case 1: convertedValue=value*60;
         break;
         case 2: convertedValue=value/60;
         break;
         case 3: convertedValue=value*60;
         break;
         case 4: convertedValue=value/60;
         break;
         default : printf("Wrong input in selection of choice!\n");
         break;
} //end switch

    printf("Converted value is: %.2f\n",convertedValue);
    printf("Do you wish to do another conversion? (Y or N): ");
    scanf(" %c",&userContinues);
 }//end else if
 
   else if(choice==5) {
    system("clear");
     printf("<<<<<You've selected data conversion in terms of Digital Storage!>>>>>\n\n");
     printf("Press 1 to convert from Terabyte to Gigabyte\n");
     printf("Press 2 to convert from Gigabyte to Terabyte\n");
     printf("Press 3 to convert from Gigabyte to Megabyte\n");
     printf("Press 4 to convert from Megabyte to Gigabyte\n");
     printf("Press 5 to convert from Megabyte to Kilobyte\n");
     printf("Press 6 to convert from Kilobyte to Megabyte\n");
     printf("Press 7 to convert from Kilobyte to Byte\n");
     printf("Press 8 to convert from Byte to Kilobyte\n");
     printf("Press 9 to convert from Byte to Bit\n");
     printf("Press 10 to convert from Bit to Byte\n");
     printf("Enter your selection: ");
     scanf("%d",&choice);
     printf("Enter a value to convert: ");
     scanf("%f",&value);
     switch(choice) {
         //1TB = 1024GB in binary
         case 1: convertedValue=value*1000;
         break;
         case 2: convertedValue=value/1000;
         break;
         case 3: convertedValue=value*1000;
         break;
         case 4: convertedValue=value/1000;
         break;
         case 5: convertedValue=value*1000;
         break;
         case 6: convertedValue=value/1000;
         break;
         case 7: convertedValue=value*1000;
         break;
         case 8: convertedValue=value/1000;
         break;
         case 9: convertedValue=value*8;
         break;
         case 10: convertedValue=value/8;
         break;
         default : printf("Wrong input in selection of choice!\n");
         break;
} //end switch

    printf("Converted value is: %.2f\n",convertedValue);
    printf("Do you wish to do another conversion? (Y or N): ");
    scanf(" %c",&userContinues);
 }//end else if
 
 else if(choice==6) {
     system("clear");
     printf("<<<<<You've selected data conversion in terms of Volume!>>>>>\n\n");
     printf("Press 1 to convert from Gallon to Cup\n");
     printf("Press 2 to convert from Cup to Gallon\n");
     printf("Press 3 to convert from Cup to Litre\n");
     printf("Press 4 to convert from Litre to Cup\n");
     printf("Press 5 to convert from Litre to mililitre\n");
     printf("Press 6 to convert from Mililitre to litre\n");
     printf("Enter your selection: ");
     scanf("%d",&choice);
     printf("Enter a value to convert: ");
     scanf("%f",&value);
     switch(choice) {
         case 1: convertedValue=value*16;
         break;
         case 2: convertedValue=value/16;
         break;
         case 3: convertedValue=value/3.52;
         break;
         case 4: convertedValue=value*3.52;
         break;
         case 5: convertedValue=value*1000;
         break;
         case 6: convertedValue=value/1000;
         break;
         default : printf("Wrong input in selection of choice!\n");
         break;
} //end switch
    printf("Converted value is: %.2f\n",convertedValue);
    printf("Do you wish to do another conversion? (Y or N): ");
    scanf(" %c",&userContinues);
 }//end else if
 
    
 
 else{
    printf("Wrong Input!!\n\nProgram will exit...\n");
    break;
}//end else

    printf("\nThank you for using this program!\n");
    }while(userContinues!='n'); //end do-while
}//end main
