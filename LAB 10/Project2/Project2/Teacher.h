#ifndef TEACHER_H
#define TEACHER_H

#include "Employee.h"
#include "Person.h"


class Teacher :public Employee, Person
{
private:
	int payScale;

public:
	Teacher();
	Teacher(char *, int, char*, double, int);
	~Teacher();
	void setPayscale(int);
	int getPayScale();
};

#endif