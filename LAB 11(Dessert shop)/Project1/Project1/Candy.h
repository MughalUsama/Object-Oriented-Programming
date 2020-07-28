#ifndef CANDY_H
#define CANDY_H

#include "DessertItem.h"
#include "DessertShoppe.h"

class Candy:public DessertItem
{
private:
	double weight;
	int pricePerPound;
public:
	Candy(CString,double,int);
	int getCost();
	CString getString();
	~Candy();
};

#endif