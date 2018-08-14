#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning(default:4996)  // Remove unsafe warning in Visual Studio

#define TRUE 1
#define FALSE 0
typedef short BOOLEAN;

char * generateRefCode(char * lastName,int chkNo);
BOOLEAN isVowel(char aChar);


char * generateRefCode(char * lastName,int chkNo)
{
	static char tempStrf[30 + 1];
	static char tempStr[30 + 1];
	int i,j = 1;
	
	tempStr[0] = lastName[0];
	for (i=1; i < strlen(lastName);i++)
	  if (!isVowel(lastName[i])) tempStr[j++] = lastName[i];
	tempStr[j] = 0; // add string terminator
	 char chkStr[10];
	sprintf(chkStr, "%d", chkNo);
	strcpy(tempStrf, "Reference:  ");
	strcat(tempStrf, tempStr);
	strcat(tempStrf, chkStr);
	return tempStrf;
}

BOOLEAN isVowel(char aChar)
{
	switch (toupper(aChar)) //<ctype.h>
	{
	  case 'A':
	  case 'E':
	  case 'I':
	  case 'O':
	  case 'U' : return TRUE;break;
	  default: return FALSE;
	}
}