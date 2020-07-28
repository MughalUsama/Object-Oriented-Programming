#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H


class ComplexNumber
{
private:
	double real;
	double imaginary;
public:
	ComplexNumber(double = 0.0, double = 0.0);
	void display();
	ComplexNumber operator+(const ComplexNumber &ref);
	ComplexNumber operator-(const ComplexNumber &ref);
	ComplexNumber operator*(const ComplexNumber &ref);
	ComplexNumber operator/(const ComplexNumber &ref);
};




#endif // !COMPLEXNUMBER_H

