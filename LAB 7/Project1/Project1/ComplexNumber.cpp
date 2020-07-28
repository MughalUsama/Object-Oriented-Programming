#include "ComplexNumber.h"
#include <iostream>

using namespace std;


ComplexNumber::ComplexNumber(double r, double i)
{
	this->real = r;
	this->imaginary = i;
}


void ComplexNumber::display()
{
	cout <<this->real;
	if (this->imaginary<0)
	{
		cout << this->imaginary<<"i";
	}
	else
	{
		cout << "+"<<this->imaginary<<"i";
	}
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber & ref)
{
	ComplexNumber temp(this->real+ref.real,this->imaginary+ref.imaginary );
	return temp;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber & ref)
{
	ComplexNumber temp(this->real - ref.real, this->imaginary - ref.imaginary);
	return temp;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber & ref)
{
	ComplexNumber temp((this->real * ref.real)-(this->imaginary * ref.imaginary),(this->imaginary*ref.real)+(this->real *ref.imaginary));
	return temp;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber & ref)
{
	double denominator = (ref.real*ref.real) + (ref.imaginary * ref.imaginary);
	if (denominator != 0)
	{
		ComplexNumber temp((((this->real * ref.real) + (this->imaginary * ref.imaginary)) / denominator), (((this->imaginary*ref.real) - (this->real *ref.imaginary)) / denominator));
		return temp;
	}
	else
	{
		ComplexNumber temp(0, 0);
		return temp;
	}
}
