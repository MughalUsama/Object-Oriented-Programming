#include <iostream>
using namespace std;

int * copyArray(int *arr, int size);


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int *newArr = copyArray(arr, 10);

	for (int i = 0; i < 20; i++)
	{
		cout << "\n" << newArr[i];

	}

	delete[] newArr;
	cout << "\n";
	system("pause");
	return 0;
}

int * copyArray(int *arr, int size)
{
	int * newArr = new int[size * 2];
	
	for (int i = 0; i < size*2; i++)
	{
		if (i<size)
		{
			newArr[i] = arr[i];
		}
		else
		{
			newArr[i] = 0;
		}
	}
	return newArr;
}