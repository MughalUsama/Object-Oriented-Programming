#ifndef DATE_H
#define DATE_H
#include "CString.h"
class Date
{
private:
	int year;
	int month;
	int day;
	static const int DAYS_IN_MONTH[13];
public:
	Date();
	Date(int, int, int);
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	int getYear()const;
	int getMonth()const;
	int getDate()const;
	void incYear(int = 1);
	void incMonth(int = 1);
	void incDay(int = 1);
	void displayFormat1()const;
	void displayFormat2()const;
	void displayFormat3()const;
	/*CString getDateInFormat1()const;
	CString getDateInFormat2()const;
	CString getDateInFormat3()const;*/
};

#endif 


