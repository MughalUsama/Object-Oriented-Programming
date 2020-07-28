#include<iostream>
using namespace std;
class Test
{
public:
	int i;
	double d;
public:


};
int main()
{
	Test t1(1,2);
	//Test t2 = 5;
	//Test(10);
	//(Test)99;
//	Test t6 = t1;
	//Test *tPtr = new Test[2]{ Test(1,1.2) };
	cout << t1.i;
	//delete[] tPtr;

	system("pause");

	return 0;
}