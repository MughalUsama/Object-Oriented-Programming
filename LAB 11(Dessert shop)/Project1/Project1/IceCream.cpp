#include "IceCream.h"


IceCream::IceCream(CString dname,int cost):DessertItem(dname)
{
	if (cost >= 0)
	{
		this->price = cost;
	}
	else
	{
		this->price = -cost;
	}
}


int IceCream::getCost()
{
	return price;
}

CString IceCream::getString()
{
	CString str = "";
	str += this->getName();
	str += " Ice cream\t\t";
	return str;
}

IceCream::~IceCream()
{
}
