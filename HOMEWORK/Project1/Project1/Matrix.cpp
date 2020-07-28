#include "Matrix.h"
#include <iostream>

using namespace std;



Matrix::Matrix()
{
	this->cols = 0;
	this->rows = 0;
	this->data = nullptr;
}

Matrix::Matrix(const Matrix & ref)
{
	
	this->cols = ref.cols;
	this->rows = ref.rows;
	this->data = new int *[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		this->data[i] = new int[this->cols];
	}
	for (int i = 0; i < ref.rows; i++)
	{
		for (int j = 0; j < ref.cols; j++)
		{
			this->data[i][j] = ref.data[i][j];
		}
	}
}

Matrix::Matrix(int rw, int cl)
{
	this->cols = cl;
	this->rows = rw;
	this->data = new int *[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		this->data[i] = new int[this->cols];
	}
}


Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] this->data[i];
	}
	delete[] this->data;
	this->data = nullptr;
}

void Matrix::setRow(int r)
{
	this->rows = r;
	this->data = new int *[this->rows];
}

void Matrix::setCol(int c)
{
	this->cols = c;
	for (int i = 0; i < this->rows; i++)
	{
		this->data[i] = new int[cols];
	}
}

int Matrix::getRow() const
{
	return this->rows;
}

int Matrix::getCol() const
{
	return this->cols;
}

void Matrix::inputMatrix()
{
	cout << "Input Matrix: \n";
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			cout << "\nEnter value at location ["<<i<<"]["<<j<<"]";
			cin >> this->data[i][j];
		}
	}
}

int & Matrix::at(const int r, const int c)
{
	cout << "Enter the value";
	int value;
	cin >> value;
	this->data[r][c] = value;
	return this->data[r][c];
}

void Matrix::printMatrix() const
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			cout << this->data[i][j] << " ";
		}
		cout << "\n";
	}
}

bool Matrix::isIdentity() const
{
	if (this->rows!=this->cols)
	{
		return false;
	}
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			if (i != j && this->data[i][j] != 0)
			{
				return false;
			}
			else if (i == j && this->data[i][j] != 1)
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isRectangular() const
{
	if (this->cols != this->rows)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Matrix::isDiagonal() const
{
	if (this->rows != this->cols)
	{
		return false;
	}
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			if (i != j && this->data[i][j] != 0)
			{
				return false;
			}
		}
	}
	for (int j = 0; j < this->cols; j++)
	{
		if (this->data[j][j] != 0)
		{
			return true;
		}
	}
	return false;

}

bool Matrix::isNullMatrix() const
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			if (this->data[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isLowerTriangular() const
{
	if (!this->isRectangular())
	{

		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				if (i > j && this->data[i][j] != 0)
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool Matrix::isUpperTriangular() const
{
	if (!this->isRectangular())
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				if (i < j && this->data[i][j] != 0)
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool Matrix::isTriangular() const
{
	if (this->isLowerTriangular() || this->isUpperTriangular())
	{
		return true;
	}
	return false;
}

Matrix Matrix::getMatrixCopy() const
{
	Matrix temp(this->rows,this->cols);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			temp.data[i][j] = this->data[i][j];
		}
	}
	return temp;
}

bool Matrix::isEqual(const Matrix m2) const
{
	if (this->cols == m2.cols && this->rows == m2.rows)
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				if (this->data[i][j] != m2.data[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

void Matrix::reSize(const int newRow, const int newCol)
{
	int ** temp;
	temp = new int *[newRow];
	for (int i = 0; i < newRow; i++)
	{
		temp[i] = new int[newCol];
	}
	for (int i = 0; i <  newRow; i++)
	{
		for (int j = 0; j < newCol; j++)
		{
			if (i > this->rows || j > this->cols)
			{
				temp[i][j] = 0;
			}
			else
			{
				temp[i][j] = this->data[i][j];
			}
		}
	}
	this->freeMemory();
	this->data = temp;
	this->rows = newRow;
	this->cols = newCol;
}

bool Matrix::isSymmetric() const
{
	Matrix m2 = this->transpose();
	if (this->isEqual(m2))
	{
		return true;
	}
	else
	{
		return false;
	}

}


bool Matrix::isSkewSymmetric() const
{
	Matrix m1 = this->transpose();
	if (m1.cols == this->rows && m1.rows == this->cols)
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				if (m1.data[i][j] != -(this->data[i][j]))
				{
					return false;
				}
			}
		}
		return true;
	}
	return false;
}

Matrix Matrix::transpose() const
{
	Matrix newMat(this->cols, this->rows);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			newMat.data[i][j] = this->data[j][i];
		}
	}
	return newMat;
}

Matrix Matrix::add(const Matrix m) const
{
	Matrix sum(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			sum.data[i][j] = this->data[j][i]+m.data[i][j];
		}
	}
	return sum;
}

Matrix Matrix::minus(const Matrix) const
{
	Matrix subtract(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			subtract.data[i][j] = this->data[j][i] - subtract.data[i][j];
		}
	}
	return subtract;
}

Matrix Matrix::multiply(const Matrix m) const
{
	Matrix mul(this->rows, m.cols);
	for (int i = 0; i < mul.rows; i++)
	{
		for (int j = 0; j < mul.cols; j++)
		{
			mul.data[i][j] = 0;
		}
	}
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < m.cols; ++j)
		{
			for (int k = 0; k < this->cols; ++k)
			{
				mul.data[i][j] = mul.data[i][j]+(this->data[i][k] * m.data[k][j]);
			}
		}
	}
	return mul;
}

void Matrix::freeMemory()
{
	for (int i = 0; i < this->rows; i++)
	{
		delete[] this->data[i];
	}
	delete[] this->data;
}
