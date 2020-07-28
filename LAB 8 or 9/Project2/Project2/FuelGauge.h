#ifndef FUEL_GAUGE_H
#define FUEL_GAUGE_H

class FuelGauge
{
private:
	double currentAmountOfFuel;
public:
	FuelGauge(int fuel=0);
	~FuelGauge();
	double getAmountOfFuel();
	void incrementFuel();
	void decrementFuel();
};

#endif