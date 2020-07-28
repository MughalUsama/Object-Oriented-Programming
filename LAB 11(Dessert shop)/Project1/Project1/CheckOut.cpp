#include "CheckOut.h"



CheckOut::CheckOut()
{
	dessertItem = new DessertItem * [5];
	this->noOfItems= 0;
	this->size = 5;
}


CheckOut::~CheckOut()
{
	for (int i = 0; i < this->noOfItems; i++)
	{
		delete dessertItem[i];
	}
	delete[] dessertItem;
	dessertItem = nullptr;
	
}

void CheckOut::clear()
{
	this->~CheckOut();
	this->noOfItems = 0;
	this->size = 5;
}

void CheckOut::enterItem(DessertItem * item)
{
	if (this->noOfItems < this->size)
	{
		this->dessertItem[this->noOfItems] = item;
		this->noOfItems = this->noOfItems + 1;
	}
	else
	{
		this->resize();
		this->dessertItem[this->noOfItems] = item;
		this->noOfItems = this->noOfItems + 1;
	}
}

int CheckOut::numberOfItems()
{
	return this->noOfItems;
}

CString CheckOut::toString()
{
	CString receipt;
	receipt.concatEqual("\n\t\t\t");
	receipt.concatEqual(DessertShoppe::getStoreName());
	receipt.concatEqual("\n\t\t------------------------------------\n");
	for (int i = 0; i < this->noOfItems; i++)
	{
		receipt += "\t\t";
		receipt += ((i + 1)/10);
		receipt+=((i+1)%10);
		receipt += "_ ";
		receipt+=(dessertItem[i]->getString());
		receipt+=("");
		receipt+=(DessertShoppe::cents2dollarsAndCents(dessertItem[i]->getCost()));
		receipt+=("\n");
	}
	return receipt;
}

int CheckOut::totalCost()
{

	int totalCost = 0;
	for (int i = 0; i < this->size; i++)
	{
		totalCost=dessertItem[i]->getCost() + totalCost;
	}
	return totalCost;
}

double CheckOut::totalTax()
{
	
	double totalTax=0;
	totalTax = totalCost()*(DessertShoppe::getTaxRate())/100 ;
	if (totalTax-(int)totalTax>=0.500)
	{
		return (int)totalTax + 1;
	}
	else
	{
		return (int)totalTax;
	}
}

void CheckOut::resize()
{
	DessertItem** temp = new DessertItem *[this->size+5];
	
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->dessertItem[i];
	}
	delete[] dessertItem;
	this->size += 5;
	this->dessertItem = temp;
}

ostream & operator<<(ostream & os, CheckOut & checkout)
{
	cout << checkout.toString();
	return os;
}
