#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "DessertItem.h"
#include "Candy.h"
#include "Cookie.h"
#include "CString.h"
#include "IceCream.h"
#include "Sundae.h"
#include "DessertShoppe.h"


#include <iostream>
using namespace std;

class CheckOut;

ostream & operator << (ostream &, CheckOut &);


class CheckOut
{
private:
	DessertItem ** dessertItem;
	int size = 0;
	int noOfItems;
public:
	CheckOut();
	~CheckOut();
	void clear();
	void enterItem(DessertItem * );
	int numberOfItems();
	CString toString();
	int totalCost();
	double totalTax();
	void resize();
	friend ostream & operator << (ostream & os, CheckOut &);
};

#endif