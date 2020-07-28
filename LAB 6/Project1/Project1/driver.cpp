#include <iostream>
#include "Set.h"
#include "OrderedPair.h"
#include "Relation.h"
using namespace std;



int main()
{
	OrderedPair o1(1, 3);
	OrderedPair o2(3, 2);
	OrderedPair o3(3, 1);
	OrderedPair o4(3, 4);

	Set a(3);
	a.insert(1);
	a.insert(2);
	a.insert(3);
//	Relation r1(3, a);
	Set a1(3);
	a1.insert(1);
	a1.insert(2);
	a1.insert(3);
	//r1.insert(o1);
	//r1.insert(o2);
	//r1.insert(o3);

	//Relation r2(3, a);


	//r2.insert(o1);
	//r2.insert(o2);
	//r2.insert(o4);

	//r1.print();
	//r1.remove(o4);
	//r1.print();
	//cout << r1.isTransitive();
	//OrderedPair op1(2, 3);
	//OrderedPair op2(2, 4);

	//cout <<"(" <<op1.getElementA() << "," << op1.getElementB()<<")\n";
	//op2.print();
	//cout << "\n" << op1.isEqual(op2);


	cout << "\n";
	system("pause");
	return 0;
}