#include <iostream>
#include "Set.h"

using namespace std;

Set::Set()
{
	capacity = 0;
	noOfElements = 0;
	data = nullptr;
}

Set::Set(int cap)
{
	if (cap <= 0)
	{
		this->capacity = 5;
	}
	else
	{
		this->capacity = cap;
	}
	this->noOfElements = 0;
	this->data = new int[this->capacity];
}

Set::Set(const Set & ref)
{
	cout << "cpy";
	this->capacity = ref.capacity;
	this->noOfElements = ref.noOfElements;
	this->data = new int[capacity];
	for (int i = 0; i <noOfElements; i++)
	{
		this->data[i] = ref.data[i];
	}
}


Set::~Set()
{
	if (this->data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

Set &Set::operator=(const Set &ref)
{
	if (this != &ref)
	{
		delete[] this->data;
		this->capacity = ref.capacity;
		this->noOfElements = ref.noOfElements;
		this->data = new int[this->capacity];
		for (int i = 0; i < this->noOfElements; i++)
		{
			this->data[i] = ref.data[i];
		}
	}
	return *this;

}


void Set::insert(int element)
{
	if (this->capacity != this->noOfElements)
	{
		this->data[noOfElements] = element;
		this->noOfElements = this->noOfElements + 1;
	}
}

void Set::remove(int element)
{
	for (int i = 0; i < noOfElements; i++)
	{
		if (this->data[i] == element)
		{
			for (int j = i; j < noOfElements - 1; j++)
			{
				this->data[j] = this->data[j + 1];
			}
			this->noOfElements = this->noOfElements - 1;
		}
	}
}

int & Set::getElement(int index) const
{
	return this->data[index];
}

int Set::getCardinality()const
{
	return this->noOfElements;
}

Set Set::calcUnion(Set & s)
{
	Set s1(this->noOfElements + s.noOfElements);
	int index = 0;;
	for (int i = 0; i < this->noOfElements; i++)
	{
		s1.data[index] = this->data[i];
		index = index + 1;
	}
	for (int i = 0; i < s.noOfElements; i++)
	{
		s1.data[index] = s.data[i];
		index = index + 1;
	}
	s1.noOfElements = index;
	return s1;
}

Set Set::calcIntersection(Set &s)
{
	int commonElements = 0;
	for (int i = 0; i < this->noOfElements; i++)
	{
		for (int j = 0; j < s.noOfElements; j++)
		{
			if (this->data[i] == s.data[j])
			{
				commonElements = commonElements + 1;
			}
		}
	}
	Set s1(commonElements);
	int index = 0;
	for (int i = 0; i < this->noOfElements; i++)
	{
		for (int j = 0; j < s.noOfElements; j++)
		{
			if (this->data[i] == s.data[j])
			{
				s1.data[index] = s.data[j];
				index = index + 1;
			}
		}
	}
	s1.noOfElements = commonElements;
	return s1;
}

Set Set::calcSymmetricDifference(Set &s)
{
	Set unionSet, intersectionSet;
	unionSet = this->calcUnion(s);
	intersectionSet = this->calcIntersection(s);
	Set symDif(unionSet.noOfElements - intersectionSet.noOfElements);

	int index = 0;

	for (int i = 0; i < unionSet.noOfElements; i++)
	{
		bool found = false;
		for (int j = 0; j < intersectionSet.noOfElements; j++)
		{
			if (unionSet.data[i] == intersectionSet.data[j])
			{
				found = true;
			}
		}
		if (!found)
		{
			symDif.data[index] = unionSet.data[i];
			index = index + 1;
		}
		symDif.noOfElements = index + 1;
	}
	return symDif;
}


Set Set::calcDifference(Set &s)
{
	Set difference(this->noOfElements - ((this->calcIntersection(s).noOfElements)));

	int index = 0;

	for (int i = 0; i < this->noOfElements; i++)
	{
		bool found = false;
		for (int j = 0; j < s.noOfElements; j++)
		{
			if (this->data[i] == s.data[j])
			{
				found = true;
			}
		}
		if (!found)
		{
			difference.data[index] = this->data[i];
			index = index + 1;
		}
		difference.noOfElements = index;
	}
	return difference;
}

int Set::isMember(int value)
{
	for (int i = 0; i < this->noOfElements; i++)
	{
		if (value == this->data[i])
		{
			return 1;
		}
	}
	return 0;
}

int Set::isSubSet(Set &s)
{
	if (this->noOfElements<s.noOfElements)
	{
		return 0;
	}

	int commonElements = 0;
	for (int i = 0; i < s.noOfElements; i++)
	{
		for (int j = 0; j < this->noOfElements; j++)
		{
			if (this->data[j] == s.data[i])
			{
				commonElements = commonElements + 1;
			}
		}
	}
	if (commonElements == this->noOfElements)
	{
		return 2;
	}
	else if (commonElements < this->noOfElements && commonElements == s.noOfElements)
	{
		return 1;
	}

	return 0;
}

void Set::reSize(int newCapacity)
{
	int * dt = new int[newCapacity];
	for (int i = 0; i < this->noOfElements; i++)
	{
		dt[i] = this->data[i];
	}
	delete[] this->data;
	this->data = dt;
}

void Set::displaySet()
{
	cout << "\n{ ";
	for (int i = 0; i < this->noOfElements; i++)
	{
		cout << this->data[i] << " ";
	}
	cout << "}";
}
