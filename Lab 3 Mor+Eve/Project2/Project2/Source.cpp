#include <iostream>
using namespace std;

class Circle
{
private:
	double radius;
	double pi;
public:
	void setRadius(double rad);
	void setPi();
	double getRadius();
	double getArea();
	double getDiameter();
	double getCircumference();


};


int main()
{
	Circle c1;
	c1.setPi();
	double rad;
	cout << "Enter Radius : ";
	cin >> rad;
	c1.setRadius(rad);

	cout << "\n Radius : " << c1.getRadius();
	cout << "\n Area : " << c1.getArea();
	cout << "\n Diameter : " << c1.getDiameter();
	cout << "\n Circumference : " << c1.getCircumference();

	cout << "\n\n";
	system("pause");
	return 0;
}

void Circle::setRadius(double rad)
{
	if (rad<0)
	{
		radius = 0;
	}
	else
	{
		radius = rad;
	}
}

void Circle::setPi()
{
	pi = 3.14159;
}

double Circle::getRadius()
{
	return radius;
}

double Circle::getArea()
{
	return (pi*radius*radius);
}

double Circle::getDiameter()
{
	return 2 * radius;
}

double Circle::getCircumference()
{
	return (2 * pi*radius);
}
