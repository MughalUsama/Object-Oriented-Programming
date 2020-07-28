#ifndef Fraction_H
#define Fraction_H

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int = 1, int = 1);
	void display();
	Fraction operator +(const Fraction &);
	Fraction operator *(const Fraction &);
	Fraction operator /(const Fraction &);
	Fraction operator -(const Fraction &);

	void operator+=(const Fraction &);
	void operator-=(const Fraction &);
	void operator*=(const Fraction &);
	void operator/=(const Fraction &);

	bool operator==(const Fraction &);
	bool operator!=(const Fraction &);
	bool operator<=(const Fraction &);
	bool operator>=(const Fraction &);
	bool operator<(const Fraction &);
	bool operator>(const Fraction &);
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);
	Fraction operator-();
	operator double();
};


#endif


