#ifndef COOKIE_H
#define COOKIE_H

#include "DessertItem.h"
#include "DessertShoppe.h"

class Cookie:public DessertItem
{
private:
	int noOfCookies;
	int pricePerDozen;
public:
	Cookie(CString ,int, int );
	int getCost();
	CString getString();
};

#endif