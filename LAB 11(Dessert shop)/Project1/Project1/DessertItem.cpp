#include "DessertItem.h"


DessertItem::DessertItem()
{
}


DessertItem::DessertItem(CString & dessertName)
{
	if (name.getLength()<=DessertShoppe::getMaxItemNameSize())
	{
		this->name = dessertName;
	}
	else
	{
		this->name = dessertName.left(DessertShoppe::getMaxItemNameSize());
	}

}

CString DessertItem::getName() const
{
	return name;
}

DessertItem::~DessertItem()
{
}



