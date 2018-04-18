/*
 Program: Assignment 2- Payroll application-Module 3.4
 Author: Phan Dang- CISP360-Sacramento City College-Spring 2018
 Purpose: Module 3.4 calGross- Calculate gross based on the user inputs. If the hours
 is less than or equal 40 hours, let gross pay equal pay rate time hours.If the hours
 over 40 hrs, overtime is counted as 1.5 times overtime hours times pay rate.

 3.4 calGross(in hours, payrate as real, out gross)
 -----------------------------------------------
 Date        Who            What
 3/22/2018    Phan        3.4 calGross
 3.4 calcGross(in hours, payrate as real, out gross as real)

 */
#include <stdio.h>

void calGross(float &hours, float &payRate, float *gross, float *reghrs, float *ovthrs);



//3.4 Calculate Gross
void calGross(float &hours, float &payRate, float *gross, float *reghrs, float *ovthrs)
{
    if(hours<=40){
        
        *reghrs=hours;
        *ovthrs=0;
        *gross=payRate*hours;
        
    }
    else if(hours>40){
        *reghrs=40;
        *ovthrs=hours-40;
        *gross=payRate*40+1.5*payRate**ovthrs;
        
    }
}
