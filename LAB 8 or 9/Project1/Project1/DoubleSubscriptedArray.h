#ifndef DOUBLE_SUBSCRIPTED_ARRAY_H
#define DOUBLE_SUBSCRIPTED_ARRAY_H

#include <iostream>
using namespace std;

class DoubleSubscriptedArray;

ostream & operator << (ostream & , DoubleSubscriptedArray  );
istream & operator >> (istream &, DoubleSubscriptedArray &);



class DoubleSubscriptedArray
{

private:

	int rows;
	int cols;
	int * data;
	
public:

	DoubleSubscriptedArray(int = 1, int = 1);
	DoubleSubscriptedArray(const DoubleSubscriptedArray &);
	~DoubleSubscriptedArray();
	int& operator[](int);
	DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray&);
	int& operator()(int, int);
	friend ostream & operator << (ostream & os, DoubleSubscriptedArray arr);
	friend istream & operator >> (istream & is, DoubleSubscriptedArray & arr);
	bool operator == (DoubleSubscriptedArray arr);
	bool operator != (DoubleSubscriptedArray arr);
};

#endif 










//	DoubleSubscriptedArray operator+(const DoubleSubscriptedArray&);
//	void operator+=(const DoubleSubscriptedArray &);