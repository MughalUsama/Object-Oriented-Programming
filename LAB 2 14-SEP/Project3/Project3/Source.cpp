#include <iostream>
using namespace std;

struct Book
{
	char name[50];
	char publisher[50];
	int ISBNNumber;
};

struct Library
{
	Book * data;
	int noOfBooks;
	int capacity;
};

//prototype
void displayMenu();
void initializeLibrary(Library &ly, const int capacity);
void addBook(Library & ly, const Book &bo);
bool removeBook(Library &ly, char *bookName, int count = 1);
int searchBook(Library &ly, char *bookName);
void displayAllBooksInformation(Library &ly);
void resize(Library & ly, const int capacity);



int main()
{
	Library ly;
	initializeLibrary(ly, 1);
	displayMenu();
	int choice;
	do
	{
		cout << "\n\n\t\t\t\t\t  Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Book bo;
			cout << "Enter name of book: ";
			cin.ignore();
			cin.getline(bo.name,50);
			cout << "Enter name of publisher: ";
			cin.ignore();
			cin.getline(bo.publisher,50);
			cout << "Enter ISBN no of book: ";
			cin >> bo.ISBNNumber;
			addBook(ly, bo);
			break;
		case 2:
			char name[50];
			int count;
			cout << "Enter name of book: ";
			cin.ignore();
			cin.getline(name, 50);
			cout << "Enter no of books to remove: ";
			cin >> count;
			if (!removeBook(ly, name, count))
			{
				cout << "\n\t\t\t\t\tNot enough books of this name to remove.";
			}
			else
			{
				cout << "\n\t\t\t\t\tBooks removed";
			}
			
			break;
		case 3:
			displayAllBooksInformation(ly);
			break;
		default:
			break;
		}
	} while (choice!=0);

	cout << "\n";
	system("pause");
	return 0;
}

void displayMenu()
{
	cout << "Enter 1 to add book.\n";
	cout << "Enter 2 to remove book.\n";
	cout << "Enter 3 to display all books.\n";
	cout << "Enter 0 to exit";
}

void initializeLibrary(Library &ly, const int capacity)
{
	ly.data = new Book[capacity];
	ly.noOfBooks = 0;
	ly.capacity = capacity;
}

void addBook(Library & ly, const Book &bo)
{
	if (ly.capacity == ly.noOfBooks)
	{
		resize(ly, ly.capacity + 1);
	}
	
	ly.data[ly.noOfBooks] = bo;
	ly.noOfBooks = ly.noOfBooks + 1;
	
}

bool removeBook(Library &ly, char *bookName, int count)
{
	for (int i = 0; i < count; i++)
	{

		int index = searchBook(ly, bookName);
		if (index == -1)
		{
			return false;
		}
		else
		{
			for (int i = index; i < ly.noOfBooks; i++)
			{
				ly.data[i] = ly.data[i + 1];
			}
			ly.noOfBooks = ly.noOfBooks - 1;
		}
	}
	return true;
}

int searchBook(Library &ly, char *bookName)
{
	
	for (int i = 0; i < ly.noOfBooks; i++)
	{
		bool found=true ;
		int j = 0;
		while (bookName[j]!='\0' && found)
		{
			if (bookName[j]!=ly.data[i].name[j])
			{
				found = false;
			}
			else
			{
				j = j + 1;
			}
		}
		if (bookName[j] == ly.data[i].name[j])
		{
			return i;
		}
	}
	return -1;
}

void displayAllBooksInformation(Library &ly)
{
	cout <<"\n\t\t\t\t\tTotal books available: "<< ly.noOfBooks;
	for (int i = 0; i < ly.noOfBooks; i++)
	{
		cout << "\n\n\nBook no: " << i + 1;
		cout << "\n\n Book name: " << ly.data[i].name;
		cout << "\n Name of Publisher: " << ly.data[i].publisher;
		cout << "\n ISBN No: " << ly.data[i].ISBNNumber;
	}
}

void resize(Library & ly, const int capacity)
{
	Library newLib;
	initializeLibrary(newLib, capacity);
	for (int i = 0; i < ly.noOfBooks; i++)
	{
		newLib.data[i] = ly.data[i];
	}
	
	delete[] ly.data;
	ly.data = newLib.data;
	ly.capacity = capacity;
}




