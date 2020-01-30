/*
 *           Filename:             Simulation_The_Tortoise_And_The_Hare.c
 *
 *           Description:          C Program for simulating the race of Tortoise and the Hare
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              17th January, 2020 7:40 PM (PST)
 *           Revision:             Fourth
 *
 *           @Author:              Sanzar Farooq - sanzarfarooq01@gmail.com
 *           @Version:             1.4
 */

#include<stdio.h>
#include<time.h>

#define RACE_END 70

void moveTortoise(int *tortoise);
void moveHare(int *hare);
void printCurrentPositions(int const *tortoise, int const *hare); //the pointers in this method are declared constant because we don't want their values changed
/*
//for global scope of the variable
int tortoise=1; // toroise's position
int hare=1; // hare's position
long int timer=0; // clock ticks elapsed
*/
int main(void)
{

    srand(time(NULL)); 

	int tortoise=1; // toroise's position
	int *tortoisePtr; 
	tortoisePtr = &tortoise;
	int hare=1; // hare's position
	int *harePtr;
	harePtr= &hare;
	long int timer=0; // clock ticks elapsed
    
	puts( "BANG !!!!!\n" );
	puts( "AND THEY'RE OFF !!!!!\n" );
	while ( tortoise != RACE_END && hare != RACE_END )
		{
			moveHare(harePtr);
			moveTortoise(tortoisePtr);
			printCurrentPositions(tortoisePtr,harePtr);

			/*slow down the program by making some useless calculation to make system busy
			increase or decrease the variable temp value as desired for fast and slow program execution  
			use he value 999999999 for examining CPU Stress */
			for ( long temp = 0; temp < 999999999; temp++ ); //the semicolon in the end is must as it's a loop intended for only making system busy
			++timer;
		} // end while
		
    // tortoise beats hare or a tie
	if ( tortoise >= hare )
		printf( "\nTORTOISE WINS!!! YAY!!!\n" );
	// hare beat tortoise
	else
		printf( "\nHare wins. Yuch!\n" );
	
	printf("\nTIME ELAPSED = %ld seconds\n",timer);
		
	return 0;
	}//end function main()
	
	
	
// move tortoise's position
void moveTortoise(int *tortoise)
	{
		//these addition of numbers is basically the addition of blocks to the record
		//that each of these animals have covered
		//as the total number of blocks are 70
		
		// randomize move to choose
		int percent = 1 + rand() % 10;//for generating random number between 1 and 10 as for under 100%;
		
		// determined moves as guided
		
		// fast plod
		if ( percent >= 1 && percent <= 5 )
			*tortoise += 3;
		
		// slip
		else if ( percent == 6 || percent == 7 )
			*tortoise -= 6;
		
		// slow plod (30% of time)
		else
			++(*tortoise);
		
		// ensure tortoise doesn't slip beyond start position
		if ( *tortoise < 1 )
			*tortoise = 1;
		
		// ensure tortoise doesn't pass the finish
		else if ( *tortoise > RACE_END )
			*tortoise = RACE_END;
} // end function moveTortoise()
	
// move hare's position
void moveHare(int *hare)
		{
		
		// randomize move to choose
		int percent = 1 + rand() % 10;//for generating random number between 1 and 10;
		
		// big hop means between 30% and 40% 
		if ( percent == 3 || percent == 4 )
		*hare += 9;
		
		// big slip 
		else if ( percent == 5 )
		*hare -= 12;
		
		// small hop means between 60% and 80%
		else if ( percent >= 6 && percent <= 8 )
		++(*hare);
		
		// small slip
		else if ( percent == 10 )
		*hare -= 2;
		
		// ensure that hare doesn't slip beyond start position
		if ( *hare < 1 )
		*hare = 1;
		
		// ensure hare doesn't pass the finish
		else if ( *hare > RACE_END )
		*hare = RACE_END;
} // end function moveHare()
	
	
// display positions of tortoise and hare
void printCurrentPositions(int const *tortoise, int const *hare)
		{
		printf("Race Progress: ");
		// goes through all 70 squares, printing H
		
		// if hare on position and T for tortoise

		//in the following for loop we're not using any brace
		//because when else if statements are used in with if
		//then it'll automatically test those cases
		//this can be tried by simply replacing else if with only if statements
		for ( int count = 1; count <= RACE_END; count++ )
		
		// tortoise and hare positions collide
		if ( count == *tortoise && count == *hare )
		puts( "OUCH!!!" );
		
		//hare here means the number of steps that are covered by hare and the 
		//number that is stored in this variable in each run, this is how we'll get to know its
		//position
		else if ( count == *hare )
		//putchar('H');
		putchar('H');
		
		//tortoise here means the number of steps that are covered by tortoise and the 
		//number that is stored in this very variable in each run, this is how we'll get to know its
		//position
		else if (count == *tortoise)
		putchar('T');

		
		else
		putchar('.');

		
		printf("\n");
}//end function printCurrentPositions()

