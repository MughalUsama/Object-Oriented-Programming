#include<iostream>
#include"matrixClass.h"
using namespace std;

Matrix :: Matrix()
{
	row = 0;
	col = 0;
	data = nullptr;
}
Matrix::Matrix(const Matrix & cpy)
{
	row = cpy.row;
	col = cpy.col;
	data = new int *[row];
	for (int i = 0; i < row; i = i + 1)
	{
		data[i] = new int[col];
	}
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			data[i][j] = cpy.data[i][j];
		}
	}
}
Matrix::Matrix(int r, int c)
{
	row = r;
	col = c;
	data = new int *[row];
	for (int i = 0; i < row; i = i + 1)
	{
		data[i] = new int[col];
	}
}
void Matrix :: inputArr()
{	
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			cout << "Data[" << i << "][" << j << "] : ";
			cin >> data[i][j];
		}
	}
}

void Matrix :: setRow(int r)
{
	row = r;
}
void Matrix :: setCol(int c)
{
	col = c;
}
int Matrix :: getRow() const
{
	return row;
}
int Matrix :: getCol() const
{
	return col;
}

int& Matrix :: at(const int r, const int c)										// ???
{
	return data[r][c];
}

void Matrix :: printMatrix() const
{
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			cout << data[i][j] << " ";
		}
		cout << "\n";
	}
}

int Matrix::isIdentity() const
{
	int a = 0;
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			if (i != j && data[i][j] != 0)
			{
				return 0;
			}
			if (i == j && data[i][j] == 1)
			{
				a = a + 1;
			}
		}
	}
	if (a == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
bool Matrix::isRectangular()const
{
	if (row != col)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Matrix::isDiagonal()const
{
	int a = 0;
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			if (i != j && data[i][j] != 0)
			{
				return false;
			}
			if (i == j && data[i][j] == 0)
			{
				a = a + 1;
			}
		}
	}
	if (a != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Matrix::isNullMatrix() const
{
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			if (data[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool Matrix::isLowerTriangular() const
{
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			if (j > i && data[i][j]!=0)
			{
				return false;
			}
		}
	}
	return true;
}
bool Matrix::isUpperTriangular() const
{
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			if (i > j && data[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool Matrix::isTriangular()const
{
	if (isUpperTriangular() == true || isLowerTriangular() == true || isDiagonal() == true)
	{
		return true;
	}
	return false;
}

Matrix Matrix::getMatrixCopy() const
{
	Matrix abc;
	abc.row = row;
	abc.col = col;
	abc.data = new int *[row];
	for (int i = 0; i < row; i = i + 1)
	{
		abc.data[i] = new int[col];
	}
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			abc.data[i][j] = data[i][j];
		}
	}
	return abc;
}

bool Matrix :: isEqual(const Matrix m2) const
{
	if (m2.row != row || m2.col != col)
	{
		return false;
	}
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			if (m2.data[i][j] != data[i][j])
			{
				return false;
			}
		}
	}
	return true;
}


void Matrix :: reSize(const int newrow, const int newcol)
{
	int ** resizedData = new int *[newrow];
	{
		for (int i = 0; i < newrow; i = i +1)
		{
			resizedData[i] = new int[newcol];
		}
	}
	for (int i = 0; i < row; i = i + 1)
	{
		for (int j = 0; j < col; j = j + 1)
		{
			resizedData[i][j] = data[i][j];
		}
	}
	freeMemory();
	row = newrow;
	col = newcol;
	data = resizedData;
}

void Matrix :: freeMemory()
{
	for (int i = 0; i < row; i = i + 1)
	{
		delete[] data[i];
	}
	delete[] data;
	data = nullptr;
	row = 0;
	col = 0;
}



































































