#include <iostream>
#include "TestScores.h"
using namespace std;


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	try
	{
		TestScores scores(arr,10);
		cout << scores.arrayAverage();
	}
	catch (const char str[])
	{
		cout << str;
	}

	
	cout << "\n";
	system("pause");
	return 0;
}