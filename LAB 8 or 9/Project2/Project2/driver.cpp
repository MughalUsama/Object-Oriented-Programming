#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"
using namespace std;


int main()
{
	FuelGauge f(15);
	Odometer od(999999);
	for (int i = 0; i <= 24; i++)
	{
		od.incrementMileage(f);
		cout << f.getAmountOfFuel()<< " ";
		cout << od.getMileage() << "\n";
	}





	cout << "\n";
	system("pause");
	return 0;
}