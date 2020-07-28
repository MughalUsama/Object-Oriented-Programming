#ifndef ICECREAM_H
#define ICECREAM_H

#include "DessertItem.h"
#include "DessertShoppe.h"

class IceCream:public DessertItem
{
private:
	int price;
public:
	IceCream(CString,int);
	int getCost();
	CString getString();
	~IceCream();
};

#endif