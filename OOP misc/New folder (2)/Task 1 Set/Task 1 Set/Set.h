#ifndef SET_H
#define SET_H

class Set
{
private:   //private Data members and methods

	int*data;
	int noOfElements;
	int capacity;
	bool isFull();
	bool isEmpty();
	bool isUniqoe(int );
	int searchElementPosition(int);
	bool searchElement(int element);

public:   //public Constructors , Destructor, and methods

	 Set ( int = 5 ); 
	 Set( Set & ref);
	 ~Set();
	 void setCapacity(int);
	 int getCapacity();
	 void insert ( int element); 
	 void remove ( int element); 
	 int getCardinality();
	 Set calcUnion ( Set & s2 );
	 Set calcIntersection ( Set & s2 );
	 Set calcDifference ( Set & s2 ) ;
	 Set calcSymmetricDifference ( Set & s2 ); 
	 int isMember ( int val );
	 int isSubSet ( Set & s2 );
	 void reSize ( int newcapacity );
	 void freeMemory();
};

#endif