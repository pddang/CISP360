    /*****************************************************************************************************
     Program: Payroll application                                                         *
     Author: Phan Dang                                      *
     Purpose: Develop a C program for payroll application which read a file inputs: first name,          *
     last name, pay rate, hours, and defrered earning.                                                   *
     The application will produce a report including gross pay, regular hours, overtime hours,           *
     federal taxes, statetaxes, SSI taxes, net pay through the employee data file.                       *
     The quicksort algorithm is implemented to sort all the employee alphabetically in last name.        *
     The application will also provide the summary reports of the total and averages of inputs and       *
     outputs for all employees processed.                                                                *
     -----------------------------------------------                                                     *
     Date        Who            What                                                                     *
     05/07/2018    Phan        Main Module                                                               *
     -----------------------------------------------                                                     *
     Data Design                                                                                         *                                                           *
     Define EmployeeRecord as record                                                                     *
		 Declare firstname, lastname, fullname,fullname_f
				 state, cityState, address1, address2, 
				 fulladdress,netPaystr as string
		 Declare city, addressnum,zipcode as integer
		 Declare hour, payrate, fedtax,statetax, ssitax,reghrs,
				 ovthrs, defr,gross, regPay, ovtPay netpay as real            *
     end record                                                                                          *
                                                                                                         *
     --------------Hiearchy chart-------------------------                                               *
     3.0 Main Module                                                                                     *
         3.1 PrintReportHeading(inout reportFile as file)                                                *
         3.2 InitializeAccumulators(out num_emps as integer, totreg, totovt, totpayrate, totgross,       *
         totfed, totstate, totssi, totderr,totnet as real)                                               *
         3.3 InputEmployeeData(out lastName, firstName as string,hours, payrate, defr as real)           *
            3.3.1 catName(in firstName, lastName as string, out fullName as string);                     *
			3.3.2 catName_f(in firstName, lastName as string, out fullName as string);                     *
         3.4 CalculateGross(in hours, payrate as real, out gross as real)                                *
         3.5 CalculateTaxes as float(in gross as real, in defr as real,                                  *
         out fedtax as real, out statetax as real, out ssitax as real)                                   *
            3.5.1 CalcFedtax(in gross as real,in defr as real,in FEDTAXRATE as constant,                 *
                             out fedtax as real);                                                        *
            3.5.2 CalcStatetax(in fedtax as real, in STATETAXRARE as constant, out statetax as real)     *
            3.5.3 float CalcSSI(in gross as real, in SSITAXRATE as constant,                             *
                                in defr as real, out ssitax as real)                                     *
         3.6 AddDetailToAccumulators(in reghrs, ovthrs, payrate, gross                                   *
         fed, state, ssi, defr, net as real, inout totreg, totovt, totpayrate, totgross,                 *
         totfed, totstate, totssi, totdefr, totnet as real)                                              *
         3.7 Quicksort by lastName(inout EmployeeRecord as record)										 *
		 3.8 PrintSummaryReport(inout reportFile as file,inout EmployeeRecord as record)  
		 3.9 PrintCheck(inout num_emps as integer, emps as EmployeeRecord,fullName as string,
						      netPaystr, address, city,state as string, zipcode as integer,
							  regpay, ovtpay,gross, netpay, fedtax, statetax, ssitax as real)
     *****************************************************************************************************/
	
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "./PrintReportHeading.h"
    #include "./defs.h"
	#include "./printCheck.h"
	#pragma warning(default:4996)
    #define SIZE 5
	#define WIDTH 60 //width of the paystub

    //3.1 Print Report Headings
    extern void calGross(float &hours, float &payRate,
                         float *gross, float *reghrs, float *ovthrs);      //3.4 Calculate Gross Pay
    extern void calTaxes(float *gross, float *defr, float * fedtax,
                         float * statetax, float * ssitax);               //3.5 Calculate Taxes
    void catName(char *, char *, char *) ;      //3.3.2 catName
    extern void Qsort(struct EmployeeRecord employee[], int start, int finish);//quicksort prototype
	extern char * generateRefCode(char * lastName, int chkNo);
	extern void convertNetPay(float netPay,char *netPaystr);

	void paddingStr(int targetStrlen, char *myString,const char * );
	void catName_f(char *, char *, char *); // first Name to last Name, without comma
	int main(void)

	{
		//Define structure
		EmployeeRecord emps[SIZE];
		//Variable declarations 3.2, 3.6, 3.7
		float totpayRate, totreghrs, totovthrs, totdefr, totgross, totnetPay, totft, totst, totssit;
		int num_emps;
		//attempt to read file
		FILE * inputFile = fopen("/Users/pddang/Desktop/Payroll/employees.dat", "r"); //open employees'data
		FILE *inputFile1= fopen("/Users/pddang/Desktop/Payroll/employeesinfo.dat", "r");//open employees' address
		FILE *inputFile2 = fopen("/Users/pddang/Desktop/Payroll/zipcode.dat", "r");//open employees' zipcode
		if (inputFile == NULL)
		{
			printf("File open failed... Terminating \n");
			exit(-100);

		}
		//3.1 Print Heading
		printf(SPACE);
		printf(WELCOMEMSG1);
		printf(SPACE);
		printf(REPLINE1);
		printf(REPLINE2);
		printf(REPLINE3);
		//3.2 Initialize the accummulators
		num_emps = 0;
		totgross = 0; totpayRate = 0; totreghrs = 0;
		totovthrs = 0; totdefr = 0; totnetPay = 0;
		totft = 0; totst = 0; totssit = 0;
		//3.3 Read Data From File
		
		
		do
		{
			
			for (int i = 0; i < SIZE; i++)
			{
				//Read all data 
				fscanf(inputFile, "%s %s %f %f %f \n",emps[i].firstName,
					emps[i].lastName, &emps[i].payRate, &emps[i].hours, &emps[i].defr);
				fscanf(inputFile1, "%d %s %s %s %s\n", &emps[i].addressnum, emps[i].address1,
					emps[i].address2, emps[i].city, emps[i].state);
				fscanf(inputFile2, "%d\n", &emps[i].zipCode);
				//Concatenate address together
				sprintf(emps[i].fullAddress, "%d", emps[i].addressnum);
				strcat(emps[i].fullAddress, " ");
				strcat(emps[i].fullAddress, emps[i].address1);
				strcat(emps[i].fullAddress, " ");
				strcat(emps[i].fullAddress, emps[i].address2);
				//Concatenate city and state together
				catName(emps[i].city, emps[i].state,emps[i].cityState);
				//3.4 Calculate Gross
				calGross(emps[i].hours, emps[i].payRate, &emps[i].gross,
					&emps[i].reghrs, &emps[i].ovthrs);     
				//3.5 Calculate Taxes
				calTaxes(&emps[i].gross, &emps[i].defr, &emps[i].fedtax,
					&emps[i].statetax, &emps[i].ssitax);  
				emps[i].netPay = emps[i].gross - emps[i].fedtax - emps[i].statetax -
					emps[i].ssitax - emps[i].defr;  
				convertNetPay(emps[i].netPay, emps[i].netPaystr);
				catName(emps[i].lastName, emps[i].firstName, emps[i].fullName);
				catName_f(emps[i].firstName, emps[i].lastName, emps[i].fullName_f);
				//Calculate regular pay and overtime pay for each employee
				emps[i].regPay = emps[i].reghrs*emps[i].payRate;
				emps[i].ovtPay = emps[i].ovthrs*emps[i].payRate*1.5;
				emps[i].totTax = emps[i].fedtax + emps[i].statetax + emps[i].ssitax;
				//increment to the next data
				num_emps = num_emps + 1;
				//3.6 Add Detailed to Accumulators
				totreghrs = emps[i].reghrs + totreghrs; totovthrs = emps[i].ovthrs + totovthrs;
				totpayRate = emps[i].payRate + totpayRate; totgross = emps[i].gross + totgross;
				totft = emps[i].fedtax + totft; totst = emps[i].statetax + totst;
				totssit = emps[i].ssitax + totssit;
				totdefr = emps[i].defr + totdefr;
				totnetPay = emps[i].netPay + totnetPay;

		}
	} while (!feof(inputFile));
	//3.8 Sort By Last Name
	Qsort(emps, 0, SIZE - 1);
	//3.7 Print out employee's report
	for(int i=0;i<SIZE;i++)
	{
	printf(REPFORMAT1,emps[i].fullName,emps[i].payRate,emps[i].reghrs,
			emps[i].gross,emps[i].fedtax,emps[i].ssitax,emps[i].netPay);
	printf(REPFORMAT2,emps[i].ovthrs,emps[i].statetax,emps[i].defr);
	}
	printf(REPLINE4);
	printf(REPFORMAT3,totpayRate,totreghrs,totgross,totft,totssit,totnetPay);
	printf(REPFORMAT4,totovthrs,totst,totdefr);
	printf(REPFORMAT5,totpayRate/num_emps,totreghrs/num_emps,totgross/num_emps,
			totft/num_emps,totssit/num_emps,totnetPay/num_emps);
	printf(REPFORMAT6,totovthrs/num_emps,totst/num_emps,totdefr/num_emps);
	fclose(inputFile);
	//3.8 Print check
	
		for (int i = 0; i < SIZE; i++)
		{
			//check no. start at 100
			int chkNo = 100;
			//printout formatting i.e. company info:
			printf(ASTERISK);
			printf(CHECKNO1, (chkNo + i));
			printf(BLANK);
			printf(COM1); printf(COM2); printf(COM3);
			printf(BLANK); printf(BLANK);
			printf(STRING1);
			printf(BLANK);
			//employee's name-reformatted.
			paddingStr(WIDTH+3, emps[i].fullName_f,"*\n");
			printf(BLANK);
			//3.8.1 convert Netpay and print within padding
			paddingStr(WIDTH+3, emps[i].netPaystr,"*\n");
			printf(BLANK); printf(BLANK);
			//3.8.2 generate reference code and print padding
			paddingStr(WIDTH+3,generateRefCode(emps[i].lastName,
							   (chkNo + i)),"*\n");
			printf(BLANK); printf(BLANK);
			printf(ASTERISK);
			printf(CHECKNO2, (chkNo + i));
			printf(BLANK);
			//3.8.3 print check stub
			paddingStr(WIDTH-42, emps[i].fullName, " ");
			printf(EMPSPRINT1, emps[i].regPay,emps[i].fedtax);
			paddingStr(WIDTH - 42, emps[i].fullAddress, " ");
			printf(EMPSPRINT2, emps[i].ovtPay, emps[i].statetax);
			paddingStr(WIDTH - 42, emps[i].cityState, " ");
			printf(EMPSPRINT3, emps[i].gross, emps[i].ssitax);
			printf(EMPSPRINT4, emps[i].zipCode, emps[i].netPay, emps[i].totTax);
			printf(BLANK); printf(BLANK);
			printf(ASTERISK);
		}
		
    } //Close tag for MAIN
	  
	  
//3.3.1 catName formatting: lastName, firstName
void catName(char *lastName, char *firstName, char *fullName)       
    {
        strcpy(fullName,lastName);
        strcat(fullName,",");
        strcat(fullName,firstName);
    }
//3.3.2 catName formatting: firstName lastName
void catName_f(char *firstName, char *lastName, char *fullName_f)     
{
	strcpy(fullName_f, firstName);
	strcat(fullName_f, " ");
	strcat(fullName_f, lastName);
}

//3.8.4 padding within margin
void paddingStr(int targetStrlen, char *myString, const char *padding)
{
//	int targetStrlen = 57;
	//const char *padding = " *\n";

	int padLen = targetStrlen - strlen(myString);
	if (padLen < 0) padLen = 0;
	printf("*      %s%*.*s", myString, padLen, padLen, padding);
	
	}

		

