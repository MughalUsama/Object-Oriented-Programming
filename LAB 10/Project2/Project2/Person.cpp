#include "Person.h"

Person::Person()
{
	this->age = 0;
}


Person::Person(char *personName, int personAge):name(personName)
{
	if (personAge >= 0)
	{
		this->age = personAge;
	}
	else
	{
		this->age = -personAge;
	}
}




Person::~Person()
{
	this->name.~CString();
	this->age = 0;
}

CString Person::getName()
{
	return this->name;
}

double Person::getAge()
{
	return this->age;
}

void Person::setName(char * pName)
{
	this->name = pName;

}

void Person::setAge(int pAge)
{
	if (pAge >= 0)
	{
		this->age = pAge;
	}
	else
	{
		this->age = -pAge;
	}
}

void Person::displayPerson()
{
	cout << "Person name : " << this->name << "\n";
	cout << "Person age : " << this->age << "\n";
}
