/*
 *           File-name:            Structure_C.c
 *
 *           Description:          C program for demonstrating input of values in a single line and declaring multiple structure variable in a 
				    single line.
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              Thursday,12th December, 2019 5:30 (PKT)
 *           Revision:             none
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 */

#include<stdio.h>
struct student
{
	int rollNo;
	char name[10];
	char ageDetailed[15];
};

int main(void)
{
	struct student s1, s2, s3;
	
	//defining defaults details for the struct student variable s4 and s5
	struct student s4={146,"Shahzad", "21-02-17"}, s5={145,"Kamil", "24-06-23"};
	
	//taking respective details from the user for the respective variable and saving them in the respective variables
	printf("Enter names (first name only): \n");
	scanf("%s %s %s", s1.name, s2.name, s3.name);
		
	printf("Enter respective roll numbers: \n");
	scanf("%d %d %d", &s1.rollNo, &s2.rollNo, &s3.rollNo);
	
	printf("Enter respective date of births (Years-Months-Days): \n");
	scanf("%s %s %s", s1.ageDetailed, s2.ageDetailed, s3.ageDetailed);
	
	//Printing Details for the variable s1
	printf("\nName: %s", s1.name);
	printf("\nRoll Number: %d", s1.rollNo);
	printf("\nDetailed Age: %s\n", s1.ageDetailed);


	//Printing Details for the variable s2
	printf("\nName: %s", s2.name);
	printf("\nRoll Number: %d", s2.rollNo);
	printf("\nDetailed Age: %s\n", s2.ageDetailed);


	//Printing Details for the variable s3
	printf("\nName: %s", s3.name);
	printf("\nRoll Number: %d", s3.rollNo);
	printf("\nDetailed Age: %s\n", s3.ageDetailed);


	//Printing Details for the variable s4
	printf("\nName: %s", s4.name);
	printf("\nRoll Number: %d", s4.rollNo);
	printf("\nDetailed Age: %s\n", s4.ageDetailed);

	//Printing Details for the variable s5
	printf("\nName: %s", s5.name);
	printf("\nRoll Number: %d", s5.rollNo);
	printf("\nDetailed Age: %s\n", s5.ageDetailed);
	
	return 0;
}
