#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
	int rollNo;
	char name[31];
	int marks[5];
};



int main()
{

	fstream file("students.txt",ios::in);

	cout << "\n";
	system("pause");
	return 0;
}



