#include<iostream>
#include"MyArray.h"

using namespace std;

int main()
{

	MyArray<char> a(5);
	a.input();

	MyArray<char> c;
	c = a;
	for (int i = 0; i < 5; i++)
	{
		cout << c[i] << "\n";
	}

	system("pause");
	return 0;

}