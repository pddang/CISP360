/*
 Program: Assignment2- Payroll application- Module 3.3 inPutEmployeeData
 Author: Phan Dang- CISP360-Sacramento City College-Spring 2018
 Purpose: Input Employee Data for application
 -----------------------------------------------
 Date        Who            What
 3/22/2018    Phan        3.3 inputEmployeeData
 3.3 InputEmployeeData(out lastName, firstName as string.
 hours, payrate, defr as real)
 */

#include <stdio.h>
void inputEmployeeData(char *firstName, char *lastName, float *payRate, float *hours, float *defr); // 3.3

//3.3 InputEmployeeData
void inputEmployeeData( char*firstName, char *lastName, float *payRate, float *hours, float *defr)
{
    
    
    printf(  "Please enter the employee's first name ==>");
    scanf("%s",firstName);
    printf(  "Please enter the employee's last name ==>");
    scanf("%s",lastName);
    printf(  "How many hours did this employee work? ==>");
    scanf("%f", hours);
    printf(  "What is the employee's payrate? ==>");
    scanf("%f", payRate);
    printf(  "What is the employee's deduction? ==>");
    scanf("%f", defr);
    
    
}
