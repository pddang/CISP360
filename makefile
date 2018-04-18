
cgross.o:	main.cpp calGross.cpp 
	g++ -c	calGross.cpp -o cgross.o
ctax.o:		main.cpp calTaxes.cpp  myTaxes.h 
	g++ -c	calTaxes.cpp -o ctax.o
m.exe:		main.cpp PrintReportHeading.h get_yesno.cpp cgross.o ctax.o
	g++  	inputEmployeeData.cpp main.cpp get_yesno.cpp cgross.o ctax.o -o m.exe

