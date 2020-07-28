#include <iostream>
#include <iomanip>
#include"CString.h"
#include "Date.h"
using namespace std;

const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

char*  Date::monthNames[13] = { "", "January","February","March" ,"April","May","June",
                                      "July","August","September""October","November","December" };

Date::Date()
{
	day = 1;
	month = 1;
	year = 1900;
}

Date::Date(int day, int month, int year)
{
	if (year >= 1900 && year <= 2100)
	{
		this->year = year;
	}
	else
	{
		this->year = 1900;
	}
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		this->month = 1;
	}
	int dIM = daysInMonth[this->month];
	if(leapYear() && month == 2 && day <= dIM+1 && day >= 1)
	{
		this->day = day;
	}
	else if (day <= dIM && day >= 1)
	{
		this->day = day;
	}
	else
	{
		this->day = 1;
	}
}

void Date::setDate(int a, int b, int c)
{
	if (year >= 1900 && year <= 2100)
	{
		this->year = year;
	}
	else
	{
		this->year = 1900;
	}
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		this->month = 1;
	}
	int dIM = daysInMonth[this->month];
	if(leapYear() && month == 2 && day <= dIM+1 && day >= 1)
	{
		this->day = day;
	}
	else if (day <= dIM && day >= 1)
	{
		this->day = day;
	}
	else
	{
		this->day = 1;
	}
}

void Date::setYear(int x)
{
	if (x >= 1900 && x <= 2100)
	{
		this->year = x;
	}
	else
	{
		this->year = 1900;
	}
}

void Date::setMonth(int a)
{
	if (a >= 1 && a <= 12)
	{
		this->month = a;
	}
	else
	{
		this->month = 1;
	}
}

void Date::setDay(int a)
{
	int dIM = daysInMonth[this->month];
	if(leapYear() && month == 2 && day <= dIM+1 && day >= 1)
	{
		this->day = day;
	}
	else if (day <= dIM && day >= 1)
	{
		this->day = day;
	}
	else
	{
		this->day = 1;
	}
}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

void Date::incYear(int a)
{
	if (year + a <= 2100)
	{
		if(leapYear() && month ==2 && day == daysInMonth[month]+1)
		{
			month = 3;
			day = 1;
		}
		year = year + a;
	}
}

void Date::incMonth(int a )
{
	if (a > 0)
	{
		if (month + a >= 12) 
		{
			this->year = this->year + a/12;
			month = month + a%12;
		}
		else
		{
			month = month + a;
		}
	}
}

void Date::incDay(int a)
{
	int i=1;
	while(i<=a)
	{
		int dIM = daysInMonth[this->month];
		if(leapYear() && month == 2 && day < dIM+1)
		{
			this->day = this->day + 1;
			i = i + 1;
		}
		else if (a >= 1)
		{
			if ((day + 1) > dIM)
			{
				incMonth((day+1) / dIM);
				day = (day + 1 )% dIM;
			}
			else 
			{
				day = day + 1;
			}
			i = i + 1;
		}
	}
}

void Date::displayFormat1() const
{
	cout << "\n";
	if(day<10)
	{
		cout.fill('0') ;
		cout << setw(2);
	}
	cout << day << " / ";
	if(month<10)
	{
		cout.fill('0') ;
		cout << setw(2);;
	}
	cout << month << " / ";
	cout << setw(4) << year<<"\n";
}

void Date::displayFormat2() const
{
	cout << "\n";
	cout << monthNames[month] << "  ";
	if(day<10)
	{
		cout.fill('0') ;
		cout << setw(2);
	}
	cout << day << " ,";
	cout << year;
	cout << "\n";
}

void Date::displayFormat3() const
{
	if(day<10)
	{
		cout.fill('0') ;
		cout << setw(2);
	}
	cout << day ;
	cout <<" "<< monthNames[month] << ",";
	cout << year;
	cout << "\n";
}

bool Date::leapYear()
{
	if(year%4 == 0 || year%400 == 0)
	{
		return true;
	}
	return false;
}

String Date::getDateInFormat1() const
{
	String date(10);
	int i=0;
	if(day<10)
	{
		date.str[i]='0';
		i=i+1;
		date.str[i]=day+'0';
		i=i+1;
		date.str[i]='/';
		i=i+1;
	}
	else
	{
		date.str[i]=day/10+'0';
		i=i+1;
		date.str[i]=day%10+'0';
		i=i+1;
		date.str[i]='/';
		i=i+1;
	}
	if(month<10)
	{
		date.str[i]='0';
		i=i+1;
		date.str[i]=month+'0';
		i=i+1;
		date.str[i]='/';
		i=i+1;
	}
	else
	{
		date.str[i]=month/10+'0';
		i=i+1;
		date.str[i]=month%10+'0';
		i=i+1;
		date.str[i]='/';
		i=i+1;
	}
	int r= 1000 , yr=year;
	while(r>0)
	{
		date.str[i]=yr/r+48;
		yr = yr%r;
		r= r/10;
		i=i+1;
	}
	return date;
}

String Date::getDateInFormat2() const
{
	int i=0,j=0, size=9;
	char *c = monthNames[month];
	while(c[j]!='\0')
	{
		j=j+1;
	}
	size = size+j;
	String date(size);
	date.copy(c);
	i=j;
	date.str[i]=' ';
	i=i+1;
	if(day<10)
	{
		date.str[i]='0';
		i=i+1;
		date.str[i]=day+'0';
		i=i+1;
		date.str[i]=',';
		i=i+1;
		date.str[i]=' ';
		i=i+1;
	}
	else
	{
		date.str[i]=day/10+'0';
		i=i+1;
		date.str[i]=day%10+'0';
		i=i+1;
		date.str[i]=',';
		i=i+1;
		date.str[i]=' ';
		i=i+1;
	}
	int r= 1000 , yr=year;
	while(r>0)
	{
		date.str[i]=yr/r+48;
		yr = yr%r;
		r= r/10;
		i=i+1;
	}
	return date;
}

String Date::getDateInFormat3() const
{
	int i=0,j=0, size=9;
	char *c = monthNames[month];
	while(c[j]!='\0')
	{
		j=j+1;
	}
	size = size+j;
	String date(size);
	if(day<10)
	{
		date.str[i]='0';
		i=i+1;
		date.str[i]=day+'0';
		i=i+1;
		date.str[i]=' ';
		i=i+1;
	}
	else
	{
		date.str[i]=day/10+'0';
		i=i+1;
		date.str[i]=day%10+'0';
		i=i+1;
		date.str[i]=' ';
		i=i+1;
	}
	date.copy(c,i);
	i=i+j;
	date.str[i]=',';
	i=i+1;
	date.str[i]=' ';
	i=i+1;
	int r= 1000 , yr=year;
	while(r>0)
	{
		date.str[i]=yr/r+48;
		yr = yr%r;
		r= r/10;
		i=i+1;
	}
	return date;
}

int Date::get_size(char*c)  //private memver function
{
	int i = 0;
	while (c[i] != '\0')
	{
		i = i + 1;
	}
	return i - 1;
}

Date&  Date::operator + (const Date& ref)
{

	if( this  !=  &ref )
	{

		this -> ~Date();
		this -> day = ref.day;
		this -> month = ref.month;
		this -> year = ref.year;

	}

	return  *this;

}