#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int Date::DAYS_IN_MONTH[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;
}

Date::Date(int dy, int mon, int yr)
{
	if (yr >= 1900 && yr <= 2100)
	{
		this->year = yr;
	}
	else
	{
		this->year = 1900;
	}
	if (mon >= 1 && mon <= 12)
	{
		this->month = mon;
	}
	else
	{
		this->month = 1;
	}
	if (dy >= 1 && dy <= DAYS_IN_MONTH[month] && month != 2)
	{
		this->day = dy;
	}
	else if (month == 2 && dy >= 1)
	{
		if (dy < 29)
		{
			this->day = dy;
		}
		else if ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0)
		{
			this->day = 29;
		}
		else
		{
			this->day = 1;
		}

	}
	else
	{
		this->day = 1;
	}

}

void Date::setYear(int yr)
{
	if (yr >= 1900 && yr <= 2100)
	{
		this->year = yr;
	}
	else
	{
		this->year = 1900;
	}
	setDay(day);
}

void Date::setMonth(int mon)
{
	if (mon >= 1 && mon <= 12)
	{
		this->month = mon;
	}
	else
	{
		this->month = 1;
	}
	setDay(day);
}

void Date::setDay(int dy)
{

	if (dy >= 1 && dy <= DAYS_IN_MONTH[month] && month != 2)
	{
		this->day = dy;
	}
	else if (month == 2 && dy >= 1)
	{
		if (dy < 29)
		{
			this->day = dy;
		}
		else if ((this->year % 4 == 0 && this->year % 100 != 0) || this->year % 400 == 0)
		{
			this->day = 29;
		}
		else
		{
			this->day = 1;
		}
	}
	else
	{
		this->day = 1;
	}

}

int Date::getYear() const
{
	return this->year;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getDate() const
{
	return this->day;
}

void Date::incYear(int count)
{
	if (this->year + count >= 1900 && this->year + count <= 2100)
	{
		this->year = this->year + count;
	}
	setDay(day);
}

void Date::incMonth(int count)
{
	if (this->month + count >= 1)
	{
		if (this->month + count>12)
		{
			this->incYear((this->month + count) / 12);
			this->month = (this->month + count) % 12;
		}
		else
		{
			this->month = this->month + count;
		}
		setDay(day);
	}

}

void Date::incDay(int count)
{
	int d = this->day + count;
	if (d >= 1)
	{
		if (d <= DAYS_IN_MONTH[this->month])
		{
			this->day = d;
		}
		else
		{
			int i = this->month;
			while (d>this->DAYS_IN_MONTH[i])
			{
				incMonth();
				d = d - this->DAYS_IN_MONTH[i];
				i = i + 1;
			}
			this->day = d;
		}
	}
}

void Date::displayFormat1() const
{
	cout.fill('0');
	cout << setw(2) << this->day << "/" << setw(2) << this->month << "/" << this->year;
}

void Date::displayFormat2() const
{
	switch (this->month)
	{
		case 1:
			cout << "January";
			break;
		case 2:
			cout << "February";
			break;
		case 3:
			cout << "March";
			break;
		case 4:
			cout << "April";
			break;
		case 5:
			cout << "May";
			break;
		case 6:
			cout << "June";
			break;
		case 7:
			cout << "July";
			break;
		case 8:
			cout << "August";
			break;
		case 9:
			cout << "September";
			break;
		case 10:
			cout << "October";
			break;
		case 11:
			cout << "November";
			break;
		case 12:
			cout << "December";
			break;
	default:
		break;
	}
	cout.fill('0');
	cout << " " << setw(2) << this->day << ", " << this->year;
}

void Date::displayFormat3() const
{
	cout.fill('0');
	cout << setw(2) << this->day<<" ";
	switch (this->month)
	{
		case 1:
			cout << "January";
			break;
		case 2:
			cout << "February";
			break;
		case 3:
			cout << "March";
			break;
		case 4:
			cout << "April";
			break;
		case 5:
			cout << "May";
			break;
		case 6:
			cout << "June";
			break;
		case 7:
			cout << "July";
			break;
		case 8:
			cout << "August";
			break;
		case 9:
			cout << "September";
			break;
		case 10:
			cout << "October";
			break;
		case 11:
			cout << "November";
			break;
		case 12:
			cout << "December";
			break;
		default:
			break;
	}
	cout << ", " << this->year;
}

//CString Date::getDateInFormat1() const
//{
//	CString str1;
//	if (this->day < 10)
//	{
//		CString str2('0');
//		str1.concatEqual(char(day + 48));
//		str1.concatEqual('/');
//	}
//	else
//	{
//		CString str2(char(day + 48));
//		str1.concatEqual('/');
//	}
//	if (this->month == 1)
//	{
//
//		char mn1[8] = "January";
//		CString str2(mn1);
//	}
//	else if (this->month == 2)
//	{
//		char mn2[9] = "February";
//		CString str2(mn2);
//	}
//	else if (this->month == 3)
//	{
//
//		char mn3[6] = "March";
//		CString str2(mn3);
//	}
//	else if (this->month == 4)
//	{
//		char mn4[6] = "April";
//		CString str2(mn4);
//
//	}
//	else if (this->month == 5)
//	{
//
//		char mn5[4] = "May";
//		CString str2(mn5);
//
//	}
//	else if (this->month == 6)
//	{
//
//		char mn6[5] = "June";
//		CString str2(mn6);
//	}
//	else if (this->month == 7)
//	{
//
//
//		char mn7[5] = "July";
//		CString str2(mn7);
//
//	}
//	else if (this->month == 8)
//	{
//
//		char mn8[7] = "August";
//		CString str2(mn8);
//
//	}
//	else if (this->month == 9)
//	{
//
//		char mn9[10] = "September";
//		CString str2(mn9);
//	}
//	else if (this->month == 10)
//	{
//
//		char mn10[8] = "October";
//		CString str2(mn10);
//	}
//	else if (this->month == 11)
//	{
//
//
//		char mn11[9] = "November";
//		CString str2(mn11);
//
//	}
//	else if (this->month == 12)
//	{
//
//		char mn12[9] = "December";
//		CString str2(mn12);
//	}
 //
//	str1.concatEqual(str2);
//	str1.concatEqual(this->year);
//
//	return str1;
//}
//
//CString Date::getDateInFormat2() const
//{
//	return CString();
//}
//
//CString Date::getDateInFormat3() const
//{
//	return CString();
//}
