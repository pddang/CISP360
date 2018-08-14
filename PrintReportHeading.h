/*
  Program:  3.1 PrintReportHeading
  Purpose: Print out the headings for the application including
  welcome messages, titles, format for the outputs
  -----------------------------------------------
  Date        Who            What
  4/1/2018    Phan        3.1 PrintReportHeading
  -----------------------------------------------
  3.1 PrintReportHeading(inout reportFile as file)
  
  */

#include <stdio.h>

#define WELCOMEMSG1 "  -------------------Welcome to your Payroll Application--------------------------------\n"
#define SPACE       "                                                                                        \n"
#define REPLINE1    " Employee            Pay        Reg hrs       Gross         Fed          SSI           Net\n"
#define REPLINE2    "     Name           rate        Ovt hrs         Pay       State         Defr           Pay\n"
#define REPLINE3    " ========          =====          =====     =======      ======       ======        ======\n"
#define REPLINE4    "----------------------------------------------------------------------------------------\n"
#define REPFORMAT1 " %-15s%8.2f       %8.2f    %8.2f    %8.2f     %8.2f      %8.2f\n"
#define REPFORMAT2 "                               %8.2f                %8.2f     %8.2f                \n"
#define REPFORMAT3 "Totals          %8.2f       %8.2f    %8.2f    %8.2f     %8.2f      %8.2f\n"
#define REPFORMAT4 "                               %8.2f                %8.2f     %8.2f                \n"
#define REPFORMAT5 "Averages        %8.2f       %8.2f    %8.2f    %8.2f     %8.2f      %8.2f\n"
#define REPFORMAT6 "                               %8.2f                %8.2f     %8.2f                \n"

