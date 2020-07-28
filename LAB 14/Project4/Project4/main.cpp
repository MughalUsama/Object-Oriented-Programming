#include <iostream>
#include <fstream>

using namespace std;
#include "Customer.h"

Customer& input();
void enterRecord();
void searchRecord();
void deleteRecord();
void changeRecord();
void displayFile();

int main()
{
	int choice=0;
	
	do
	{
		cout << "\t\t\t\tEnter 1 for new record.\n";
		cout << "\t\t\t\tEnter 2 for search and display.\n";
		cout << "\t\t\t\tEnter 3 for search and delete.\n";
		cout << "\t\t\t\tEnter 4 search and change.\n";
		cout << "\t\t\t\tEnter 5 to display entire file.\n";
		cout << "\t\t\t\tEnter 6 to Exit.  \n";
		cout << "Your choice : ";
		cin >> choice;
		while(cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n');
			cout << "Wrong Choice ! Select From the List ! : ";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			cin.ignore();
			enterRecord();
			break;
		case 2:
			searchRecord();
			break;
		case 3:
			deleteRecord();
			break;
		case 4:
			changeRecord();
			break;
		case 5:
			displayFile();
			break;
		default:
			break;
		}

	} while (choice!=6);

	cout << "\n";
	system("pause");
	return 0;
}

void enterRecord()
{
	
	try
	{
		Customer customer = input();
		fstream fileout("customer.dat", ios::out | ios::binary |ios :: app);
		fileout.write((reinterpret_cast<char *>(&customer)),sizeof(customer));
		fileout.close();
		cout << "\n\t\t\t\t\tRecord Added!\n\n";
	}
	catch (const char msg[])
	{
		cout << msg;
	}

}
void searchRecord()
{

	bool recordFound = false;
	Customer customer;
	char searchName[30];
	cin.ignore();
	cout << "\nEnter the name to search : ";
	cin.getline(searchName, 29);
	fstream filein("customer.dat", ios::in | ios::binary);
	filein.read((reinterpret_cast<char *>(&customer)), sizeof(customer));
	while (!filein.eof())
	{
		
		if (strcmp(customer.name, searchName) == 0)
		{
			recordFound = true;
			cout << "\n\t\t\t\tRecord found\n";
			cout << "\t\t\t\tName : "<<customer.name;
			cout << "\n\t\t\t\tAddress : "<<customer.address;
			cout << "\n\t\t\t\tCityStateZip : "<<customer.cityStateZip;
			cout << "\n\t\t\t\tTelephoneNo : " << customer.telephoneNo;
			cout << "\n\t\t\t\tAccountBalance : " << customer.accountBalance;
			cout << "\n\t\t\t\tLast payment date : " << customer.date<<"\n\n";
		}
		filein.read((reinterpret_cast<char *>(&customer)), sizeof(customer));
	}
	if (!recordFound)
	{
		cout << "\n\t\t\t\t\tRecord not found!\n\n";
	}
	filein.close();
	
}
void deleteRecord()
{

	bool recordFound = false;
	Customer customer;
	char searchName[30];
	cin.ignore();
	cout << "\nEnter the name to remove : ";
	cin.getline(searchName, 29);
	fstream filein("customer.dat", ios::in | ios::binary);
	if (filein.good())
	{
		fstream newFile("new.dat", ios::out | ios::binary);
		filein.read((reinterpret_cast<char *>(&customer)), sizeof(customer));
		while (!filein.eof())
		{
			if (strcmp(customer.name, searchName) != 0)
			{
				newFile.write((reinterpret_cast<char *>(&customer)), sizeof(customer));
			}
			else
			{
				recordFound = true;
			}
			filein.read((reinterpret_cast<char *>(&customer)), sizeof(customer));
		}
		newFile.close();
		filein.close();
		remove("customer.dat");
		rename("new.dat", "customer.dat");
		if (!recordFound)
		{
			cout << "\n\t\t\t\t\tRecord not found!\n\n";
		}
		else
		{
			cout << "\n\t\t\t\t\tRecord deleted!\n\n";
		}
	}
}
void changeRecord()
{

	bool recordFound = false;
	Customer customer;
	char searchName[30];
	cin.ignore();
	cout << "\nEnter the name to change : ";
	cin.getline(searchName, 29);
	fstream filein("customer.dat", ios::in | ios::binary);
	if (filein.good())
	{
		fstream newFile("new.dat", ios::out | ios::binary);
		filein.read((reinterpret_cast<char *>(&customer)), sizeof(customer));
		while (!filein.eof())
		{
			if (strcmp(customer.name, searchName) != 0)
			{
				newFile.write((reinterpret_cast<char *>(&customer)), sizeof(customer));
			}
			else
			{
				recordFound = true;
				Customer newCustomer = input();
				newFile.write((reinterpret_cast<char *>(&newCustomer)), sizeof(customer));
			}
			filein.read((reinterpret_cast<char *>(&customer)), sizeof(customer));
		}
		newFile.close();
		filein.close();
		remove("customer.dat");
		rename("new.dat", "customer.dat");
		if (!recordFound)
		{
			cout << "\n\t\t\t\t\tRecord not found!\n\n";
		}
		else
		{
			cout << "\n\t\t\t\t\tRecord Changed!\n\n";
		}
	}
}
void displayFile()
{
	Customer customer;
	bool recordFound = false;
	int count = 1;
	fstream filein("customer.dat", ios::in | ios::binary);
	filein.read((reinterpret_cast<char *>(&customer)), sizeof(customer));
	if (!filein.eof())
	{
		cout << "_________________________________________________________________________________________________________\n\n";
	}
	while (!filein.eof())
	{
		recordFound = true;
		cout << "--------------------------------------------------------------------------------------------------------\n";
		cout << "\n\t\t\t\t\t<Record No " << count << ">\n\n";
		cout << "\t\t\t\tName : " << customer.name;
		cout << "\n\t\t\t\tAddress : " << customer.address;
		cout << "\n\t\t\t\tCityStateZip : " << customer.cityStateZip;
		cout << "\n\t\t\t\tTelephoneNo : "<<customer.telephoneNo;
		cout << "\n\t\t\t\tAccountBalance : " << customer.accountBalance;
		cout << "\n\t\t\t\tLast payment date : " << customer.date << "\n\n";
		count++;
		filein.read((reinterpret_cast<char *>(&customer)), sizeof(customer));
	}
	if (!recordFound)
	{
		cout << "\n\t\t\t\t\tNo record found!\n\n";
	}
	else
	{
		cout << "--------------------------------------------------------------------------------------------------------\n";

		cout << "_________________________________________________________________________________________________________\n\n";
	}
	filein.close();
}




Customer& input()
{
	Customer customer;
	char cName[30];
	char cAddress[50];
	char cZip[30];
	char no[20];
	double balance;
	char payDate[11];
	cout << "\n\nEnter name : ";
	cin.getline(cName, 29);
	strcpy_s(customer.name, cName);

	cout << "Enter Address : ";	
	cin.getline(cAddress,49);
	strcpy_s(customer.address, cAddress);
	
	cout << "Enter City, State, Postal Address: ";
	cin.getline(cZip, 29);
	strcpy_s(customer.cityStateZip, cZip);
	
	cout << "Enter Telephone no : ";
	cin .getline(no,20);
	strcpy_s(customer.telephoneNo, no);
	
	cout << "Enter Account balance: ";
	cin >> balance;
	if (balance < 0)
	{
		throw "balance cannot be negative";
	}
	customer.accountBalance = balance;
	cin.ignore();
	
	cout << "Enter last payment date: ";
	cin.getline(payDate, 10);
	strcpy_s(customer.date, payDate);
	cout << "\n\n";
	return customer;

}