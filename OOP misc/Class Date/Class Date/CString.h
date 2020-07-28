#ifndef STRING_H
#define STRING_H

class String
{
public:

	char*str;
	int size;
	int get_size(char*t);
	String(int x);
	void free(char *c);
	void re_size(int sz);
	/*void copy(char*c)
	{
	int i= 0;
	while(c[i]!='\0')
	{
	str[i]=c[i];
	i=i+1;
	}
	str[i] = '\0';
	}*/
	void copy(char*c, int ind = 0);
	void copyString(char*c);
	int searchString(char*key, int ind = 0);
	int comparison(char *string2, bool caseSensitive = true);

public:

	String();
	String(char c);
	String(char* c);
	String(const String&);
	~String();
	void input();
	void setString(char* c);
	void setString(char* c, int size);
	void createString(int size, char* c = "");
	void displayString();
	int getSize();
	void concatenate(char*);
	String concatenate(const String&) const;
	void String::concatEqual(const String& s2);
	void insertString(char* = "", int = 0);
	void remove(char*);
	int remove(char ch);
	int remove(int index, int count = 1);
	void replaceString(char*, char*);
	void replaceString(char c);
	void replaceString(char old, char neww);
	void String::reverseString();
	String left(int count);
	String right(int count);
	void trimAll();
	void trim();
	void trimLeft();
	void String::trimRight();
	void String::makeUpper();
	void String::makeLower();
	void replace(char* oldStr, char* newStr);
	void  reSize(int newSize);
	bool isEmpty();
	int isEqual(const String & s2) const;
	int isEqual(char* c) const;
	char & at(int index);
	int* find(char * key, int = 0);
	String* split(char, int&);
	String* String::split(char* c, int& newCount);
	String& operator = ( const String& );

};

#endif

