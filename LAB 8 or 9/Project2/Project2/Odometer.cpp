#include "Odometer.h"
#include "FuelGauge.h"

Odometer::Odometer(int mile)
{
	if (mile>= 0 && mile<=999999)
	{
		this->currentMileage = mile;
	}
	else
	{
		this->currentMileage = 0;
	}
	this->previousMileage = this->currentMileage;
}


Odometer::~Odometer()
{
	this->currentMileage = 0;
	this->previousMileage = 0;
}

double Odometer::getMileage()
{
	return this->currentMileage;
}

void Odometer::incrementMileage(FuelGauge &fg)
{
	if (this->currentMileage<999999)
	{
		this->currentMileage = this->currentMileage + 1;
		if ((this->currentMileage-this->previousMileage)==24 || (this->currentMileage+this->previousMileage-this->previousMileage+1)==24)
		{
			fg.decrementFuel();
			this->previousMileage = this->currentMileage;
		}
	}
	else
	{
		this->currentMileage = 0;
	}
}


