#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "CString.h"

class Employee
{
private:
	CString empName;
	double wage;
public:
	Employee();
	Employee(char *, int);
	~Employee();
	CString getEmployeeName();
	double getWage();
	void setEmployeeName(char *);
	void setWage(int);
	void displayEmployee();
};




#endif // !

