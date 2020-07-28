#ifndef ODOMETER_H
#define ODOMETER_H

#include "FuelGauge.h"

class Odometer
{
private:
	double currentMileage;
	double previousMileage;
public:
	Odometer(int mile=0);
	~Odometer();
	double getMileage();
	void incrementMileage(FuelGauge &);
};

#endif