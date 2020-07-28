#include "Candy.h"




Candy::Candy(CString dName,double dWeight, int price):DessertItem(dName)
{
	if (dWeight>=0)
	{
		this->weight = dWeight;
	}
	else
	{
		this->weight = -dWeight;
	}

	if (price >= 0)
	{
		this->pricePerPound = price;
	}
	else
	{
		this->pricePerPound = -price;
	}
}



int Candy::getCost()
{
	double cost = this->weight * this->pricePerPound;
	if ((cost - int(cost))>=0.500)
	{
		return int(cost) + 1;
	}
	else
	{
		return int(cost);
	}
}

CString Candy::getString()
{
	CString str = "";
	str += this->weight;
	str += " @ ";
	str += pricePerPound;
	str += "/lb\n    ";
	str += "\t\t    ";
	str += this->getName();
	str += "\t\t\t";
	return str;
}

Candy::~Candy()
{
}

