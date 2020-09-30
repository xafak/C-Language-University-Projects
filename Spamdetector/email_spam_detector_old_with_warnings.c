/*
 *           Filename:             email_spam_detector.c
 *
 *           Description:          C program for detecting spam domains in an e-mail (a text file in this case) againt
 * 			           some predefined spam domains (that are also defined in a text file in this case)
 * 				   defined in a blacklist text file.
 * 
 *           Programming Language: C-Programming Language
 *
 *           Created:              11th August, 2020 11:52 PM (PST)
 *           Revision:             none
 *
 *           @Author:              Sanzar Farooq (XaFaK) - sanzarfarooq01@gmail.com
 *           @Version:             5.8
 */

#include <stdio.h>
#include <string.h>

int chkArguments(char *email, char *blacklist);
int chkSpam(char *email, char *blacklist);
int checkCurrentWebsite(char websiteName[], char *email);
char *tokenizeAtPeriod(char string[]);

int main(int argc, char *argv[])
{
	int chkArg = 0;
	int chkMail = 0;
	switch (argc)
	{
	case 1:
	case 2:
		printf("\n This programs expects two arguments \n ");
		break;

	case 3:
		printf("\n arguments supplied %s and %s \n", argv[1], argv[2]);
		chkArg = chkArguments(argv[1], argv[2]);
		if (chkArg == 1)
		{
			printf("\n Ready to detect spam \n");
			chkMail = chkSpam(argv[1], argv[2]);

			if (chkMail == 0)
			{
				printf("\n email is a spam");
			}
			else
			{
				printf("\n email is not a spam");
			}
		}
		break;
	}
	return 0;
}

int chkArguments(char *email, char *blacklist)
{
	int returnValue = 1;
	FILE *fp, *fp2;
	fp = fopen(blacklist, "r");
	fp2 = fopen(email, "r");
	if (fp == NULL || fp2 == NULL)
	{
		printf("\n Cannot open one of the files %s %s \n", blacklist, email);
		returnValue = 0;
		if (fp != NULL)
			fclose(fp);
		if (fp2 != NULL)
			fclose(fp2);
	}

	return returnValue;
}

int chkSpam(char *email, char *blacklist)
{
	FILE *fp_blackList;
	fp_blackList = fopen(blacklist, "r");
	int i = 0;

	int NUMBER_OF_WEBSITES = 24;
	int MAX_CHARACTERS_IN_WEBSITE = 35;
	char websites[NUMBER_OF_WEBSITES][MAX_CHARACTERS_IN_WEBSITE];

	while (!feof(fp_blackList))
	{
		fgets(websites[i], MAX_CHARACTERS_IN_WEBSITE, fp_blackList);
		i++;
	}

	int websiteAvailable = 1;
	int spamStatus = 1;

	for (int i = 0; i < 25; i++)
	{
		websiteAvailable = checkCurrentWebsite(websites[i], email);
		if (websiteAvailable == 1)
		{
			spamStatus = 0;
			break;
		}
	}
	return spamStatus;
}

int checkCurrentWebsite(char websiteName[], char *email)
{
	char delimit[] = " \t\r\n\v\f";

	FILE *fp_email;
	fp_email = fopen(email, "r");

	int emailNotSpamFlag = 0;
	int email_content_size = 30;
	char email_content[email_content_size];
	while (!feof(fp_email))
	{
		fgets(email_content, 30, fp_email);

		char *tokenPtr;
		tokenPtr = strtok(email_content, delimit);

		while (tokenPtr != NULL)
		{

			//tokenPtr
			int lengthForTokenPtr = strlen(tokenizeAtPeriod(tokenPtr));
			char tokenPtrTokenized[lengthForTokenPtr];
			strcpy(tokenPtrTokenized, tokenizeAtPeriod(tokenPtr));

			//website
			int lengthForWebsite = strlen(tokenizeAtPeriod(websiteName));
			char websiteTokenized[lengthForWebsite];
			strcpy(websiteTokenized, tokenizeAtPeriod(websiteName));

			//checking for first occurrence of strings
			char *c = strstr(tokenPtrTokenized, websiteTokenized);
			if (c != NULL)
			{
				printf("[tokenPtrTokenized] %s\n", tokenPtrTokenized);
				printf("[websiteTokenized] %s\n", websiteTokenized);
				printf("[strstr] %s\n", c);

				return emailNotSpamFlag = 1;
			}
			tokenPtr = strtok(NULL, delimit);
		}
	}

	return emailNotSpamFlag;
}

char *tokenizeAtPeriod(char string[])
{
	char *tokenPtr;
	tokenPtr = strtok(string, ".");

	while (tokenPtr != NULL)
	{
		if ((strcmp("www", tokenPtr)) && (strcmp("com", tokenPtr)))
		{
			return tokenPtr;
		}
		tokenPtr = strtok(NULL, ".");
	}
}
