#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(default:4996)  // Remove unsafe warning in Visual Studio

void convertNetPay(float netPay,char *netPaystr);


void convertNetPay(float netPay, char *netPaystr)
{
	//Declare table of strings
	 const char *OnesTable[] = { "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine" };

	const char *TeensTable[] = { "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

	 const char *tensTable[] = { "ten", "twenty", "thirty", "forty", "fifty",
		"sixty", "seventy", "eighty", "ninety" };
	  
	const char *tensPower[] = { "hundred", "thousand" };
	float cents;
	int numThousands,numHuns, numTens, numOnes,remainder;
	
	//Initialize the string
	//strcpy(fullName_f, firstName);
	//strcat(fullName_f, " ");
	//strcat(fullName_f, lastName);
	strcpy(netPaystr,"The sum of ") ;
	numHuns = netPay / 100; 
	numThousands = int(netPay) / 1000;
	if (numHuns > 0 && numHuns < 10) {
		strcat(netPaystr, OnesTable[numHuns - 1]);
		strcat(netPaystr, " ");
		strcat(netPaystr, tensPower[0]);
	}
	//else if (numThousands >0) printf("%s %s ", OnesTable[numThousands-1], tensPower[1]); 
	else strcat(netPaystr," ");
	//Consider remainder
	remainder = int(netPay) % 100;
	numTens = (int(netPay) % 100) / 10;
	numOnes = (int(netPay) % 100) % 10;
	//Case for hundreds
	if (remainder == 0) strcat(netPaystr, " ");
	else if (remainder > 10 && remainder < 20)
	{
		strcat(netPaystr, " ");
		strcat(netPaystr, TeensTable[remainder - 11]);
	}
	/*else if (remainder>=20 && remainder < 100) {
		printf("%s %s ", OnesTable[numThousands - 1], tensPower[0]);
		if (numTens > 0) printf("%s ", tensTable[numTens - 1]);
		if (numOnes > 0) printf("%s ", OnesTable[numOnes - 1]);
	}*/
	else
	{

		if (numTens > 0)
		{
			strcat(netPaystr, " ");
			strcat(netPaystr, tensTable[numTens - 1]);
			if (numOnes > 0)
			{
				strcat(netPaystr, " ");
				strcat(netPaystr, OnesTable[numOnes - 1]);
			}


		}
	}
	// Convert the cents into string
	cents = netPay - int(netPay);
	cents = cents + 0.005;
	cents = 100 * cents;
	int cenInt = int(cents);
	char centStr[5];
	sprintf(centStr, "%d", cenInt);
	strcat(netPaystr, " and ");
	strcat(netPaystr, centStr);
	strcat(netPaystr, "/100 Dollars ");
}