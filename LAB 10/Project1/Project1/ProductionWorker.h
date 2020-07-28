#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H

#include "Employee.h"


class ProductionWorker:public Employee
{
private:
	int shift;
	double hourlyPayRate;
public:
	ProductionWorker();
	ProductionWorker(char *, int, int ,double);
	void setShift(int);
	void setPayRate(double);
	int getShift();
	double getPayRate();
	~ProductionWorker();
	void displayWorker();
};



#endif // !PRODUCTION_WORKER

