#include <iostream>
using namespace std;

int getTotal(int arr[][5]);
double getAverage(int arr[][5]);
int getRowTotal(int arr[][5], int rowNo);
int getColTotal(int arr[][5], int colNo);
int getHighestInRow(int arr[][5], int rowNo);
int getLowestInRow(int arr[][5], int rowNo);

int main()
{
	int arr[5][5] = { {1,3,4,5,6},{3,4,6,3,6},{9,0,7,5,3},{0,6,4,2,2},{5,5,2,9,7} };
	cout << "\nTotal "<<getTotal(arr);
	cout << "\nAverage " << getAverage(arr);
	cout << "\nRow Total " << getRowTotal(arr, 3);
	cout << "\nColoumn Total " << getColTotal(arr, 1);
	cout << "\nHighest in row " << getHighestInRow(arr, 2);
	cout << "\nLowest in row " << getLowestInRow(arr, 2);
	

	cout << "\n";
	system("pause");
	return 0;
}

int getTotal(int arr[][5])
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5;j++)
		{
			total = total + arr[i][j];
		}
	}
	return total;
}
double getAverage(int arr[][5])
{
	int total = getTotal(arr);
	return total / (25.0);
}

int getRowTotal(int arr[][5], int rowNo)
{
	int total = 0;
	for (int j = 0; j < 5; j++)
	{
		total = total + arr[rowNo][j];
	}
	return total;
}
int getColTotal(int arr[][5], int colNo)
{
	int total = 0;
	for (int j = 0; j < 5; j++)
	{
		total = total + arr[j][colNo];
	}
	return total;
}
int getHighestInRow(int arr[][5], int rowNo)
{
	int highest = arr[rowNo][0];
	for (int j = 0; j < 5; j++)
	{
		if (arr[rowNo][j]>highest)
		{
			highest = arr[rowNo][j];
		}
	}
	return highest;
}
int getLowestInRow(int arr[][5], int rowNo)
{
	int lowest = arr[rowNo][0];
	for (int j = 0; j < 5; j++)
	{
		if (arr[rowNo][j]<lowest)
		{
			lowest = arr[rowNo][j];
		}
	}
	return lowest;
}