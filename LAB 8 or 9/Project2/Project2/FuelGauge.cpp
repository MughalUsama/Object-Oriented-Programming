#include "FuelGauge.h"


FuelGauge::FuelGauge(int fuel)
{
	if (fuel<=15 && fuel >= 0)
	{
		this->currentAmountOfFuel= fuel;
	}
	else
	{
		this->currentAmountOfFuel= 0;
	}
}


FuelGauge::~FuelGauge()
{
	this->currentAmountOfFuel = 0;
}

double FuelGauge::getAmountOfFuel()
{
	return this->currentAmountOfFuel;
}


void FuelGauge::incrementFuel()
{
	if (this->currentAmountOfFuel<15)
	{
		this->currentAmountOfFuel = this->currentAmountOfFuel + 1;
	}
}

void FuelGauge::decrementFuel()
{
	if (this->currentAmountOfFuel > 0)
	{
		this->currentAmountOfFuel = this->currentAmountOfFuel - 1;
	}
}
