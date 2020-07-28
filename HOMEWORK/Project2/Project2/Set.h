#ifndef SET_H
#define SET_H



class Set
{
	private:
		int *data;
		int noOfElements;
		int capacity;
	public:
		Set();
		Set(int);
		Set(const Set &);
		~Set();
		Set & operator=(const Set&);
		void insert(int);
		void remove(int);
		int getCardinality();
		Set calcUnion(Set &);
		Set calcIntersection(Set &);
		Set calcSymmetricDifference(Set &);
		Set calcDifference(Set & );
		int isMember(int);
		int isSubSet(Set &);
		void reSize(int);
		void displaySet();
};



#endif