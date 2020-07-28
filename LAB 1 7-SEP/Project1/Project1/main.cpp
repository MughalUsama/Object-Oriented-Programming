#include <iostream>
using namespace std;

int * extractPositives(int * , int , int &);

int main()
{
	int array[10] = { 21,42,4,-52,84,0,9,-33,2,78 };
	int newArraySize = 0;

	int *positivesArray = extractPositives(array, 10, newArraySize);

	//displaying array
	cout << "\nArray of positive integers is : ";
	for (int i = 0; i < newArraySize; i=i+1)
	{
		cout << positivesArray[i]<<" ";
	}
	delete[] positivesArray;
	cout << "\n";
	cin.get();
	return 0;
}

int * extractPositives(int * original, int origSize, int &newSize)
{
	int * newArray;
	for (int i = 0; i < origSize; i=i+1)
	{
		if (original[i]>=0)
		{
			newSize = newSize + 1;
		}
	}

	if (newSize!=0)
	{
		newArray = new int[newSize];

		int index = 0;
		for (int i = 0; i < origSize; i = i + 1)
		{
			if (original[i] >= 0)
			{
				newArray[index] = original[i];
				index = index + 1;
			}
		}
		return newArray;
	}
	cout << "There is no positive number in array.\n";
	cin.get();
	exit(0);
}