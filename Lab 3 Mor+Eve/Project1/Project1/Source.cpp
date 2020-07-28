#include <iostream>
using namespace std;

class Information
{
private:
	char name[50];
	char address[50];
	int age;
	long int phNo;

public:
	void setName(char * enteredName);
	void setAddress(char * enteredAddress);
	void setAge(int enteredAge);
	void setPhNo(long int phoneNo);
	char* getName();
	char * getAddress();
	int getAge();
	long int getPhNo();
};

void inputInformation(Information &person);
void displayInformation(Information &person);


int main()
{
	Information my, family, friend1;
	inputInformation(my);
	inputInformation(family);
	inputInformation(friend1);

	displayInformation(my);
	displayInformation(family);
	displayInformation(friend1);

	cout << "\n";
	system("pause");
	return 0;
}

void Information::setName(char * enteredName)
{
	strcpy_s(name, enteredName);
}

void Information::setAddress(char * enteredAddress)
{
	strcpy_s(address, enteredAddress);
}

void Information::setAge(int enteredAge)
{
	age = enteredAge;
}

void Information::setPhNo(long int phoneNo)
{
	phNo = phoneNo;
}

char * Information::getName()
{
	return name;
}

char * Information::getAddress()
{
	return address;
}

int Information::getAge()
{
	return age;
}

long int Information::getPhNo()
{
	return phNo;
}








void inputInformation(Information &person)
{
	char pName[50], pAddress[50];
	int pAge;
	long int phone;

	cout << "\nEnter the name :";
	cin>>pName;
	person.setName(pName);
	cout << "Enter the address :";
	cin>>pAddress;
	person.setAddress(pAddress);
	cout << "Enter the age : ";
	cin >> pAge;
	person.setAge(pAge);
	cout << "Enter Phone no : ";
	cin >> phone;
	person.setPhNo(phone);
}
void displayInformation(Information &person)
{

	cout << "\n\nName : "<<	person.getName();
	cout << "\nAddress :" <<	person.getAddress();
	cout << "\nAge : " << person.getAge();
	cout << "\nPhone no : " <<	person.getPhNo();
}






/**/