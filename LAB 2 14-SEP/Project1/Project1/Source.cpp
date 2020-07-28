#include <iostream>
using namespace std;

int ** createPascalArray(int );
void displayPascalArray(int **, int );
void deallocatePascalTriangle(int **, int );

int main()
{
	int noOfRows;
	cout << "Enter no of rows of Pascal triangle: ";
	cin >> noOfRows;
	//creating array
	int **pascalArray = createPascalArray(noOfRows);
	//displaying array
	displayPascalArray(pascalArray, noOfRows);
	//deallocating array
	deallocatePascalTriangle(pascalArray, noOfRows);

	cout << "\n";
	system("pause");
	return 0;
}

int ** createPascalArray(int n)
{
	int ** pascalArray = new int *[n];

	for (int i = 0; i < n; i++)
	{
		pascalArray[i] = new int[i+1];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j==0 || j==i)
			{
				pascalArray[i][j] = 1;
			}
			else
			{
				pascalArray[i][j] = pascalArray[i - 1][j] + pascalArray[i - 1][j - 1];
			}
		}
	}
	return pascalArray;
}

void displayPascalArray(int **pt, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << pt[i][j] << " ";
		}
		cout << "\n";
	}
}

void deallocatePascalTriangle(int **pt,int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] pt[i];
	}
	delete[] pt;
}