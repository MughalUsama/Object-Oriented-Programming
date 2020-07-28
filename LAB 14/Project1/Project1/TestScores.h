#ifndef TESTSCORES_H
#define TESTSCORES_H
class TestScores
{
private:
	int * data;
	int size;
public:
	TestScores(int *,int);
	~TestScores();
	double arrayAverage();
};

#endif