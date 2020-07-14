/*
 *           Filename:             strong_password_validation.c
 *
 *           Description:          C program for validating a character array by checking for its 
 *                                 length and then using pre-defined functions to determine that whether
 *                                 it has a character, a number and a special symbol.
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              14th July, 2020 2:55 PM (PST)
 *           Revision:             none
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.0
 */
#include<stdio.h>
#include<ctype.h>

int length(char array[]);
int strongpwd(char array[]);

int main()
{

    char password[]="123456";
    char password2[]="qwerty";
    char password3[]="qwerty123";
	char password4[]="14July_2020!";

  printf("\n1. Length of password:\t %s is %d", password, length(password));
  printf("\n2. Length of password2:\t %s is %d", password2, length(password2));
  printf("\n3. Length of password3:\t %s is %d", password3, length(password3));
  printf("\n4. Length of password4:\t %s is %d", password4, length(password4));


  printf("\n1. Strength of password:\t %s is %d", password, strongpwd(password));
  printf("\n2. Strength of password2:\t %s is %d", password2, strongpwd(password2));
  printf("\n3. Strength of password3:\t %s is %d", password3, strongpwd(password3));
  printf("\n4. Strength of password4:\t %s is %d", password4, strongpwd(password4));



	printf("\n");
	return 0;
}

int strongpwd(char array[])
{
 
    int count = 0;

    int strong = 0;
    int arraySize = 0;
    
    int hasCharacter = 0;
    int hasNumber = 0;
    int hasSpecialSymbol = 0;
	
	int checkForCharacter = 1;
	int checkForNumber = 1;
	int checkForSpecialSymbol = 1;

	arraySize = length(array);

	if(arraySize>=8) {
        while(array[count] != '\0') {
           if(checkForNumber) {
			    if(isdigit(array[count])) {
                hasNumber = 1;
				checkForNumber = 0;
            } 
		   }
           if(checkForCharacter) {
			    if(isalpha(array[count])) {
                hasCharacter = 1;
				checkForCharacter = 0;
            }
		   }
           if(checkForSpecialSymbol) {
			    if(ispunct(array[count])){
                hasSpecialSymbol = 1;
				checkForSpecialSymbol = 0;
            }
		   }
            count++;
        }
        if(hasNumber && hasCharacter && hasSpecialSymbol) {
            strong = 1;
        }
    }
   return strong;
}

int length(char array[])
{
	int length=0;
	int count=0;

	while(array[count] != '\0')
	{
		length++;
		count++;
	}

	return length;
}
