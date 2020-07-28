#ifndef DATE_H
#define DATE_H
#include"CString.h"
class Date
{
private:

	int year;
	int month;
	int day;
	int get_size(char*c);
	
public:

	static const int daysInMonth[13];
	static  char * monthNames[13];
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	void incYear(int a);
	void incMonth(int a );
	void incDay(int a);
	void displayFormat1() const;
	void displayFormat2() const;
	void displayFormat3() const;
	String getDayName() const;
	bool leapYear();
	String getDateInFormat1() const;
	String getDateInFormat2() const;
	String getDateInFormat3() const;
	Date&  operator + (const Date& );

};



#endif