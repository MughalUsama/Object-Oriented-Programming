#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction f(9, -7);
	Fraction f2(9, 2);
	Fraction f3=f+f2;
	f--;
	f.display();
	cout << "\n";
	system("pause");
	return 0;
}