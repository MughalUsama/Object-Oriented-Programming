#ifndef C_STRING
#define C_STRING


#include <iostream>
using namespace std;

class CString;

ostream & operator << (ostream &, CString);
istream & operator >> (istream &, CString&);


class CString
{
private:
	char *str;
	int size;

public:
	CString();
	CString(char);
	CString(char *);
	CString(const CString &);
	~CString();
	void setSize(int);
	void setString(char*);
	int getLength(char *);
	int getLength();
	void display()const;
	int find(char *, int start = 0)const;
	int find(char, int start = 0)const;
	int insert(int index, char *subStr);
	int insert(int index, char ch);
	CString left(int count)const;
	CString right(int count)const;
	int remove(int index, int count = 1);
	int remove(char ch);
	void replace(char newCh);
	int replace(char old, char newCh);
	int replace(char* old, char* newStr);
	void trim();
	void trimLeft();
	void trimRight();
	void makeUpper();
	void makeLower();
	void reverse();
	void Resize(int add);
	CString concat(const CString& s2) const;
	void concatEqual(const CString& s2);
	void concatEqual(const char * s2);
	int isEqual(const CString & s2) const;
	int isEqual(char * s2) const;
	void input();
	char & at(int index);
	int isEmpty();
	CString *split(char c, int & newCount);
	CString *split(char *c, int & newCount);
	CString & operator=(const CString &);
	CString operator+(const CString & s2) const;
	CString operator+(char* const s2) const;
	void operator +=(const CString & s2);
	void operator +=(const char* s2);
	int operator == (const CString & s2) const;
	int operator == (char * s2) const;
	char& operator [] (int index);
	int operator ! ();
	CString operator () (int start, int end) const;
	friend ostream & operator << (ostream & os, CString str);
	friend istream & operator >> (istream & is, CString & str);
};


#endif