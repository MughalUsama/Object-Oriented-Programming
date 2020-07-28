#include "Employee.h"
#include <iostream>
using namespace std;


Employee::Employee()
{
	this->wage = 0;
}

Employee::Employee(char * name, int empwage) :empName(name)
{
	if (empwage >= 0)
	{
		this->wage = empwage;
	}
	else
	{
		this->wage= -empwage;
	}
}


Employee::~Employee()
{
	this->empName.~CString();
	this->wage = 0;
}

CString Employee::getEmployeeName()
{
	return this->empName;
}

double Employee::getWage()
{
	return this->wage;
}

void Employee::setEmployeeName(char * name)
{
	this->empName = name;
}

void Employee::setWage(int empwage)
{
	if (empwage >= 0)
	{
		this->wage = empwage;
	}
	else
	{
		this->wage = -empwage;
	}
}

void Employee::displayEmployee()
{
	cout << "Employee name: " << this->empName << "\n";
	cout << "Wage: " << this->wage << "\n";
}
