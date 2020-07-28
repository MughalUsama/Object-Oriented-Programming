#include <iostream>
#include "CString.h" 
using namespace std;

int main()
{
	cout << "Enter string1: ";
	CString a;
	a.input();
	CString s;
	s=a(4, 20);
	/*cout << "Enter string2: ";
	CString a1;
	a1.input();*/
	s.display();
	//char st[27] = "UsamaShahid UsamaShahidas";
	//CString s1(st);
	//char st1[7] = "Shahid";
	//char st2[7] = "USAMA ";
	//int count = 0;
	//CString *s2=s1.split(st1, count);
	//for (int i = 0; i < count; i++)
	//{
	//	s2[i].display();
	//	cout << "\n";
	//}
	cout << "\n";
	return 0;
}


/*char st[13] = "usama shahid";
	CString s1(st);
	int count;
	CString * arr=s1.split('a', count);
	for (int i = 0; i < count; i++)
	{
		cout << "STRING" << i + 1<< " : ";
		arr[i].display();
		cout << "\n";
	}
*/



/*	char st[2] = "b";
	char stt[7] = "abcdef";
	CString s1('a');
	//s1.display();
	cout << "\n";
	CString s2(stt);
	//cout << s2.getLength();
	//s2.display();
	//cout << "\n";
	//cout << "String found at index "<<s2.find(stt)<<"\n";
	//cout<<s2.insert(5,stt);
	//s2.display();
	CString s5=s2.right(3);
	cout << "\nRight extract :  ";
	s5.display();
	
	cout << "\n";
	//s2.remove(5,2);
	//s2.display();
	char a[5] = "sama", b[5] = "SAMA";
	//cout << s2.replace(a,b);
	//s2.display();
	cout << "\n";
	//s2.trim();
	cout << "00";
	//s2.display();
	cout << "0123";
	cout << "\n";
	//s2.trimLeft();
	//s2.display();
	cout << "\n";
	cout << "00";
	//s2.trimRight();
	//s2.display();
	cout << "00";
	cout << "\n";
	//s2.makeUpper();
	//s2.display();
	cout << "\n";
	//s2.makeLower();
	//s2.display();
	cout << "\n";
	//s2.reverse();
	//s2.display();
	cout << "\n";
	CString s0 = s1.concat(s2);
	cout << "s0 ";
	s0.display();
	cout << "\n\n\n";
	s1.concatEqual(s2);
	s1.display();


	s2.display();
	s1.concatEqual(stt);
	cout << "\n";
	s1.display();
	cout << "\n";


	cout << "Comparing s1 and s2 :"<<s1.isEqual(s2)<<"\n";
	cout << "Comparing s and string stt : " <<s2.isEqual(stt);
	CString s9;
	cout << "\nGetting input : ";
	s9.input();
	s9.display();
	cout << "\n";
	
	cout << "Returning value at index : "<<s9.at(1);*/