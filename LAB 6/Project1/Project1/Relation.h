#ifndef RELATION_H
#define RELATION_H 

#include "Set.h"
#include "OrderedPair.h"


class Relation
{
private:
	Set setA;
	OrderedPair *orderedPairList;
	int capacity;
	int noOfOrderedPair;
public:
	Relation();
	Relation(int, Set&);
	Relation(const Relation&);
	~Relation();
	Relation & operator=(const Relation &);
	void insert(const OrderedPair&);
	void remove(const OrderedPair&);
	int find(const OrderedPair &)const;
	int getCardinality()const;
	bool compare(const Relation &)const;
	bool isReflexive()const;
	bool isIrreflexive()const;
	bool isSymmetric()const;
	bool isAntiSymmetric()const;
	bool isTransitive()const;
	void print();
};


#endif