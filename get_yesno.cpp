/*
 Program: Assignment2- Payroll application- Module 3.7.1 get_yesno
 Author: Phan Dang- CISP360-Sacramento City College-Spring 2018
 Purpose: ask user whether they want to continue to enter another input
//3.7.1. get_yesno(in question as string, out answer as string)
 -----------------------------------------------
 Date        Who            What
 3/22/2018    Phan       get_yesno.cpp
 3.7.1. get_yesno(in question as string, out answer as string)
 -----------------------------------------------
*/



#include <stdio.h>
char get_yesno(char question[25+1]);


char get_yesno(char question[25+1])
{
    char answer[1+1];
    do{
        printf("%s",question);
        scanf("%s",&answer[0]);
        if(answer[0] == 'y'){
            answer[0]='Y';
        }
        else if(answer[0]=='n'){
            answer[0]='N';
        }
        if(answer[0]!='Y'&&answer[0] !='N'){
            printf("Please type 'Y' for yes or 'N' for no\n");
        }
    }while(answer[0] != 'Y' && answer[0] !='N');
    return answer[0];
}
