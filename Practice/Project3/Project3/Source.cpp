#include <iostream>
using namespace std;


class Rectangle;
class square
{
private:
	int l;
	int m;
public:
	square(int k = 0, int h = 0)
	{
		l = k;
		m = h;
	}
	friend class Rectangle;
};





class Rectangle
{
private:
	int l;
public:
	Rectangle(int i = 0)
	{
		l = i;
	}
	Rectangle(const Rectangle & ref)
	{
		this->l = ref.l;
		cout << "cpy";
	}
	void display(square);

};




int main()
{
	Rectangle r(2);
	Rectangle r2 ;
	r2 = r;
	square s(2, 3);
	r2.display(s);
	cout << "\n";
	system("Pause");
	return 0;
}

void Rectangle::display(square q)
{
	cout << q.l;
	cout << "\n" << q.m;
}
