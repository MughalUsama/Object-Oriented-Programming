#ifndef SINGLETON_H
#define SINGLETON_H

class SingleTon
{
private:
	static SingleTon* stptr;
	SingleTon();
public:
	static SingleTon* create();
	void desroy();
};

#endif
