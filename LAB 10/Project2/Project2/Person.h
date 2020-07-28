#ifndef PERSON_H
#define PERSON_H

#include "CString.h"


class Person
{
private:
	CString name;
	int age;

public:
	Person();
	~Person();
	Person(char *, int );
	CString getName();
	double getAge();
	void setName(char *);
	void setAge(int);
	void displayPerson();
};
#endif 
