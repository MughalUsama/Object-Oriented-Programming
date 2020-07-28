#include "Fraction.h"
#include <iostream>

using namespace std;


Fraction::Fraction(int num, int den)
{
	this->numerator = num;
	if (this->denominator!=0)
	{
		if (this->denominator<0)
		{
			this->denominator = -den;
			this->numerator = -this->numerator;
		}
		else
		{
			this->denominator = den;
		}
		for (int i = this->denominator; i > 0; i--)
		{
			if (this->numerator%i == 0 && this->denominator%i == 0)
			{
				this->numerator = this->numerator / i;
				this->denominator = this->denominator / i;
			}
		}
	}
	else
	{
		this->numerator = 0;
		this->denominator = 1;
	}
}

void Fraction::display()
{
	cout << this->numerator << "/" << this->denominator;
}

Fraction Fraction::operator+(const Fraction & ref)
{
	Fraction temp((this->numerator*ref.denominator + this->denominator*ref.numerator), this->denominator*ref.denominator);
	return temp;
}

Fraction Fraction::operator*(const Fraction &ref)
{
	Fraction temp(this->numerator*ref.numerator,this->denominator*ref.denominator);
	return temp;
}

Fraction Fraction::operator/(const Fraction & ref)
{
	Fraction temp(this->numerator*ref.denominator, this->denominator*ref.numerator);
	return temp;
}

Fraction Fraction::operator-(const Fraction & ref)
{
	Fraction temp((this->numerator*ref.denominator - this->denominator*ref.numerator), this->denominator*ref.denominator);
	return temp;
}

void Fraction::operator+=(const Fraction & ref)
{
	*this = *this + ref;
}

void Fraction::operator-=(const Fraction & ref)
{
	*this = *this - ref;
}

void Fraction::operator*=(const Fraction & ref)
{
	*this = *this * ref;
}

void Fraction::operator/=(const Fraction & ref)
{
	*this = *this / ref;
}

bool Fraction::operator==(const Fraction & ref)
{
	if (this->numerator==ref.numerator && this->denominator==ref.denominator)
	{
		return true;
	}
	return false;
}

bool Fraction::operator!=(const Fraction & ref)
{
	if (this->numerator == ref.numerator && this->denominator == ref.denominator)
	{
		return false;
	}
	return true;
}

bool Fraction::operator<=(const Fraction & ref)
{
	if (*this<ref || *this==ref)
	{
		return true;
	}
	return false;
}

bool Fraction::operator>=(const Fraction & ref)
{
	if (*this>ref || *this == ref)
	{
		return true;
	}
	return false;
}

bool Fraction::operator<(const Fraction & ref)
{
	if (this->numerator*ref.denominator < ref.numerator*this->denominator)
	{
		return true;
	}
	return false;
}

bool Fraction::operator>(const Fraction & ref)
{
	if (this->numerator*ref.denominator > ref.numerator*this->denominator)
	{
		return true;
	}
	return false;
}


Fraction Fraction::operator++()
{
	Fraction temp1;
	*this += temp1;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp(this->numerator, this->denominator);
	Fraction temp1;
	*this += temp1;
	return temp;
}

Fraction Fraction::operator--()
{
	Fraction temp1;
	*this -= temp1;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction temp(this->numerator, this->denominator);
	Fraction temp1;
	*this -= temp1;
	return temp;
}

Fraction Fraction::operator-()
{
	Fraction temp(this->numerator*-1, this->denominator);
	return temp;
}


Fraction::operator double()
{
	double temp = this->numerator*1.0 / this->denominator;
	return temp;
}
