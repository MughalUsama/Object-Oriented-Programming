#include "OrderedPair.h"
#include <iostream>
using namespace std;



OrderedPair::OrderedPair(int n, int m)
{
	this->a = n;
	this->b = m;
}



int OrderedPair::getElementA() const
{
	return this->a;
}

int OrderedPair::getElementB() const
{
	return this->b;
}

void OrderedPair::print()
{
	cout << "(" << a << "," << b << ")";
}

bool OrderedPair::isEqual(const OrderedPair & oP) const
{
	if (this->a==oP.a && this->b==oP.b)
	{
		return true;
	}
	return false;
}
