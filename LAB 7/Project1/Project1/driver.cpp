#include <iostream>
#include "ComplexNumber.h"

using namespace std;

int main()
{
	ComplexNumber c(0, 7);
	ComplexNumber c1(0, 2);
	ComplexNumber c3 = c + c1;
	c3.display();
	cout << "\n";
	c3 = c - c1;
	c3.display();
	cout << "\n";
	c3 = c * c1;
	c3.display();
	cout << "\n";
	c3 = c / c1;
	c3.display();
	cout << "\n";
	system("pause");
	return 0;
}