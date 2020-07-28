#include "TestScores.h"



TestScores::TestScores(int *arr,int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i]<0 || arr[i]>100)
		{
			throw "Scores can not be negative or greater than 100";
		}
	}
	this->data = arr;
	this->size = arrSize;
}


TestScores::~TestScores()
{
}

double TestScores::arrayAverage()
{
	double total=0;
	for (int i = 0; i <this->size; i++)
	{
		total += this->data[i];
	}
	return total/this->size;
}

