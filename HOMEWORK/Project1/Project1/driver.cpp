#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{
	Matrix mat(5,1);
	Matrix mat1(1, 5);
	mat.inputMatrix();
	mat1.inputMatrix();
	
	Matrix m = mat1.multiply(mat);
	m.printMatrix();
	cout << "\n";
	system("pause");
	return 0;
}