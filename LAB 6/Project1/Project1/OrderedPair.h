#ifndef ORDERED_PAIR_H
#define ORDERED_PAIR_H


class OrderedPair
{
private:
	int a;
	int b;
public:
	OrderedPair(int n=0, int m=0);
	int getElementA()const;
	int getElementB()const;
	void print();
	bool isEqual(const OrderedPair &)const;
};

#endif