#include <iostream>
#include "Set.h"
using namespace std;



int main()
{
	Set s(5);
	s.insert(1);
	s.insert(2);
	s.insert(0);

	s.displaySet();

	Set s1(5);
	s1.insert(1);
	s1.insert(2);
	s1.insert(0);
	s1.insert(8);

	s1.displaySet();

	Set s3 = (s.calcDifference(s1));
	s3.displaySet();
	cout << s1.isSubSet(s);
	cout << "\n";
	system("pause");
	return 0;
}