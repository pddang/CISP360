cgross.o:	main.cpp calGross.cpp 
	g++ -c	calGross.cpp -o cgross.o
ctax.o:		main.cpp calTaxes.cpp  myTaxes.h 
	g++ -c	calTaxes.cpp -o ctax.o
m.exe:		main.cpp cgross.o ctax.o PrintReportHeading.h defs.h printCheck.h employees.dat employeesinfo.dat 
	g++  	main.cpp sortbyLastname.cpp convertNetpay.cpp GenRef.cpp cgross.o ctax.o -o m.exe

