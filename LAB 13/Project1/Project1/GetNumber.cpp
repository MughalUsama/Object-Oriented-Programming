#include <iostream>
#include <fstream>

using namespace std;

void getNumber()
{
	int position = 0, number;

	fstream file("C:\\Users\\Usama Shahid\\Desktop\\C++\\OOP\\LAB 13\\Project1\\Project1\\numbers.dat", ios::in | ios::binary);
	cout << "Enter the position of number you want to access : ";
	cin >> position;
	file.seekg((position - 1) * sizeof(number), ios::beg);
	
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
		file.read(reinterpret_cast <char *>(&number), sizeof(number));
		cout << "No." << position << " is " << number << "\n";
	}
	file.close();
}




