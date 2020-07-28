#include <iostream>
using namespace std;


char ** mineSweeper(int noOfRows, int noOfCol);
void getInput(char ** matrix, int noOfRows, int noOfCol);
void displayMineSweeper(char ** matrix, int noOfRows, int noOfCol);

int main()
{
	char ** matrix;
	int noOfRows, noOfCol;
	cout << "Enter no of rows and coloumns : ";
	cin >> noOfRows >> noOfCol;
	matrix = mineSweeper(noOfRows, noOfCol);
	displayMineSweeper(matrix,noOfRows,noOfCol);
	for (int i = 0; i < noOfRows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	cout << "\n";
	cin.ignore();
	cin.get();
	return 0;
}

char ** mineSweeper(int noOfRows, int noOfCol )
{
	char **matrix = new char *[noOfRows];
	for (int i = 0; i < noOfRows; i=i+1)
	{
		matrix[i] = new char[noOfCol];
	}

	getInput(matrix, noOfRows, noOfCol);

	for (int i = 0; i < noOfRows; i=i+1)
	{
		for (int j = 0; j < noOfCol; j=j+1)
		{
			int value = 0;
			if (matrix[i][j] == '.')
			{
				if (i!=0 && j!=0 && matrix[i - 1][j - 1] == '*')
				{
					value = value + 1;
				}
				if (i!=noOfRows-1 && j!= noOfCol-1 && matrix[i + 1][j + 1] == '*')
				{
					value = value + 1;
				}
				if (i != 0 && j != noOfCol-1 && matrix[i - 1][j + 1] == '*')
				{
					value = value + 1;
				}
				if (i != noOfRows-1 && j != 0 && matrix[i + 1][j - 1] == '*')
				{
					value = value + 1;
				}
			
			
				if (i != 0 && matrix[i - 1][j] == '*')
				{
					value = value + 1;
				}
				if (i != noOfRows-1 && matrix[i + 1][j] == '*')
				{
					value = value + 1;
				}
			
				if (j != noOfCol-1 && matrix[i][j + 1] == '*')
				{
					value = value + 1;
				}
				if (j != 0 && matrix[i][j - 1] == '*')
				{
					value = value + 1;
				}
				
				matrix[i][j] = value + '0';
			}
		}
	}
	return matrix;
}

void getInput(char ** matrix, int noOfRows, int noOfCol)
{
	cout << "\n Enter characters in matrix: \n";

	for (int i = 0; i < noOfRows; i=i+1)
	{
		for (int j = 0; j < noOfCol; j=j+1)
		{
			cin >> matrix[i][j];
		}
	}
}

void displayMineSweeper(char ** matrix, int noOfRows, int noOfCol)
{
	cout << "\n\t\tSweeped mine is: ";

	for (int i = 0; i < noOfRows; i = i + 1)
	{
		cout << "\n\t\t";
		for (int j = 0; j < noOfCol; j = j + 1)
		{
			cout <<  matrix[i][j];
		}
	}
}