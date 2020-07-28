#include <iostream>
using namespace std;

void specialSearch(int *arr, int n, int key, int &numLess, int &numGreater);


int main()
{
	int arr[10] = { 12,34,5,17,4,23,21,32,-2,34 };
	int key = 12;
	int numLess = 0, numGreater = 0;
	specialSearch(arr, 10, key, numLess, numGreater);
	cout << "\nThere are " << numLess << " numbers less than and " << numGreater << " numbers are greater than " << key;

	cout << "\n";
	system("pause");
	return 0;
}

void specialSearch(int *arr, int n, int key, int &numLess, int &numGreater)
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i]>key)
		{
			numGreater = numGreater + 1;
		}
		else if(arr[i]<key)
		{
			numLess = numLess + 1;
		}
	}

}