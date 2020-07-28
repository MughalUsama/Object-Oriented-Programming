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
	Student student;
	ifstream fin("students.txt");
	int noOfStudents;
	if (!fin.fail())
	{
		fin >> noOfStudents;
		for (int i = 0; i < noOfStudents && !fin.eof(); i++)
		{
			fin >> student.rollNo;
			if (student.rollNo<0)
			{
				student.rollNo = -student.rollNo;
			}
			fin.getline(student.name,30);
			double totalMarks = 0;
			for (int j = 0; j < 5; j++)
			{
				fin >> student.marks[j];
				if (student.marks[j]<0 || student.marks[j]>100)
				{
					student.marks[j] = 0;
				}
				totalMarks += student.marks[j];
			}
			cout << "Roll no : " << student.rollNo << "\n";
			cout << "Name : " << student.name << "\n";
			cout << "Percentage : " << totalMarks/500*100 << "\n\n";
		}
		fin.close();
	}

	cout << "\n";
	system("pause");
	return 0;
}