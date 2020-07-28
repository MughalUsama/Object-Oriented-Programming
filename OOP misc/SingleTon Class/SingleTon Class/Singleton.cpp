#include"Singleton.h"

SingleTon* SingleTon:: stptr = nullptr;

SingleTon::SingleTon()
{

}

SingleTon* SingleTon::create()
{
	if (stptr == nullptr)
	{
		stptr = new SingleTon;
	}
	return stptr;
}

void SingleTon::desroy()
{
	if (stptr)
	{
		delete stptr;
		stptr = nullptr;
	}
}

