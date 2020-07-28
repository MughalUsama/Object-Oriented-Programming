#include "MyArray.h"
#include <iostream>
using namespace std;



MyArray::MyArray()
{
	this->capacity = 5;
	this->noOfElements = 0;
	this->data = new int[5];
}

MyArray::MyArray(int size)
{
	if (size<1)
	{
		throw (negSize());
	}
	this->capacity = size;
	this->noOfElements = 0;
	this->data = new int[size];
}


MyArray::~MyArray()
{
	this->capacity = 0;
	this->noOfElements = 0;
	delete[] this->data;
}

void MyArray::input()
{
	for (int i = 0; i < this->capacity; i++)
	{
		cout << "Enter element no " << i + 1 << ": ";
		cin >> this->data[i];
	}
	noOfElements = this->capacity;
}

int & MyArray::operator[](int index)
{
	if (index >= 0 && index < capacity && data != nullptr)
	{
		return data[index];
	}
	throw wrongSubscript();
}

MyArray & MyArray::operator=(const MyArray & ref)
{
	if (this != &ref && ref.data != nullptr)
	{
		this->~MyArray();
		this->capacity = ref.capacity;
		this->noOfElements = ref.noOfElements;
		this->data = new int[this->capacity];
		for (int i = 0; i < noOfElements; i = i + 1)
		{
			this->data[i] = ref.data[i];
		}

	}
	else
	{
	
		this->~MyArray();
		this->capacity = ref.capacity;
		this->noOfElements = ref.noOfElements;
	}
	return *this;
}

MyArray MyArray::operator+(const MyArray & ref)
{
	MyArray  arr;
	if (this->data != nullptr && ref.data != nullptr)
	{
		arr.~MyArray();
		arr.capacity = this->capacity + ref.capacity;
		arr.noOfElements = this->noOfElements + ref.noOfElements;
		arr.data = new int[arr.capacity];
		int count = 0;
		for (int i = 0; i < noOfElements; i = i + 1)
		{
			arr.data[count] = data[i];
			count = count + 1;
		}
		for (int i = 0; i < ref.noOfElements; i = i + 1)
		{
			arr.data[count] = ref.data[i];
			count = count + 1;
		}

	}
	else if (ref.data != nullptr)
	{
		arr = *this;
	}
	else if (this->data != nullptr)
	{
		arr = ref;
	}
	return arr;

}

void MyArray::operator+=(const MyArray & ref)
{
	if (this->data != nullptr && ref.data != nullptr)
	{
		int*dataa = this->data;
		this->capacity = this->capacity + ref.capacity;
		this->noOfElements = this->noOfElements + ref.noOfElements;
		this->data = new int[this->capacity];
		int count = 0;
		for (int i = 0; i < noOfElements; i = i + 1)
		{
			this->data[count] = dataa[i];
			count = count + 1;
		}
		for (int i = 0; i < ref.noOfElements; i = i + 1)
		{
			this->data[count] = ref.data[i];
			count = count + 1;
		}
		delete[] dataa;
		dataa = nullptr;
	}
	else if (this->data != nullptr)
	{
		*this = ref;
	}
}
