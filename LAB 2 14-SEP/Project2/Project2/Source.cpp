#include <iostream>
using namespace std;

int ** fillInRowMajorOrder(int * inputArray, int rows, int cols, int noOfElements);
int ** create2dArray(int rows, int cols, int noOfElements);
void display2dArray(int **  newArray, int rows, int cols);
void deallocateArray(int **newArray, int rows);
int ** fillInColMajorOrder(int * inputArray, int rows, int cols, int noOfElements);

int main()
{
	int rows=8, col=3, noOfElements=24;
	int inputArray[25] = { 2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7 };
	for (int i = 0; i < noOfElements; i++)
		inputArray[i] = i + 1;
	//filling arrray
	int ** new2dArray =	fillInColMajorOrder(inputArray, rows, col, noOfElements);
	if (new2dArray==0)
	{
		cout << "Array cannot be filled";
	}
	else
	{
		//displaying array
		display2dArray(new2dArray, rows, col);

		//deallocating array
		deallocateArray(new2dArray, rows);
	}

	cout << "\n";
	system("pause");
	return 0;
}


//row major filling
int ** fillInRowMajorOrder(int * inputArray, int rows, int cols, int noOfElements)
{

	int **newArray = create2dArray(rows, cols, noOfElements);
	if (newArray== 0)
	{
		return 0;
	}
	else
	{
		int index = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
					newArray[i][j] = inputArray[index];
					index = index + 1;
			}
		}
	}
	return newArray;
}


//creating array
int ** create2dArray(int rows, int cols, int noOfElements)
{
	if ((rows*cols)!=noOfElements)
	{
		return 0;
	}
	else
	{
		int **newArray = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new int [cols];
		}
		return newArray;
	}

}

//displaying aaray
void display2dArray(int **  newArray, int rows, int cols )
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << newArray[i][j] << " ";
;
		}
		cout << "\n";
	}
}

//deallocating array
void deallocateArray(int **newArray, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] newArray[i];
	}
	delete[] newArray;
}



int ** fillInColMajorOrder(int * inputArray, int rows, int cols, int noOfElements)
{

	int **newArray = create2dArray(rows, cols, noOfElements);
	if (newArray == 0)
	{
		return 0;
	}
	else
	{
		int index = 0;
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				newArray[j][i] = inputArray[index];
				index = index + 1;
			}
		}
	}
	return newArray;
}