#include "Employee.h"
#include <iostream>
using namespace std;


Employee::Employee()
{
	this->number = 0;
}

Employee::Employee(char * name, int no) :empName(name)
{
	if (no>=0)
	{
		this->number = no;
	}
	else
	{
		this->number = -no;
	}

}


Employee::~Employee()
{
	this->empName.~CString();
	this->number = 0;
}

CString Employee::getName()
{
	return this->empName;
}

int Employee::getNumber()
{
	return this->number;
}

void Employee::setName(char * name)
{
	this->empName = name;
}

void Employee::setNumber(int no)
{
	this->number = no;
}

void Employee::displayEmployee()
{
	cout << "Employee name: " << this->empName <<"\n" ;
	cout << "Employee no: " << this->number << "\n";
}
