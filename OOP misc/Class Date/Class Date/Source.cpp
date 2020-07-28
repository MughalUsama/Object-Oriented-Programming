#include "Date.h"
#include<iostream>
#include"CString.h"
using namespace std;
int main()
{
	Date d1(1,1,1903);
	d1.incDay(59);
	d1.displayFormat3();
	String s=d1.getDateInFormat3();
	s.displayString();
	system("pause");
	return  0;
}