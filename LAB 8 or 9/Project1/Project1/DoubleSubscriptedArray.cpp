#include<iostream>
using namespace std;

#include"DoubleSubscriptedArray.h"



DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c)
{
	rows = r;
	cols = c;
	data = new int[r*c];
	
}

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray & ref)
{
	rows = ref.rows;
	cols = ref.cols;
	if (ref.data != nullptr)
	{
		data = new int[rows*cols];
		for (int i = 0; i < rows*cols; i = i + 1)
		{
			data[i] = ref.data[i];
		}
	}
	else
	{
		data = ref.data;
	}

}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
	rows = 0;
	cols = 0;
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

int & DoubleSubscriptedArray::operator[](int index)
{
	if (index >= 0 && index < rows*cols && data != nullptr)
	{
		return data[index];
	}
	exit(0);
}

DoubleSubscriptedArray & DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray & ref)
{
	if (this != &ref && ref.data != nullptr)
	{
		this->~DoubleSubscriptedArray();
		this->rows = ref.rows;
		this->cols = ref.cols;
		this->data = new int[rows*cols];
		for (int i = 0; i < rows*cols; i = i + 1)
		{
			this->data[i] = ref.data[i];
		}
	}
	else if(ref.data == nullptr)
	{
		this->~DoubleSubscriptedArray();
	}
	return *this;
}

int & DoubleSubscriptedArray::operator()(int r, int c)
{
	if (r<rows && c<cols)
	{
		return this->data[r*this->cols + c];
	}
	exit(0);
}

bool DoubleSubscriptedArray::operator==(DoubleSubscriptedArray arr)
{
	if (this->cols == arr.cols && this->rows == arr.rows)
	{
		for (int i = 0; i < this->rows*this->cols; i++)
		{
			if (this->data[i] != arr.data[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool DoubleSubscriptedArray::operator!=(DoubleSubscriptedArray arr)
{
	if (this->cols == arr.cols && this->rows == arr.rows)
	{
		for (int i = 0; i < this->rows*this->cols; i++)
		{
			if (this->data[i] != arr.data[i])
			{
				return true;
			}
		}
		return false;
	}
	return true;

}

ostream &  operator<<(ostream & os, DoubleSubscriptedArray arr)
{
	for (int i = 0; i < arr.rows; i++)
	{
		for (int j = 0; j < arr.cols; j++)
		{
			cout << arr(i, j) << " ";
		}
		cout << "\n";
	}
	return os;
}

istream & operator>>(istream & is, DoubleSubscriptedArray & arr)
{
	for (int i = 0; i < arr.rows; i++)
	{
		for (int j = 0; j < arr.cols; j++)
		{
			cin >> arr(i, j);
		}
	}
	return is;
}




























//DoubleSubscriptedArray DoubleSubscriptedArray::operator+(const DoubleSubscriptedArray & ref)
//{
//	DoubleSubscriptedArray  arr;
//	if (this->data != nullptr && ref.data != nullptr)
//	{
//		arr.~DoubleSubscriptedArray();
//		arr.capacity = this->capacity + ref.capacity;
//		arr.noOfElements = this->noOfElements + ref.noOfElements;
//		arr.data = new int[arr.capacity];
//		int count = 0;
//		for (int i = 0; i < noOfElements; i = i + 1)
//		{
//			arr.data[count] = data[i];
//			count = count + 1;
//		}
//		for (int i = 0; i < ref.noOfElements; i = i + 1)
//		{
//			arr.data[count] = ref.data[i];
//			count = count + 1;
//		}
//
//	}
//	else if (ref.data != nullptr)
//	{
//		arr = *this;
//	}
//	else if (this->data != nullptr)
//	{
//		arr = ref;
//	}
//	return arr;
//}

//void DoubleSubscriptedArray::operator+=(const DoubleSubscriptedArray & ref)
//{
//	if (this->data != nullptr && ref.data != nullptr)
//	{
//		int*dataa = this->data;
//		this->capacity = this->capacity + ref.capacity;
//		this->noOfElements = this->noOfElements + ref.noOfElements;
//		this->data = new int[this->capacity];
//		int count = 0;
//		for (int i = 0; i < noOfElements; i = i + 1)
//		{
//			this->data[count] = dataa[i];
//			count = count + 1;
//		}
//		for (int i = 0; i < ref.noOfElements; i = i + 1)
//		{
//			this->data[count] = ref.data[i];
//			count = count + 1;
//		}
//		delete[] dataa;
//		dataa = nullptr;
//	}
//	else if (this->data != nullptr)
//	{
//		*this = ref;
//	}
//}

