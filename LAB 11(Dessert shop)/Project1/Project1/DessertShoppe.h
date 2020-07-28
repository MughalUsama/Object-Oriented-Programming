#ifndef DESSERTSHOPPE_H
#define DESSERTSHOPPE_H

#include "CString.h"


class DessertShoppe
{
private:
	static const double taxRate;
	static const CString storeName;
	static const int maxItemNameSize;
	static const int costWidth;
public:
	static CString cents2dollarsAndCents(int cents);
	static int getMaxItemNameSize();
	static CString getStoreName();
	static int getCostWidth();
	static int getTaxRate();
}
;

#endif // !

