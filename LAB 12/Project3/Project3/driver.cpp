#include <iostream>
#include <fstream>
#include "CString.h"
using namespace std;


void displaySingleLineComments();
void displayMultipleLineComments();




int main()
{
	cout << "Enter:\n 's' for single line comments \n 'm' for multiple line comments : ";
	char choice;
	cin >> choice;

	if (choice == 's' || choice == 'S')
	{
		displaySingleLineComments();
	}
	else if(choice == 'm' || choice == 'M')
	{
		displayMultipleLineComments();
	}
	else
	{
		cout << "You have entered wrong option.";
	}
	cout << "\n";
	system("pause");
	return 0;
}


void displaySingleLineComments()
{
	ifstream fin("input.cpp");
	ofstream fout("output.txt");
	CString comment;
	char ch;
	if (!fin.fail())
	{
		while (!fin.eof())
		{
			comment.~CString();
			fin >> ch;
			if (ch == '/')
			{
				fin.get(ch);
				if (ch == '/')
				{
					while (ch != '\n')
					{
						fin.get(ch);
						comment.concatEqual(ch);
					}
					fout << comment;
				}

			}

		}
	}
}

void displayMultipleLineComments()
{
	ifstream fin("input.cpp");
	ofstream fout("output.txt");
	CString comment;
	char ch;
	char ch1;
	while (!fin.eof())
	{
		fin >> ch;
		if (ch == '/')
		{
			fin.get(ch);
			if (ch == '*')
			{
				fin.get(ch);
				fin.get(ch1);
				while (ch != '*' || ch1 != '/')
				{
					comment.concatEqual(ch);
					ch = ch1;
					fin.get(ch1);
				}
				fout << comment;
			}

		}


	}
}
