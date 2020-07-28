#include <iostream>
using namespace std;


#include "CheckOut.h"






int  main()
{
	CheckOut checkout;

	checkout.enterItem(new Candy("FUDGE", 2.25, 399));
	checkout.enterItem(new IceCream("Chocolate", 100));
	checkout.enterItem(new Candy("FUDGE", 5, 399));
	checkout.enterItem(new IceCream("Vanilla", 200));
	checkout.enterItem(new Candy("Strawberry", 3, 270));
	checkout.enterItem(new IceCream("Orange", 290));
	checkout.enterItem(new Sundae("Vanilla", 200, "Chocolate chip", 40));
	checkout.enterItem(new Sundae("Mango", 250,"Chocolate",35));

	cout << checkout;
	cout << "\n";
	system("pause");
	return 0;
}