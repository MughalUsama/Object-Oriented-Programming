#include <iostream>
using namespace std;

struct Course
{
	char course_name[100];
	double obtained_marks;
	double total_marks;
};

struct Result
{
	int student_id;
	int num_of_courses;
	Course * courseList;
	double percentage;
};

void computeAllResult(Result *allResult, int size);
void computeOneResult(Result * ptrResult);
void inputResult(Result * allResult, int size);
void inputCourses(Result * allResult, int size);
void displayAllResult(Result * allResult, int size);


int main()
{
	Result allResult[5];

	//adding courses
	inputCourses(allResult, 5);
	
	//taking obt marks
	inputResult(allResult,5);
	
	//computing results
	computeAllResult(allResult,5);
	
	//displaying results
	displayAllResult(allResult, 5);

	cout << "\n";
	system("pause");
	return 0;
}

void computeAllResult(Result * allResult, int size)
{
	for (int k = 0; k < size; k++)
	{
		computeOneResult(&allResult[k]);
	}
}

void computeOneResult(Result * ptrResult)
{
	double totalMarks = 0, totalObtMarks = 0;
	for (int j = 0; j < ptrResult->num_of_courses; j++)
	{
		totalMarks = ptrResult->courseList[j].total_marks;
		totalObtMarks= ptrResult->courseList[j].obtained_marks;
	}
	ptrResult->percentage = (totalObtMarks / totalMarks) * 100;
}


void inputCourses(Result * allResult,int size)
{
	int totalCourses;
	cout << "\n\t\t\t\tEnter total no of courses: ";
	cin >> totalCourses;
	for (int i = 0; i < size; i++)
	{
		allResult[i].num_of_courses = totalCourses;
		allResult[i].courseList = new Course[totalCourses];
	}
	for (int i = 0; i <totalCourses ; i++)
	{
		cout << "\nEnter course no : " << i + 1;
		cout << "\nCourse name : ";
		cin >> allResult[0].courseList[i].course_name;
		cout << "Enter total marks : ";
		cin >> allResult[0].courseList[i].total_marks;
	}
	for (int j = 1; j < size; j++)
	{
		for (int k = 0; k < totalCourses; k++)
		{
			allResult[j].courseList[k] = allResult[0].courseList[k];
		}
	}
}


void inputResult(Result * allResult, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\n\n\t\t\t\tEnter the Student ID : ";
		cin >> allResult[i].student_id;
		cout << "\n\t\t\t\tEnter the marks for " << allResult[i].student_id;
		for (int j = 0; j < allResult[0].num_of_courses; j++)
		{
			cout << "\nEnter the obtained marks in " << allResult[i].courseList[j].course_name << " : ";
			cin >> allResult[i].courseList[j].obtained_marks;
		}
	}
}

void displayAllResult(Result * allResult, int size)
{
	cout << "\n\n\t\t\t\t<:Percentage of all students:>";
	for (int i = 0; i < size; i++)
	{
		cout << "\nPercentage of Student ID : " << allResult[i].student_id << " = " << allResult[i].percentage;
	}
}