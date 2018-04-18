    /*
     Program: Assignment 2c- Payroll application
     Author: Phan Dang- CISP360-Sacramento City College-Spring 2018
     Purpose: Develop a C program for payroll application which prompts
     user to input: first name, last name, pay rate, hours, and defrered earning.
     The application will produce a report including gross pay, regular hours, overtime hours,
     federal taxes, statetaxes, SSI taxes, net pay. At the end of employee, the user is prompts
     whether he/she wants to input other employee. If the user answers no, the application will
     exit with the summary reports of the total and averages of inputs and outputs for all
     employees processed.
     -----------------------------------------------
     Date        Who            What
     3/22/2018    Phan        Main Module
     -----------------------------------------------
     Date design document
     Data Design
     --------------Hiearchy chart---------------------------
     3.0 Main Module
     3.1 PrintReportHeading(inout reportFile as file)
     3.2 InitializeAccumulators(out num_emps as integer, totreg, totovt, totpayrate, totgross,
     totfed, totstate, totssi, totderr,
     totnet as real)
     3.3 InputEmployeeData(out lastName, firstName as string.
     hours, payrate, defr as real)
     3.4 calcGross(in hours, payrate as real, out gross as real)
     3.5 void CalculateTaxes as float(in gross as real, in defr as real,
     out fedtax as real, out statetax as real, out ssitax as real)
     
     3.5.1 CalcFedtax(in gross as real,in defr as real,in FEDTAXRATE as constant, out fedtax as real);
     
     3.5.2 CalcStatetax(in fedtax as real, in STATETAXRARE as constant, out statetax as real)
     
     3.5.3 float CalcSSI(in gross as real, in SSITAXRATE as constant, in defr as real, out ssitax as real);)
     3.6 AddDetailToAccumulators(in reghrs, ovthrs, payrate, gross
     fed, state, ssi, defr, net as real,
     inout totreg, totovt, totpayrate, totgross,
     totfed, totstate, totssi, totdefr,
     totnet as real)
     3.7 PrintSummaryReport(inout reportFile as file,in totreg, totovt, totpayrate, totgross,
     totfed, totstate, totssi, totdefr,totnet as real, in numemps as integer)
     3.8 get_yesno(in question as string, out answer as string)
     */

    #include <stdio.h>
    #include "./PrintReportHeading.h"    //3.1 Print Report Headings
    #define SIZE 20                     //3.6 Add details to accumulators- Maximum data input accepted, to store in arrays.

//Main module
    extern void inputEmployeeData(char *firstName, char *lastName, float *payRate, float *hours, float *defr); // 3.3 Import Employee Data
    extern void calGross(float &hours, float &payRate, float *gross, float *reghrs, float *ovthrs);     //3.4 Calculate Gross Pay
    extern void calTaxes(float *gross, float *defr, float * fedtax, float * statetax, float * ssitax);  //3.5 Calculate Taxes
    extern float calFed(float *gross,float *defr); // 3.5.1 Federal Tax
    extern float calState(float *fedtax); // 3.5.2  State Tax
    extern float calSSI(float *gross, float *defr); // 3.5.3    SSI Tax
    extern char get_yesno(char question[25+1]);     //3.7.1 Get Yes/no answer


int main(void)

{
 
    
    //Variable delarations 3.1,3.3, 3.4,3.5
    float fedtax,statetax,ssitax,payRate,hours,reghrs,ovthrs,defr,gross, netPay;
    char firstName[8+1],lastName[8+1];
    // Variable declarations 3.2, 3.6, 3.7
    float totpayRate,totreghrs,totovthrs,totdefr,totgross,totnetPay,totft,totst,totssit;
    float fta[SIZE],sta[SIZE],ssita[SIZE],payRatea[SIZE],reghrsa[SIZE],
    ovthrsa[SIZE],defra[SIZE],grossa[SIZE], netPaya[SIZE];
    char firstNamea[SIZE][10];
    char lastNamea[SIZE][10];
    int num_emps;
    char question[25+1];
    int i;
    //3.2 Initialize the accummulators
    num_emps=0;totgross=0;totpayRate=0;totreghrs=0;
    totovthrs=0;totdefr=0;totnetPay=0;
    totft=0;totst=0;totssit=0;
    //---------------------------------------------------------------------------------------
    
    printf(WELCOMEMSG1);  //Welcome message
    do
    {
        inputEmployeeData(&firstName[0],&lastName[0],&payRate, &hours,&defr);   //3.3
        calGross(hours,payRate, &gross, &reghrs,&ovthrs);       //3.4
        calTaxes(&gross,&defr, &fedtax, &statetax, &ssitax);    //3.5
        netPay=gross-fedtax-statetax-ssitax-defr;               //Net Pay
        //3.7 Print Summary Report for one employee
        printf(REPLINE1);
        printf(REPLINE2);
        printf(REPLINE3);
        printf(REPFORMAT1,lastName,firstName,payRate,reghrs,gross,fedtax,ssitax,netPay);
        printf(REPFORMAT2,ovthrs,statetax,defr);
        //3.6 Add Detailed to Accumulators
        totreghrs=reghrs+totreghrs;totovthrs=ovthrs+totovthrs;
        totpayRate=payRate+totpayRate;totgross=gross+totgross;
        totft=fedtax+totft;totst=statetax+totst;totssit=ssitax+totssit;
        totdefr=defr+totdefr;
        totnetPay=netPay+totnetPay;
        for(i=0;i<10;i++){
        firstNamea[num_emps][i]=firstName[i];
        lastNamea[num_emps][i]=lastName[i];
        }
        ovthrsa[num_emps]=ovthrs;reghrsa[num_emps]=reghrs;
        payRatea[num_emps]=payRate;grossa[num_emps]=gross;
        fta[num_emps]=fedtax;sta[num_emps]=statetax;ssita[num_emps]=ssitax;
        defra[num_emps]=defr;
        netPaya[num_emps]=netPay;
        //
        num_emps=num_emps+1; 
        printf("Do you want to continue(Y/N)? ");
    } while(get_yesno(question)=='Y');
    //3.7 Print out report for all employees
    printf(REPLINE1);
    printf(REPLINE2);
    printf(REPLINE3);
    for(i=0;i<num_emps;i++){
    printf(REPFORMAT1,lastNamea[i],firstNamea[i],payRatea[i],reghrsa[i],grossa[i],fta[i],ssita[i],netPaya[i]);
    printf(REPFORMAT2,ovthrsa[i],ssita[i],defra[i]);
    }
    printf(REPFORMAT3,totpayRate,totreghrs,totgross,totft,totssit,totnetPay);
    printf(REPFORMAT4,totovthrs,totssit,totdefr);
    printf(REPFORMAT5,totpayRate/num_emps,totreghrs/num_emps,totgross/num_emps,totft/num_emps,totssit/num_emps,totnetPay/num_emps);
    printf(REPFORMAT6,totovthrs/num_emps,totssit/num_emps,totdefr/num_emps);
    
}
// 3.1 Read File from text

    
