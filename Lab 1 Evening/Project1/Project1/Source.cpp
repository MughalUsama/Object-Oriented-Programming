#include <iostream>
using namespace std;

void concatenate(char *string1, char *string2);


int main()
{
	char string1[10], string2[10];
	cout << "\nEnter string 1: ";
	cin.getline(string1,10);
	cout << "Enter string 2: ";
	cin.getline(string2,10);
	concatenate(string1, string2);

	cout << "\n";
	system("pause");
	return 0;

}

void concatenate(char *string1, char *string2)
{
	char string3[20];
	int i = 0;
	while (string1[i]!='\0')
	{
		string3[i] = string1[i];
		i = i + 1;
	}
	int j = 0;
	while (string2[j] != '\0')
	{
		string3[i] = string2[j];
		j = j + 1;
		i = i + 1;
	}
	string3[i] = string2[j];

	cout << "Concatenated String is : " << string3;
}