#include "DessertShoppe.h"

const double DessertShoppe:: taxRate=6.5;
const CString DessertShoppe::storeName= "M & M Dessert Shoppe";
const int DessertShoppe::maxItemNameSize=25;
const int DessertShoppe::costWidth=6;

CString DessertShoppe::cents2dollarsAndCents(int cents)
{
	CString s = "";
	if (cents<0)
	{
		s += "-";
		cents *= -1;
	}
	int dollars = cents / 100;
	cents = cents % 100;
	if (dollars > 0)
	{
		s += dollars;
	}
	s += ".";
	if (cents<10)
	{
		s += "0";
	}
	s += cents;
	return s;

}


int DessertShoppe::getMaxItemNameSize()
{
	return maxItemNameSize;
}

CString DessertShoppe::getStoreName()
{
	return storeName;
}

int DessertShoppe::getCostWidth()
{
	return costWidth;
}

int DessertShoppe::getTaxRate()
{
	return taxRate;
}

