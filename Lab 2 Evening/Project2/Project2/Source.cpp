#include <iostream>
using namespace std;

struct Matrix 
{
	int rows;
	int cols;
	int **data;
};

void createMatrix (Matrix &m, const int row = 1, const int Col = 1);//1
void inputMatrix(Matrix &mat);
void printMatrix(Matrix m);//2
bool isIdentity(const Matrix m);//3
bool isRectangular(const Matrix m);//4
bool isDiagonal(const Matrix m);//5
bool isNullMatrix(const Matrix m);//6
bool isUpperTriangular(const Matrix m);//7
bool isLowerTriangular(const Matrix m);//8
bool isTriangular(const Matrix m);//9
Matrix getMatrixCopy(const Matrix m);//10
bool isEqual(const Matrix m1, const Matrix m2);//11
void freeMatrix(Matrix m);//12
Matrix add(const Matrix m1, const Matrix m2);//13
Matrix transpose(const Matrix m);//14
bool isSymmetric(const Matrix m);//15
bool isSkewSymmetric(const Matrix m);//16



int main()
{
	Matrix mat;
	createMatrix(mat, 3, 3);
	inputMatrix(mat);
	printMatrix(mat);
	cout << "\n";
	transpose(mat);
	cout << "\n";
	cout << "\n " << isSkewSymmetric(mat);

	cout << "\n";
	system("pause");
	return 0;
}

void createMatrix(Matrix &m, const int row, const int col)
{
	m.rows = row;
	m.cols = col;
	m.data = new int *[row];
	for (int i = 0; i < row; i++)
	{
		m.data[i] = new int[col];
	}
}

void printMatrix(const Matrix m)
{
	for (int i = 0; i < m.rows; i++)
	{
		cout << "\n";
		for (int j = 0; j < m.cols; j++)
		{
			cout << m.data[i][j] << " ";
		}	
	}
}

void inputMatrix(Matrix &mat)
{
	for (int i = 0; i < mat.rows; i++)
	{
		cout << "\n\nEnter values in row :" << i + 1<<"\n";
		for (int j = 0; j < mat.cols; j++)
		{
			cout << "Matrix[" << i << "][" << j << "] = ";
			cin >> mat.data[i][j];
		}
	}
}

bool isIdentity(const Matrix m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			if (i!=j && m.data[i][j] != 0)
			{
				return false;
			}
			else if (i==j && m.data[i][j]!=1)
			{
				return false;
			}
		}
	}
	return true;
}

bool isRectangular(const Matrix m)
{
	if (m.cols!=m.rows)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isDiagonal(const Matrix m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			if (i != j && m.data[i][j] != 0)
			{
				return false;
			}
		}
	}
	for (int j = 0; j < m.cols; j++)
	{
		if (m.data[j][j]!=0)
		{
			return true;
		}
	}
	return false;
}

bool isNullMatrix(const Matrix m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			if (m.data[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool isUpperTriangular(const Matrix m)
{
	if (!isRectangular(m))
	{

		for (int i = 0; i < m.rows; i++)
		{
			for (int j = 0; j < m.cols; j++)
			{
				if (i > j && m.data[i][j] != 0)
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool isLowerTriangular(const Matrix m)
{
	if (!isRectangular(m))
	{
		for (int i = 0; i < m.rows; i++)
		{
			for (int j = 0; j < m.cols; j++)
			{
				if (i < j && m.data[i][j] != 0)
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool isTriangular(const Matrix m)
{
	if (isLowerTriangular(m)||isUpperTriangular(m))
	{
		return true;
	}
	return false;
}

Matrix getMatrixCopy(const Matrix m)
{
	Matrix newMat;
	createMatrix(newMat, m.rows,m.cols);
	
	newMat.cols = m.cols;
	newMat.rows = m.rows;
	for (int i = 0; i < newMat.cols; i++)
	{
		for (int j = 0; j < newMat.rows; j++)
		{
			newMat.data[i][j] = m.data[i][j];
		}
	}
	return newMat;
}

bool isEqual(const Matrix m1, const Matrix m2)
{
	if (m1.cols==m2.cols && m1.rows==m2.rows)
	{
		for (int i = 0; i < m1.rows; i++)
		{
			for (int j = 0; j < m1.cols; j++)
			{
				if (m1.data[i][j]!=m2.data[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

void freeMatrix(Matrix m)
{
	for (int i = 0; i < m.rows; i++)
	{
		delete[] m.data[i];
	}
	delete[] m.data;
}

Matrix add(const Matrix m1, const Matrix m2)
{
	Matrix newMat;
	createMatrix(newMat, m1.rows, m1.cols);

	for (int i = 0; i < m1.rows; i++)
	{
		for (int j = 0; j < m1.cols; j++)
		{
			newMat.data[i][j] = m1.data[i][j] + m2.data[i][j];
		}
	}
	return newMat;
}

Matrix transpose(const Matrix m)
{
	Matrix newMat;
	createMatrix(newMat, m.cols, m.rows);
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			newMat.data[i][j] = m.data[j][i];
		}
	}
	return newMat;
}

bool isSymmetric(const Matrix m)
{
	Matrix m2=transpose(m);
	if (isEqual(m,m2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isSkewSymmetric(const Matrix m)
{
	Matrix m1 = transpose(m);
	if (m1.cols == m.rows && m1.rows == m.cols)
	{
		for (int i = 0; i < m.rows; i++)
		{
			for (int j = 0; j < m.cols; j++)
			{
				if (m1.data[i][j] != -(m.data[i][j]))
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
