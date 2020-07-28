#include<iostream>
#include"MyArray.h"

using namespace std;

int main()
{
	try
	{
		MyArray a(5);
		a.input();

		MyArray c;
		c = a;
		for (int i = 0; i < 5; i++)
		{
			cout << c[i] << "\n";
		}
	}
	catch(MyArray::negSize message)
	{
		message.display();
	}
	catch (MyArray::wrongSubscript message)
	{
		message.display();
	}


	cout << "\n";
	system("pause");
	return 0;

}