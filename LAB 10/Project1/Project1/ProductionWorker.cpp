#include "ProductionWorker.h"



ProductionWorker::ProductionWorker()
{
	this->shift = 1;
	this->hourlyPayRate = 0;
}

ProductionWorker::ProductionWorker(char * workerName, int workerNo, int shiftNo, double payRate):Employee(workerName,workerNo)
{
	if (shiftNo==1 || shiftNo==2)
	{
		this->shift = shiftNo;
	}
	else
	{
		this->shift = 1;
	}
	if (payRate>=0)
	{
		this->hourlyPayRate = payRate;
	}
	else
	{
		this->hourlyPayRate = -payRate;
	}

}



void ProductionWorker::setShift(int shiftNo)
{
	if (shiftNo==1 || shiftNo == 2)
	{
		this->shift = shiftNo;
	}
}

void ProductionWorker::setPayRate(double payRate)
{
	if (payRate >= 0)
	{
		this->hourlyPayRate = payRate;
	}
	else
	{
		this->hourlyPayRate = -payRate;
	}
}


int ProductionWorker::getShift()
{
	return shift;
}

double ProductionWorker::getPayRate()
{
	return hourlyPayRate;
}

ProductionWorker::~ProductionWorker() 
{
	this->shift = 0;
	this->hourlyPayRate = 0;
}

void ProductionWorker::displayWorker()
{
	this->displayEmployee();
	cout << "Shift no : " << this->shift << "\n";
	cout << "Hourly Pay Rate : " << this->hourlyPayRate << "\n";

}

