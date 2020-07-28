#ifndef MATRIXCLASS_H
#define MATRIXCLASS_H

class Matrix {
	private:
		int row;
		int col;
		int **data;
	public:
		Matrix();																	//done
		Matrix(const Matrix &);														//done
		Matrix(int, int);															//done
		//input wala ana hai function
		void inputArr();
		void setRow(int);															//done	
		void setCol(int);															//done
		int getRow() const;															//done
		int getCol() const;															//done
		int& at(const int r, const int c);												//?
		//For setting or getting some value at a particular location of matrix
		void printMatrix() const;													//done
		int isIdentity() const;														//done
		bool isRectangular()const ;													//done
		bool isDiagonal()const ;													//done
		bool isNullMatrix() const ;													//done
		bool isLowerTriangular() const;												//done
		bool isUpperTriangular() const;												//done
		bool isTriangular()const ;													//done
		Matrix getMatrixCopy()const;												//??????
		bool isEqual(const Matrix m2) const;										//done
		void reSize(const int newrow, const int newcol);							//done
		bool isSymmetric() const; 
		bool isSkewSymmetric()const ;
		Matrix Transpose() const;
		Matrix add(const Matrix ) const;  
		Matrix minus(const Matrix ) const;  
		Matrix multiply(const Matrix ) const;
		void freeMemory(); 

};

#endif









