#include <iostream>
using namespace std;
class Rectangle
{
	int a;
	int b;
public:
	Rectangle();
	Rectangle(int a, int  b);
	~Rectangle();
	Rectangle(const Rectangle & r);

};
Rectangle f2(Rectangle r);
Rectangle f(Rectangle r)
{
	Rectangle g = f2(r);
	return g;
}
Rectangle f2(Rectangle r)
{
	return r;
}
Rectangle::Rectangle()
{
	cout << "\nDefault Const.\n";
}
Rectangle::Rectangle(int a, int b)
{
	cout << "\nParameterized Const.\n";
}
Rectangle::Rectangle(const Rectangle & r)
{
	cout << "\nCopy Const.\n";
}
Rectangle::~Rectangle()
{
	cout << "\nDestructor.\n";
}

void g() {
	Rectangle r1; //def
	Rectangle r2(1, 2); //para
	Rectangle r3 = r2; //copy
	r3 = f2(r1);// copy  copy dest  
	Rectangle r4 = f(r2); // copy  copy copy dest  copy
	cout << "fn\n";
}
int main()
{
	g();
	cout << "fds";
	system("pause");
	return 0;// dest dest dest dest 
}