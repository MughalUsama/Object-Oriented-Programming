#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "CString.h"

class Employee
{
private:
	CString empName;
	int number;
public:
	Employee();
	Employee(char *, int);
	~Employee();
	CString getName();
	int getNumber();
	void setName(char *);
	void setNumber(int);
	void displayEmployee();
};




#endif // !

