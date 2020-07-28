#include "Sundae.h"



Sundae::Sundae(CString dName, int priceOfIcecream,CString toppingName,int price):IceCream(dName,priceOfIcecream),topping(toppingName)
{
	if (price >= 0)
	{
		this->priceOfSundae = price;
	}
	else
	{
		this->priceOfSundae = -price;
	}
}


int Sundae::getCost()
{
	int costOfSundae=this->priceOfSundae+IceCream::getCost();
	return costOfSundae;
}

CString Sundae::getString()
{
	CString str = "";
	str += this->topping;
	str += " sundae ";
	str += " with \n";
	str += "\t\t    ";
	str += this->getName();
	str += " Ice cream\t\t";
	return str;
}
