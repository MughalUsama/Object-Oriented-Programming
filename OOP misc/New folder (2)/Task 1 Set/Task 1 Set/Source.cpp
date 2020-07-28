#include<iostream>
#include"Set.h"

using namespace std;

 
int main()
{
	Set s(7);
	Set s1(6);

	for(int i=0;i<7;i=i+1)
	{
		int element;
		cin>>element;
		s.insert(element);
	}

	for(int i=0;i<6;i=i+1)
	{
		int element;
		cin>>element;
		s1.insert(element);
	}

	int x=s.isSubSet( s1 );
	
	cout<<x<<"\n";
	s.reSize(10);
	cout<<s.getCapacity()<<"\n";
	system("pause");
	return 0;
}