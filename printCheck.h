#pragma once
//3.8 Print Check Headers Format
//Purpose: this module print check required for each employee.
//Author: Phan Dang
//Date : 05/07/2018
//Format as below
//****************************************************************
//*								      Check No  100	     		 *
//B															     *
//*	Company Name									             *
//*	Address									                     *
//*	City, State, Zip								             *
//B											                     *
//B											                     *
//*	Pay to the Order of							                 *
//B											                     *
//*	Michael Dixon								                 *
//*					 						                     *
//*	The Sum Nine Hundred Ninety nine and XX/100 Dollars		     *
//B											                     *
//B											                     *
//*	Reference: DXN100								             *
//B											                     *
//B											                     *
//****************************************************************
//*	Check No  100								                 *
//B											                     *
//*	Employee'sName	Reg Pay			Fed Tax		                 *
//*	Address			Ovt Pay			State Tax		             *
//*	City, State		Gross Pay		SSI Tax			       		 *
//*	Zip			    Net Pay			Tax Total	                 *
//B											                     *
//B											                     *
//****************************************************************

#include <stdio.h>


#define ASTERISK "****************************************************************     \n"
#define CHECKNO1 "*                                         Check No %d              *\n"
#define BLANK    "*                                                                   *\n"
#define COM1     "*      Sabre Corporate                                              *\n"
#define COM2     "*      15790 West Henness Lane                                      *\n"
#define COM3     "*      New Corio, New Mexico  65790                                 *\n"
#define STRING1  "*      Pay to the Order of			                    *\n"
#define NAME     "*      %-s %-s                                                *\n"
#define REFNO    "*      Reference No. %d                                       "	
#define CHECKNO2 "*      Check No %d		                                    *\n"
#define EMPSPRINT1 "Reg.Pay  %6.2f     Fed.Tax   %6.2f       *\n"
#define EMPSPRINT2 "Ovt.Pay  %6.2f     State Tax %6.2f       *\n"
#define EMPSPRINT3 "Gross    %6.2f     SSI Tax   %6.2f       *\n"
#define EMPSPRINT4 "*      %-d	         Net Pay  %6.2f     Tax Total %6.2f       *\n"

