#ifndef DESSERT_ITEM_H
#define DESSERT_ITEM_H

#include "CString.h"
#include "DessertShoppe.h"

class DessertItem
{
private:
	CString name;

public:
	DessertItem();
	DessertItem(CString &);
	CString getName()const;
	virtual int getCost() = 0;
	virtual CString getString() = 0;
	virtual ~DessertItem();
	
};


#endif // !

