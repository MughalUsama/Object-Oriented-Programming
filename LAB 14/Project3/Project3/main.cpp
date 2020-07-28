#include <iostream>
using namespace std;
#include "Account.h"

int main()
{
	try
	{
		Account a(500);
//		a.deposit(-100);
		a.withdraw(600);
	}
	catch (const char msg[])
	{
		cout << msg;
	}

	cout << "\n";
	system("pause");
	return 0;
}