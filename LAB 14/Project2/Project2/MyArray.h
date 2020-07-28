#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
using namespace std;

class MyArray
{
private:
	int capacity;
	int noOfElements;
	int *data;
public:
	MyArray();
	MyArray(int size);
	~MyArray();
	void input();
	int & operator[](int index);
	MyArray& operator=(const MyArray & ref);
	MyArray operator+(const MyArray & ref);
	void operator+=(const MyArray & ref);

	class negSize
	{

	public:
		negSize()
		{
		}
		~negSize()
		{

		}
		void display()
		{
			cout << "Size cannot be negative or zero";
		}
	};
	class wrongSubscript
	{

	public:
		wrongSubscript()
		{
		}
		~wrongSubscript()
		{
		}
		void display()
		{
			cout << "Subscript is out of range";
		}
	};

};

#endif