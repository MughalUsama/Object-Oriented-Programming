#include<iostream>
#include"CString.h"
using namespace std;

String::String()
{
	size=0;
	str = nullptr;
}
String::String(int x)  //private constructor
{
	size = x + 1;
	str = new char[size];
	str[size - 1] = '\0';
}
String::String(char c)
{
	size = 2;
	str = new char[2];
	str[0]=c;
	str[1]='\0';
}
String::String(char* c)
{
	size=get_size(c)+1;
	str=new char[size];
	int i=0;
	while(i<get_size(c))
	{
		this->str[i]=c[i];
		i=i+1;
	}
	this->str[i]='\0';
}
String::String(const String& ref)
{
	size = ref.size;
	str = new char [size];
	int i=0;
	while(ref.str[i]!='\0')
	{
		str[i] = ref.str[i];
		i=i+1;
	}
	str[i]='\0';
}
String::~String()
{
	size=0;
	if(str!= nullptr)
	{
		delete[] str;
		str = nullptr;
	}
}
void String::createString( int size,char* c)
{
	this->size =size+1;
	str= new char [this->size];
	int i=0;
	while(c[i]!='\0')
	{
		str[i]=c[i];
		i=i+1;
	}
	str[i]='\0';
}
void String::setString(char* c,int size)
	{
		str=new char[size];
		int i=0;
		while(i<size&&c[i]!='\0')
		{
			str[i]=c[i];
			i=i+1;
		}
		str[i]='\0';
	}
void String::setString(char* c)
{
	size = get_size(c)+1;
	str=new char[size];
	int i=0;
	while(i<get_size(c)&&c[i]!='\n'&&c[i]!='\0')
	{
		str[i]=c[i];
		i=i+1;
	}
	str[i]='\0';
}
int String::getSize() 
{
	return size-1;
}
void String::displayString()
	{
		cout<<str;
	}
void String::concatenate( char*s)
{
	size=get_size(s)+size;
	char*p=str;
	str=new char[size];
	int i=0, j=0;
	while(p[i]!='\0')
	{
		str[i]=p[i];
		i=i+1;
	}
	while(s[j]!='\0')
	{
		str[i]=s[j];
		i=i+1;
		j=j+1;
	}
	str[i]='\0';
	delete p;
	p=nullptr;
}
String String::concatenate(const String& s2) const
{
	String s3;
	s3.size = size+s2.size-1;
	s3.str = new char [s3.size];
	int i=0, count = 0;
	while(str[i]!='\0')
	{
		s3.str[count] = str[i];
		i=i+1;
		count = count + 1;
	}
	i=0;
	while(s2.str[i]!='\0')
	{
		s3.str[count] = s2.str[i];
		i=i+1;
		count = count + 1;
	}
	s3.str[count] = '\0';
	return s3;
}
void String::concatEqual(const String& s2)
{
	String s3;
	s3.size = size+s2.size-1;
	s3.str = new char [s3.size];
	int i=0, count = 0;
	while(str[i]!='\0')
	{
		s3.str[count] = str[i];
		i=i+1;
		count = count + 1;
	}
	i=0;
	while(s2.str[i]!='\0')
	{
		s3.str[count] = s2.str[i];
		i=i+1;
		count = count + 1;
	}
	s3.str[count] = '\0';
	str = s3.str;
	size=s3.size;
	s3.str= nullptr;
}
void String::insertString(char* c, int ind)
{
	int i=0 , count = 0;
	char*ch=str;
	size = size + get_size(c);
	str = new char[size];
	while(i<ind)
	{
		str[count] = ch[i];
		i= i+1;
		count =count + 1;
	}
	int j= 0;
	while(c[j]!='\0')
	{
		str[count] = c[j];
		count =count +1;
		j=j+1;
	}
	while(ch[i]!='\0')
	{
		str[count] = ch[i];
		i= i+1;
		count =count + 1;
	}
	str[count] = '\0';
	free(ch);
}
void String::remove( char* key)
{
	const int keyLength=get_size(key);
	char*c = str;
	int i=0, j=searchString(key);
	while(i<size)
	{
		if(i==j)
		{
			int r=keyLength;
			int j1 = j;
			while(c[j1]!='\0')
			{
				c[j1]=c[j1+keyLength];
				j1 = j1+1;
			}
			size = size - keyLength;
			i=i+1;
			j=searchString(key);
		}
		else
		{
			i=i+1;
		}
	}
	size = get_size(c)+1;
	str = new char[size];
	copy(c);
	free(c);
	/*int k = 1;
	while(k!=0)
	{
		int ind =searchString(key);
		if(ind==-1&&k!=1)
		{
			k=0;
		}
		else if(ind==-1&&k==1)
		{
			k=0;
		}
		else
		{
			k=k+1;
			int i=0;
			while(ind<size)
			{
				str[ind]=str[ind+get_size(key)];
				ind=ind+1;
			}
			str[ind]='\0';
			size=get_size(str)+1;
		}
	}*/
}
int String::remove( char ch)
{
	int count = 0, i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			int j = i;
			while (str[j] != '\0')
			{
				str[j] = str[j + 1];
				j = j + 1;
			}
			str[j] = '\0';
			count = count + 1;
		}
		i = i + 1;
	}
	size = get_size(str)+1;
	return count;
}
int String::remove(int index , int count )
{
	int  i = index;
	while ( count >0 && str[i] != '\0')
	{
		int j = i;
		while (str[j] != '\0')
		{
			str[j] = str[j + 1];
			j = j + 1;
		}
		str[j] = '\0';
		count =count - 1;
	}
	size = get_size(str)+1;
	return size-1;
}
void String::replaceString( char* source,char* key)
{
	int ind =searchString(source);
	while(ind!=-1)
	{
		if(!(ind==-1))
		{
			size=getSize()+get_size(key)-get_size(source)+1;
			char*p=str;
			str=new char[size];
			int i=0, j=0,count =0;
			while(count<size-1)
			{
				if((count<ind)&&str[i]!='\0')
				{
					str[i]=p[i];
					i=i+1;
				}
				else if(j<get_size(key))
				{
					str[count]=key[j];
					j=j+1;
				}
				else if(count>=ind+get_size(key)&&str[i]!='\0')
				{
					str[count]=p[i+get_size(source)];
					i=i+1;
				}
				count=count+1;
			}	
			str[count]='\0';
			delete p;
			p=nullptr;
			ind =searchString(source,ind+get_size(source));
		}
	}
}
void String::replaceString(char c)
{
	int i= 0;
	while(str[i]!='\0')
	{
		str[i]=c;
		i=i+1;
	}

}
void String::replaceString(char old , char neww)
{
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]==old)
		{
			str[i]=neww;
		}
		i=i+1;
	}
}
void String::reverseString()
{
	int i=0,j=size-2;
	while(i<(size+1)/2)
	{
		char ch=str[i];
		str[i]=str[j];
		str[j]=ch;
		i=i+1,j=j-1;
	}
}
String String:: left( int count)
{
		int  k=0;
		char*c=str;
		String s2(count) ;
		while (count > 0)
		{
			int i = 0;
			s2.str[k]=c[i];
			while (str[i] != '\0')
			{
				c[i] = c[i + 1];
				i = i + 1;
			}
			k=k+1;
			count = count - 1;
		}
		size = get_size(c)+1;
		str = new char[size];
		copy(c);
		free(c);
		return s2;
}
String String:: right( int count)
{
	char*c = str;
	String s2(count);
	int i=0, j= get_size(str)-count,k=0;
	while(k<count)
	{
		s2.str[k]=str[j];
		c[j] = '\0';
		k=k+1;
		j=j+1;
	}
	size = get_size(c)+1;
	str = new char[size];
	copy(c);
	free(c);
	return  s2;;
		/*int strLength, strLength1;
		strLength = getSize();
		while (count > 0)
		{
			str[strLength] = str[strLength + 1];
			count = count - 1;
			strLength = strLength - 1;
		}
		strLength1 = get_size(str);
		size = strLength1+1;
		return strLength1;*/
}
void String::trimAll()
{
	char*c=str;
	int i = 0;
	while (c[i] != '\0')
	{
		if (c[i] == ' ')
		{
			int j = i;
			while (c[j] != '\0')
			{
				c[j] = c[j + 1];
				j = j + 1;
			}
			c[j] = '\0';
		}
		i = i + 1;
	}
	size = get_size(c)+1;
	str = new char[size];
	copy(c);
	free(c);
}
void String::trim()
{
	trimLeft();
	trimRight();
}
void String::trimLeft()
{
	char* c = str;
	int i = 0;
	while (!(c[i] >= 65 && c[i] <=90 )&& !(c[i] >= 97 && c[i] <=122))
	{
		if (c[i] == ' ')
		{
			int j = i;
			while (c[j] != '\0')
			{
				c[j] = c[j + 1];
				j = j + 1;
			}
			c[j] = '\0';
		}
	}
	size = get_size(c)+1;
	str = new char[size];
	copy(c);
	free(c);
}
void String::trimRight()
{
	char*c=str;
	int i = getSize();
	while (!(c[i] >= 65 && c[i] <=90 )&& !(c[i] >= 97 && c[i] <=122))
	{
		if (c[i] == ' ')
		{
			int j = i;
			while (c[j] != '\0')
			{
				c[j] = c[j + 1];
				j = j + 1;
			}
		}
		i = i - 1;
	}
	size = get_size(c)+1;
	str = new char[size];
	copy(c);
	free(c);
}
void String::makeUpper()
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			char ch = str[i];
			ch = ch - 32;
			str[i] = ch;
		}
		i = i + 1;
	}
}
void String::makeLower()
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			char ch = str[i];
			ch = ch + 32;
			str[i] = ch;
		}
		i = i + 1;
	}
}
void String :: reSize(int newLength)
{
	char *p= str;
	size =newLength+1;
	str = new char[size];
	int i=0;
	while(p[i]!='\0')
	{
		str[i] =  p[i];
		i=i+1;
	}
	str[i]='\0';
	free(p);
}
bool String::isEmpty()
{
	if(str=="")
	{
		return true;
	}
	return false;
}
int String::isEqual(const String & s2) const
{
	String s3(*this);
	int indicator = s3.comparison( s2.str );
	return indicator;
}
int String::isEqual(char* c) const
{
	String s3(*this);
	int indicator = s3.comparison(c);
	return indicator;
}
void String::input()
{
	cout<<"Enter isze of string you want to ente\n";
	cin>>size;
	size=size+1;
	str = new char [size];
	cin.ignore();
	cin.getline(str, size);
	str[size-1]='\0';
}
char & String::at(int index )
{
	int i=0;
	while(i!=index)
	{
		i=i+1;
	}
	return str[i];
}
int* String::find(char * key , int ind)
{
	int i=0, count =0 , incre = 0 ;
	while(str[i]!='\0' && i!=-1)
	{
		if(searchString(key , i+incre)!=-1)
		{
			count = count + 1;
		}
		incre = get_size(key);
		i =  searchString(key ,  i+incre);
	}
	i=0;
	int *p = new int [count+1] , j=0;
	while(str[i]!='\0' && i!=-1)
	{
		if(searchString(key , i+incre)!=-1)
		{
			p[j]=searchString(key , i+incre);
			j = j+1;
		}
		incre = get_size(key);
		i =  searchString(key ,  i+incre);
	}
	p[count] = -1;
	return p;
}
void String::replace( char* oldStr,char* newStr)
{
	const int oldStringSize=get_size(oldStr), newStringSize = get_size(newStr);

	int *p = find(oldStr) , count = 0;
	while(p[count]!=-1)
	{
		count = count + 1;
	}
	if(count!=0)
	{
		size = size - count*oldStringSize + count*newStringSize;
		char* c = str;
		count = 0;
		str = new char[size];
		int i = 0 , j = 0;
		while(count<size)
		{
			if(i != p[j])
			{
				str[count] = c[i];
				count = count + 1;
				i=i+1;
			}
			else
			{
				int j1 = 0;
				while(newStr[j1]!='\0')
				{
					str[count] = newStr[j1];
					count = count + 1;
					j1= j1 +1;
				}
				j=j+1;
				i = i + oldStringSize;
			}
		}
		str[size-1]='\0';
		free(c);
	}
	delete p;
	p= nullptr;
	
}
String* String::split(char c, int& newCount)
{
	newCount = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			newCount = newCount + 1;
		}
		i = i + 1;
	}
	newCount = newCount + 1;
	char*ch = new char[size];
	copyString(ch);
	String *s2 = new String[newCount];
	i = 0;
	int j = 0;
	while (i < newCount)
	{
		int size2 = 0;
		while (str[j] != c && str[j] != '\0')
		{
			j = j + 1;
		}
		size2 = j;
		j =1;
		String ts = left(size2);
		s2[i].createString(size2 ,ts.str );
		ts.~String();
		remove(0,1);
		i = i + 1;
	}
	this->~String();
	str = ch;
	size = get_size(str);
	return s2;
}
String* String::split(char* c, int& newCount)
{
	newCount = 0;
	int i = 0,ind = searchString(c);
	while (str[i] != '\0')
	{
		if (i == ind)
		{
			newCount = newCount + 1;
			ind = searchString(c, ind + 1);
		}
		
		i = i + 1;
	}
	newCount = newCount + 1;
	char*ch = new char[size];
	copyString(ch);
	String *s2 = new String[newCount];
	i = 0 ;
	int j = 0;
	while (i < newCount)
	{
		int size2 = 0;
		while (j!= searchString(c) && str[j] != '\0')
		{
			j = j + 1;
		}
		size2 = j;
		j = 0;
		String ts = left(size2);
		s2[i].createString(size2, ts.str);
		ts.~String();
		remove(0, get_size(c));
		i = i + 1;
	}
	size = get_size(str);
	this->createString(size + 1, str);
	return s2;
}
int String::get_size(char*t)
{
	int i = 0;
	while (t[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
void String::free(char *c)
{
	delete c;
	c = nullptr;
}
void String::re_size(int sz)
{
	this->size = sz;
	this->str = new char[this->size];
}
void String::copy(char*c, int ind )
{
	int i = 0;
	while (c[i] != '\0')
	{
		str[ind] = c[i];
		ind = ind + 1;
		i = i + 1;
	}
	str[ind] = '\0';
}
void String::copyString(char*c)
{
	int i = 0;
	while (str[i] != '\0')
	{
		c[i] = str[i];
		i = i + 1;
	}
	c[i] = '\0';
}
int String::searchString(char*key, int ind )
{
	int i = 0, keyStartingIndex = -1;
	while (i<get_size(key) && str[ind] != '\0')
	{
		if ((str[ind] == key[i]))
		{
			if (i == 0)
			{
				keyStartingIndex = ind;
			}
			i = i + 1;
		}
		else
		{
			i = 0;
		}
		ind = ind + 1;
	}
	if (i == get_size(key))
	{
		return keyStartingIndex;
	}
	return -1;
}
int String::comparison(char *string2, bool caseSensitive )
{
	int strLength1, strLength2;
	strLength1 = get_size(str);
	strLength2 = get_size(string2);
	int i = 0, count = 0;
	if (caseSensitive == true)
	{
		while (str[i] != '\0')
		{
			if (str[i] == string2[i])
			{
				count = count + 1;
				i = i + 1;
			}
			else if (str[i]<string2[i])
			{
				return  -1;
			}
			else if (str[i]>string2[i])
			{
				return  1;
			}
		}
	}
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] == string2[i] || str[i] - 32 == string2[i] || str[i] + 32 == string2[i])
			{
				count = count + 1;
				i = i + 1;
			}
			else if (str[i]<string2[i])
			{
				return  -1;
			}
			else if (str[i]>string2[i])
			{
				return  1;
			}
		}
	}
	if (count == strLength2)
	{
		return 0;
	}
	else if (count<strLength2)
	{
		return -1;
	}
	return 1;
}
String& String::operator = ( const String& ref)
{

	if( this -> != &ref)
	{
		this -> ~String();
		this -> size = ref.size;
		this -> str = new char[ this-> size];
		int i = 0 ;
		while(ref.str[i] != '\0')
		{
			this -> str[i] = ref.str[i];
			i = i + 1;
		}
		this -> str[i] = '\0';

	}
	return  *this;

}

