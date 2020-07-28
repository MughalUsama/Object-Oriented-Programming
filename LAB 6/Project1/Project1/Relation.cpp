#include "Relation.h"
#include <iostream>

using namespace std;


Relation::Relation()
{
	this->orderedPairList = nullptr;
	this->capacity = 0;
	this->noOfOrderedPair = 0;
}

Relation::Relation(int cap, Set & setB): setA(setB)
{
	this->capacity = cap;
	this->orderedPairList = new OrderedPair[capacity];
	this->noOfOrderedPair = 0;
}

Relation::Relation(const Relation & ref): setA(ref.setA)
{

	this->capacity = ref.capacity;
	for (int i = 0; i < ref.noOfOrderedPair; i++)
	{
		this->orderedPairList[i] = ref.orderedPairList[i];
	}
}

Relation::~Relation()
{
	delete[] this->orderedPairList;
}

Relation & Relation::operator=(const Relation &ref)
{
	if (this!=&ref)
	{
		this->capacity = ref.capacity;
		this->noOfOrderedPair = ref.noOfOrderedPair;
		this->orderedPairList = new OrderedPair[this->noOfOrderedPair];
		for (int i = 0; i < this->noOfOrderedPair; i++)
		{
			this->orderedPairList[i] = ref.orderedPairList[i];
		}
	}
	return *this;
}


void Relation::insert(const OrderedPair & oP)
{
	bool found = false;
	int noOfSetElements = this->setA.getCardinality();
	for (int i = 0; i < noOfSetElements; i++)
	{
		if (this->setA.isMember(oP.getElementA()) || this->setA.isMember(oP.getElementB()))
		{
			found = true;
		}
	}
	if (find(oP)==-1 && this->capacity != this->noOfOrderedPair && found)
	{
		this->orderedPairList[noOfOrderedPair] = oP;
		this->noOfOrderedPair = this->noOfOrderedPair + 1;
	}
}


void Relation::remove(const OrderedPair &oP)
{
	int index = find(oP);
	if (index!=-1)
	{
		for (int i = index; i < this->noOfOrderedPair-1; i++)
		{
			this->orderedPairList[i] = this->orderedPairList[i + 1];
		}
		noOfOrderedPair = noOfOrderedPair - 1;

	}
}

int Relation::find(const OrderedPair & oP)const
{
	for (int i = 0; i < this->noOfOrderedPair; i++)
	{
		if (oP.getElementA()== this->orderedPairList[i].getElementA() && oP.getElementB() == this->orderedPairList[i].getElementB())
		{
			return i;
		}
	}
	return -1;
}

int Relation::getCardinality()const
{
	return this->noOfOrderedPair;
}

bool Relation::compare(const Relation & ref) const
{
	if (this->getCardinality()!= ref.getCardinality())
	{
		return false;
	}
	for (int i = 0; i < this->getCardinality(); i++)
	{
		if (find(ref.orderedPairList[i])==-1)
		{
			return false;
		}
	}
	return true;
}

bool Relation::isReflexive() const
{
	int noOfSetELements = this->setA.getCardinality();
	int count = 0;
	for (int i = 0; i < noOfSetELements; i++)
	{
		for (int j = 0; j < this->noOfOrderedPair; j++)
		{
			if (orderedPairList[j].getElementA()==this->setA.getElement(i) && orderedPairList[j].getElementB() == this->setA.getElement(i))
			{
				count = count + 1;
			}
		}
	}
	if (count==noOfSetELements)
	{
		return true;
	}
	return false;
}

bool Relation::isIrreflexive() const
{
	int noOfSetELements = this->setA.getCardinality();
	int count = 0;
	for (int i = 0; i < noOfSetELements; i++)
	{
		for (int j = 0; j < this->noOfOrderedPair; j++)
		{
			if (orderedPairList[j].getElementA() == this->setA.getElement(i) && orderedPairList[j].getElementB() == this->setA.getElement(i))
			{
				count = count + 1;
			}
		}
	}
	if (count == 0)
	{
		return true;
	}
	return false; 
}

bool Relation::isSymmetric() const
{
	for (int i = 0; i < this->noOfOrderedPair; i++)
	{
		OrderedPair oP(this->orderedPairList[i].getElementB(), this->orderedPairList[i].getElementA());
		if (find(oP)==-1)
		{
			return false;
		}
	}
	return true;
}

bool Relation::isAntiSymmetric() const
{
	for (int i = 0; i < this->noOfOrderedPair; i++)
	{
		OrderedPair oP(this->orderedPairList[i].getElementB(), this->orderedPairList[i].getElementA());
		if (find(oP) != -1 && this->orderedPairList[i].getElementB()!= this->orderedPairList[i].getElementA())
		{
			return false;
		}
	}
	return true;
}

bool Relation::isTransitive() const
{
	for (int i = 0; i < this->noOfOrderedPair; i++)
	{
		for (int j = 0; j < noOfOrderedPair; j++)
		{
			if (this->orderedPairList[i].getElementB()== this->orderedPairList[j].getElementA())
			{
				OrderedPair oP(this->orderedPairList[i].getElementA(), this->orderedPairList[j].getElementB());
				if (find(oP) == -1)
				{
					return false;
				}
			}

		}
	}
	return true;
}

void Relation::print()
{
	cout << "{ ";
	for (int i = 0; i < this->noOfOrderedPair; i++)
	{
		cout << "(" << this->orderedPairList[i].getElementA() << "," << orderedPairList[i].getElementB()<< ")";
		if (i!=noOfOrderedPair-1)
		{
			cout << ",";
		}
	}
	cout << " }";
}

