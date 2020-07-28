#include "Teacher.h"



Teacher::Teacher()
{
	this->payScale = 0;
}

Teacher::Teacher(char *pName, int pAge, char * eName, double wage, int scale):Employee(eName,wage),Person(pName,pAge)
{
	if (scale>=0)
	{
		this->payScale = scale;
	}
	else
	{
		this->payScale = -scale;
	}
}


Teacher::~Teacher()
{
	this->payScale = 0;
}

void Teacher::setPayscale(int scale)
{
	if (scale >= 0)
	{
		this->payScale = scale;
	}
	else
	{
		this->payScale = -scale;
	}
}

int Teacher::getPayScale()
{
	return this->payScale;
}

