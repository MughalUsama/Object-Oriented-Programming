#include <iostream>
#include <fstream>

using namespace std;

void  modifyNo()
{
	int position = 0, number;

	fstream file("C:\\Users\\Usama Shahid\\Desktop\\C++\\OOP\\LAB 13\\Project1\\Project1\\numbers.dat", ios::out | ios::binary |ios::app);
	cout << "Enter the position of number you want to access : ";
	cin >> position;

	file.seekp((position - 1) * sizeof(number), ios::beg);
	if (file.eof())
	{
		cout << "Error!! The file does not have those many numbers.\n";
	}
	else if (position <= 0)
	{
		cout << "Error!! You must specify a positive value.\n";
	}
	else
	{
		cout << "Enter the number to replace: ";
		cin >> number;
	
		file.write(reinterpret_cast <char *>(&number), sizeof(number));
	}
	file.close();
}



