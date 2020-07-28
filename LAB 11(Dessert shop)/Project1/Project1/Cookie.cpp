#include "Cookie.h"




Cookie::Cookie(CString dName, int number, int price):DessertItem(dName)
{
	if (number>=0)
	{
		this->noOfCookies = number;
	}
	else
	{
		this->noOfCookies = -number;
	}

	if (price>=0)
	{
		this->pricePerDozen = price;
	}
	else
	{
		this->pricePerDozen = -price;
	}
}



int Cookie::getCost()
{
	double cost=this->noOfCookies/12*this->pricePerDozen;
	if ((cost-int(cost))>=0.500)
	{
		return int(cost) + 1;
	}
	else
	{
		return int(cost);
	}
}

CString Cookie::getString()
{
	CString str="";
	str += this->noOfCookies;
	str += " @ ";
	str += pricePerDozen;
	str += "/dz\n    ";
	str += "\t\t\t";
	str += this->getName();
	str += "\t\t\t";
	return str;
}
