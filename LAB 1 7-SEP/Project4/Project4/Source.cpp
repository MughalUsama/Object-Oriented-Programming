#include <iostream>
using namespace std;

struct Player
{
	char name[20];
	char position[10];
	int noOfTouchDowns;
	int noOfCatches;
	int noOfPassingYards;
	int noOfReceivingYards;
	int noOfRushingYards;
};

int getIndex(char * , Player *);
void getData(Player *);
void displayData(Player *);
void searchPlayer(Player *);
void updateData(Player *);


int main()
{
	Player pl[10];
	int choice;

	do
	{
		cout << "\n\n\t\t\t\t\tEnter 1 to enter data.\n";
		cout << "\t\t\t\t\tEnter 2 to display data.\n";
		cout << "\t\t\t\t\tEnter 3 to search data of a player.\n";
		cout << "\t\t\t\t\tEnter 4 to update data.\n";
		cout << "\t\t\t\t\tEnter 0 to exit.\n\n\t\t\tYour choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\n\n\t\t\t\"Adding Data\"";
			getData(pl);
			break;
		
		case 2:
			cout << "\n\n\t\t\t\"Displaying Record\"";
			displayData(pl);
			break;

		case 3:
			cout << "\n\n\t\t\t\"Player Search\"";
			searchPlayer(pl);
			break;
		case 4:
			cout << "\n\n\t\t\t\"Update Player Data\"";
			updateData(pl);
			break;
		default:
			break;
		}
	} while (choice != 0);
	cout << "\n";
	system("pause");
	return 0;
}

void getData(Player *pl)
{
	for (int i = 0; i < 2; i++)
	{
		cout << "\n\nPlayer No "<< i+1<< " :";
		cout << "\nEnter name: ";
		cin >> pl[i].name;
		cout << "Enter position: ";
		cin >> pl[i].position;
		cout << "Enter no of touchdowns: ";
		cin >> pl[i].noOfTouchDowns;
		cout << "Enter no of catches: ";
		cin >> pl[i].noOfCatches;
		cout << "Enter no of passing yards: ";
		cin >> pl[i].noOfPassingYards;
		cout << "Enter no of receiving yards: ";
		cin >> pl[i].noOfReceivingYards;
		cout << "Enter no of rushing yards: ";
		cin >> pl[i].noOfRushingYards;
	}
}
void displayData(Player *pl)
{
	for (int i = 0; i < 2; i++)
	{
		cout << "\n\n\t\t\tPlayer Name: ";
		cout << pl[i].name;
		cout << "\n\t\t\tPlayer Position: ";
		cout << pl[i].position;
		cout << "\n\t\t\tNo of Touchdowns: ";
		cout << pl[i].noOfTouchDowns;
		cout << "\n\t\t\tNo of Catches: ";
		cout << pl[i].noOfCatches;
		cout << "\n\t\t\tNo of Passing Yards: ";
		cout << pl[i].noOfPassingYards;
		cout << "\n\t\t\tNo of Receiving Yards: ";
		cout << pl[i].noOfReceivingYards;
		cout << "\n\t\t\tNo of Rushing Yards: ";
		cout << pl[i].noOfRushingYards;
	}
}

void searchPlayer(Player *pl)
{
	char pName[20];
	cout << "\nEnter name of player: ";
	cin.ignore();
	cin.getline(pName,20);
	int i= getIndex(pName, pl);
	if (i==-1)
	{
		cout << "\n\n\t\t\t\tPlayer Record Not Found.";
	}
	else
	{
		cout << "\n\n\t\t\tPlayer Name: ";
		cout << pl[i].name;
		cout << "\n\t\t\tPlayer Position: ";
		cout << pl[i].position;
		cout << "\n\t\t\tNo of Touchdowns: ";
		cout << pl[i].noOfTouchDowns;
		cout << "\n\t\t\tNo of Catches: ";
		cout << pl[i].noOfCatches;
		cout << "\n\t\t\tNo of Passing Yards: ";
		cout << pl[i].noOfPassingYards;
		cout << "\n\t\t\tNo of Receiving Yards: ";
		cout << pl[i].noOfReceivingYards;
		cout << "\n\t\t\tNo of Rushing Yards: ";
		cout << pl[i].noOfRushingYards;

	}
}


void updateData(Player *pl)
{
	char pName[20];
	cout << "\nEnter name of player: ";
	cin.ignore();
	cin.getline(pName, 20);
	int i = getIndex(pName, pl);  //getting index of record
	if (i==-1)
	{
		cout << "\n\n\t\t\t\tPlayer Record Not Found.";
	}
	else
	{
		//updating record:
		cout << "\n\nEnter new name: ";
		cin >> pl[i].name;
		cout << "Enter position: ";
		cin >> pl[i].position;
		cout << "Enter no of touchdowns: ";
		cin >> pl[i].noOfTouchDowns;
		cout << "Enter no of catches: ";
		cin >> pl[i].noOfCatches;
		cout << "Enter no of passing yards: ";
		cin >> pl[i].noOfPassingYards;
		cout << "Enter no of receiving yards: ";
		cin >> pl[i].noOfReceivingYards;
		cout << "Enter no of rushing yards: ";
		cin >> pl[i].noOfRushingYards;
	}
}



int getIndex(char * pName, Player * pl)
{
	for (int i = 0; i < 2; i++)
	{
		int j = 0;
		while (pName[j]!='\0' && pName[j]==pl[i].name[j])
		{
			j = j + 1;
		}
		if (pl[i].name[j] == pName[j])
		{
			return i;
		}
	}
	return -1;
}