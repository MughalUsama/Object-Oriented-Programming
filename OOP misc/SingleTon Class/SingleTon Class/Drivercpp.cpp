#include <iostream>
#include"Singleton.h"
using namespace std;

int main()
{
	SingleTon * sptr = SingleTon::create();
	cout << sptr << "\n";
	system("pause");
	return 0;
}