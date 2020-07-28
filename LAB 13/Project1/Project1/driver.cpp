#include <iostream>
#include "BinaryInput.h"
#include "GetNumber.h"
#include "NumberModify.h"


using namespace std;

int main()
{
	char cont = 'Y';
	while (cont == 'Y' || cont == 'y')
	{
		int option;
		cout<< "\nENTER 1 TO INPUT FILE. \n";
		cout << "ENTER 2 TO Get a number from specific position. \n";
		cout << "ENTER 3 TO Modify a no. \n";
		cin >> option;
		if (option==1)
		{
			FileInput();
		}
		else if (option == 2)
		{
			getNumber();
		}
		else if(option == 3)
		{
			modifyNo();
		}
		cout << "\nDo you want to continue? (Y/N) : ";
		cin >> cont;
	}
	

	cout << "\n";
	system("pause");
	return 0;
}



