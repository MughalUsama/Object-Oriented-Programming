#ifndef SUNDAE_H
#define SUNDAE_H

#include "IceCream.h"
#include "DessertShoppe.h"

class Sundae:public IceCream
{
private:
	CString topping;
	int priceOfSundae;
public:
	Sundae(CString , int , CString , int );
	int getCost();
	CString getString();

};

#endif