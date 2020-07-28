#include<iostream>
#include"Set.h"

using namespace std;

 Set::Set ( int cap)
 {

	 //cout<<"Default Constructor called\n";

	 capacity = cap;
	 noOfElements = 0;
	 data = new int [capacity];

	 for(int i=0;i<capacity;i=i+1)
	 {
		 data[i] = 0;
	 }

 }
 Set::Set( Set & ref) 
 {

	 cout<<"Copy Constructor called\n";

	 capacity = ref.capacity;
	 noOfElements = ref.noOfElements;
	 data = new int[capacity];

	 for(int i=0;i<noOfElements;i=i+1)
	 {
		 data[i] = ref.data[i];
	 }

 }
 Set::~Set()
 {

	// cout << "Destructor called\n";

	 delete[] data;

 }
 void Set::setCapacity(int cap)
 {

	 capacity = cap;
	 noOfElements = 0;
	 data = new int[capacity];

 }
 int Set::getCapacity()
 {

	 return capacity;

 }
 void Set::insert ( int element)
 {

	if ( !isFull()  &&  isUniqoe(element) )
	{

		int i = noOfElements;  //i is counter for elements in Set
		data[i] = element;
		noOfElements = noOfElements + 1;

	}

}
 bool Set::isFull()
{

	if (noOfElements == capacity)
	{
		return true;
	}

	return false;

}
 bool Set::isEmpty()
{

	if (noOfElements == 0)
	{
		return  true;
	}

	return  false;
}
 bool Set::isUniqoe(int ele)
{

	int i = 0;

	while ( i < noOfElements && data[i] != ele )
	{
		i = i + 1;
	}

	if (i == noOfElements)
	{
		return  true;
	}

	return  false;

}
 void Set::remove ( int element)
 {

	if ( !isEmpty() )
	{

		if ( searchElement( element ) )
		{

			int index = searchElementPosition( element );

			while ( index < noOfElements )
			{

				data[index] = data[index + 1];
				index = index + 1;

			}
			noOfElements = noOfElements - 1;

		}

	}

 }
 bool Set::searchElement(int element)
{

	int i = 0;

	while ( i < noOfElements)
	{

		if (data[i] == element)
		{
			return  true;
		}
		i = i + 1;

	}

	return  false;

}
 int Set::searchElementPosition(int element)
{

	if( searchElement ( element ) )
	{

		int i = 0;

		while ( i <= noOfElements )
		{

			if ( data[i] == element )
			{
				return i;
			}

			i = i + 1;

		}

	}

	return -1;

}
 int Set::getCardinality() 
 {

	 return  noOfElements;

 }
 Set Set::calcUnion ( Set & s2 )
 {

	Set s1;
	s1.noOfElements = 0;
	s1.capacity = noOfElements + s2.noOfElements;
	s1.data = new int [ s1.capacity ];

	for ( int i = 0; i < noOfElements; i = i + 1 )
	{
		s1.insert( data[i] );
	}

	for ( int i = 0; i < s2.noOfElements; i = i + 1 )
	{
		s1.insert( s2.data[i] );
	}

	return s1;

 }
 Set Set::calcIntersection ( Set & s2 )
 {

	Set s1;

	if( noOfElements>s2.noOfElements )
	{

		s1.capacity = noOfElements;
		s1.noOfElements = 0;;
		s1.data = new int [ s1.capacity ];

	}
	else
	{

		s1.capacity = s2.noOfElements;
		s1.noOfElements = 0;
		s1.data = new int [ s1.capacity ];

	}

	for ( int i = 0; i < noOfElements; i = i + 1 )
	{

		for ( int j = 0; j < s2.noOfElements; j = j + 1 )
		{

			if ( data[i] == s2.data[j] )
			{
				s1.insert(data[i]);
			}

		}

	}

	return s1;

 }
 Set Set::calcDifference ( Set & s2 ) 
 {

	 Set s1;
	 s1.capacity = noOfElements;
	 s1.noOfElements = 0;
	 s1.data = new int [ s1.capacity ];

	 for (int i = 0; i<noOfElements; i = i + 1)
	 {

		int j = 0;

		while (j < s2.noOfElements)
		{

			(s2.data[j] != data[i]) ? j = j + 1 : j = s2.noOfElements + 1;
			if (j == s2.noOfElements)
			{
				s1.insert(data[i]);
			}

		}

	 }

	return s1;

 }
 Set Set::calcSymmetricDifference ( Set & s2 ) 
 {

	 Set sp=calcUnion( s2 );

	 Set sq=calcIntersection( s2 );

	 Set s1 = sp.calcDifference( sq );

	 return s1;

 }
 int Set::isMember ( int val )
 {
	 if (!isEmpty())
	 {
		if (searchElement(val))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	 }
	 return 0;
 }
 int Set::isSubSet ( Set & s2 )
 {
	int count = 0;
	for (int i = 0; i<noOfElements; i = i + 1)
	{
		for (int j = 0; j<s2.noOfElements; j = j + 1)
		{
			if (s2.data[i] == data[j])
			{
				count = count + 1;
			}
		}
	}
	if (count == s2.noOfElements&&noOfElements>s2.noOfElements)
	{
		return 1;
	}
	else if (count == s2.noOfElements&&noOfElements==s2.noOfElements)
	{
		return 2;
	}
	return 0;
 }
 void Set::reSize ( int newcapacity )
 {
	Set s1;
	s1.data = data;
	s1.noOfElements=noOfElements;
	capacity=newcapacity;
	data=new int[capacity];
	noOfElements=0;

	for (int i = 0; i<s1.noOfElements; i = i + 1)
	{
		insert(s1.data[i]);
	}

 }
 void Set::freeMemory() 
 {
	 delete data;
	 data=nullptr;
 }