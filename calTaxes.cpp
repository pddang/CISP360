
/*
 Program: Assignment2- Payroll application- Module 3.5 calTaxes
 Author: Phan Dang- CISP360-Sacramento City College-Spring 2018
 Purpose:Federal Tax, State Tax, SSI Tax deducted from gross pay.
 -----------------------------------------------
 Date        Who            What
 3/22/2018    Phan        3.5 calTaxes.cpp
 
3.5 void CalculateTaxes as float(in gross as real, in defr as real,
                    out fedtax as real, out statetax as real, out ssitax as real)

    3.5.1 CalcFedtax(in gross as real,in defr as real,in FEDTAXRATE as constant, out fedtax as real);
	
    3.5.2 CalcStatetax(in fedtax as real, in STATETAXRARE as constant, out statetax as real)

    3.5.3 float CalcSSI(in gross as real, in SSITAXRATE as constant, in defr as real, out ssitax as real);)
	
	
*/
#include <stdio.h>
#include "./myTaxes.h"
void inputEmployeeData(char *firstName, char *lastName, float *payRate, float *hours, float *defr); // 3.3
void calGross(float *hours, float *payRate, float *gross, float *reghrs, float *ovthrs);//3.4

void calTaxes(float *gross, float *defr, float * fedtax, float * statetax, float * ssitax);
float calFed(float gross,float defr); // 3.5.1
float calState(float fedtax); // 3.5.2
float calSSI(float gross, float defr); // 3.5.3



void calTaxes(float *gross, float *defr, float * fedtax, float * statetax, float * ssitax)
{
   *fedtax = calFed(*gross,*defr); // call 3.5.1
   *statetax = calState(*fedtax); // call 3.5.2
   *ssitax = calSSI(*gross,*defr); // call 3.5.3
}
float calFed(float gross,float defr) // 3.5.1
{
  return (gross-defr) * FEDTAXRATE;
}
float calState(float fedtax) // 3.5.2
{
  return (fedtax * 0.07);
}
float calSSI(float gross, float defr) // 3.5.3
{
  return (gross-defr) * SSITAXRATE;
}

