#include <iostream>
#include "DoubleSubscriptedArray.h"
using namespace std;


int main()
{
	DoubleSubscriptedArray ar(3, 2);
	cin >> ar;
	cout << ar;
	cout << "\n";
	DoubleSubscriptedArray ar1(3, 2);
	cin >> ar1;
	cout << ar1;
	cout << "\n";
	cout << (ar != ar1);
	cout << "\n";
	system("pause");
	return 0;
}