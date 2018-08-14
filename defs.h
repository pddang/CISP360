
/*
 Define STR15 as array[1..15] of character
 Define STR10 as array[1..10] of character
 Define STR18 as array[1..18] of character
 Define EmployeeRecord as record
     Declare lastname as string
     Declare firstname as string
     Declare fullname as string
     Declare hour, payrate, fedtax,statetax, ssitax,reghrs,ovthrs, defr,gross, netpay as real
 end record
 
 */
typedef struct EmployeeRecord{
    float fedtax,statetax,ssitax,payRate,hours,reghrs,ovthrs,defr,gross, netPay;
	float regPay, ovtPay,totTax;
	int addressnum;
	char address1[10 + 1];
	char address2[10 + 1];
	char fullAddress[30];

	char city[8 + 1];
	char state[3 + 1];
	char cityState[11];

	int zipCode;
    char firstName[7+1];
    char lastName[8+1];
    char fullName[15+1];
	char fullName_f[15 + 1];
	char netPaystr[60];
}EmployeeRecord;
