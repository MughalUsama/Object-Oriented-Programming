#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	void setDay(int d);
	void setMonth(int mon);
	void setYear(int y);
	int getDay();
	int getMonth();
	int getYear();
};

void displayDate(Date);


int main()
{
	Date d[5];
	d[0].setDay(25);
	d[0].setMonth(12);
	d[0].setYear(1876);

	d[1].setDay(9);
	d[1].setMonth(11);
	d[1].setYear(1877);
	
	d[2].setDay(21);
	d[2].setMonth(4);
	d[2].setYear(1938);
	
	d[3].setDay(14);
	d[3].setMonth(8);
	d[3].setYear(1947);
	
	d[4].setDay(11);
	d[4].setMonth(11);
	d[4].setYear(1948);
	
	displayDate(d, 4);

	cout << "\n\n";
	system("pause");
	return 0;
}

void Date::setDay(int d)
{
	if (d<0)
	{
		day = 1;
	}
	else
	{
		day = d;
	}
}

void Date::setMonth(int mon)
{
	if (mon<0)
	{
		month = 1;
	}
	else
	{
		month = mon;
	}

}

void Date::setYear(int y)
{
	if (y<0)
	{
		year = 2000;
	}
	else
	{
		year = y;
	}

}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void displayDate(Date d1[], int noOfDates)
{
	for (int i = 0; i < noOfDates; i++)
	{
		cout << "Date is : " << d1[i].getDay() << "/" << d1[i].getMonth << "/" << d1[i].getYear;
	}
}