#pragma once
class Matrix
{
private:
	int rows;
	int cols;
	int **data;
public:
	Matrix();
	Matrix(const Matrix&);
	Matrix(int row, int col);
	~Matrix();
	void setRow(int);
	void setCol(int);
	int getRow() const;
	int getCol() const;
	void inputMatrix();
	int& at(const int r, const int c); 
	void printMatrix() const;
	bool isIdentity() const;
	bool isRectangular()const;
	bool isDiagonal()const;
	bool isNullMatrix() const;
	bool isLowerTriangular() const;
	bool isUpperTriangular() const;
	bool isTriangular()const;
	Matrix getMatrixCopy()const;
	bool isEqual(const Matrix m2) const;
	void reSize(const int newrow, const int newcol);
	bool isSymmetric() const;
	bool isSkewSymmetric()const;
	Matrix transpose() const;
	Matrix add(const Matrix) const;
	Matrix minus(const Matrix) const;
	Matrix multiply(const Matrix) const;
	void freeMemory();
	
};




