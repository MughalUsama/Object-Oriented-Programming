#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	Date d1(1, 03, 2016);
//	d1.incDay(30);

	//d1.incMonth(13);
	//d1.incYear(0);
	d1.displayFormat1();
	cout << "\n";
	cout << "\n";
	system("pause");
	return 0;
}
