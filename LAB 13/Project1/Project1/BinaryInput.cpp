#include <iostream>
#include <fstream>


using namespace std;

void FileInput()
{
	fstream file("numbers.dat", ios::out | ios::binary);
	int number;
	int count = 0;
	/*cout << "Enter a number (0 to terminate): ";
	cin >> number;
	while (number != 0)
	{
		count++;
		file.write(reinterpret_cast <char *>(&number), sizeof(number));
		cout << "Enter a number (0 to terminate): ";
		cin >> number;
	}
	cout << count << " number(s) have been stored in the file \"numbers.dat\"";
	file.close();*/

	fstream file1("numbers.dat", ios::in | ios::binary);
	for (int i = 0; i < 9; i++)
	{
		file1.read(reinterpret_cast <char *>(&number), sizeof(number));
		cout << number;
	}
}
