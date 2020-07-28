#include "CString.h"
#include <iostream>
using namespace std;



CString::CString()
{
	this->size = 0;
	this->str = nullptr;
}

CString::CString(char c)
{
	this->size = 1;
	this->str = new char[2];
	this->str[0] = c;
	this->str[1] = '\0';
}

CString::CString(char *s1)
{
	this->size = 0;
	while (s1[this->size] != '\0')
	{
		this->size = this->size + 1;
	}
	this->str = new char[size + 1];

	for (int i = 0; i <= size; i++)
	{
		this->str[i] = s1[i];
	}
}

CString::CString(const CString &s1)
{
	this->size = s1.size;
	this->str = new char[size + 1];
	for (int i = 0; i < s1.size; i++)
	{
		this->str[i] = s1.str[i];
	}
	this->str[size] = '\0';
}

CString::~CString()
{
	if (this->str != nullptr)
	{
		delete[] this->str;
		this->str = nullptr;
		this->size = 0;
	}
}

void CString::setSize(int s)
{
	this->size = s;
}

void CString::setString(char *s1)
{
	this->size = 0;
	while (s1[this->size] != '\0')
	{
		this->size = this->size + 1;
	}
	this->str = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		this->str[i] = s1[i];
	}
	this->str[size] = '\0';
}



int CString::getLength(char * str)
{
	int index = 0;
	while (str[index] != '\0')
	{
		index = index + 1;
	}
	return index;
}

int CString::getLength()
{
	return size;
}

void CString::display() const
{
	if (this->str != nullptr)
	{
		cout << this->str;
	}
}

int CString::find(char *st, int start) const
{
	for (int i = start; i <= size; i++)
	{
		int index1 = 0, index2 = i;

		while (st[index1] == this->str[index2])
		{
			index1 = index1 + 1;
			index2 = index2 + 1;
			if (st[index1] == '\0')
			{
				return i;
			}
		}
	}
	return -1;
}

int CString::find(char c, int start) const
{
	int index = 0;
	while (index <= this->size)
	{
		if (this->str[index] == c)
		{
			return index;
		}
		index = index + 1;
	}
	return -1;
}

int CString::insert(int index, char * subStr)
{
	int nSize = 0;
	while (subStr[nSize] != '\0')
	{
		nSize = nSize + 1;
	}
	nSize = nSize + 1;
	char *newStr = new char[this->size + nSize + 1];
	int j = 0;
	for (int i = 0; i <index; i++)
	{
		newStr[j] = this->str[i];
		j = j + 1;
	}
	for (int i = 0; i <index; i++)
	{
		newStr[j] = subStr[i];
		j = j + 1;
	}
	int k = index;
	while (this->str[k] != '\0')
	{
		newStr[j] = this->str[k];
		j = j + 1;
		k = k + 1;
	}
	newStr[j] = '\0';
	delete[] this->str;
	this->str = newStr;
	return nSize;
}

int CString::insert(int index, char ch)
{
	this->size = this->size + 1;
	char *st = new char[size];
	int i = 0;
	while (i<this->size - 1)
	{
		st[i] = this->str[i];
		i = i + 1;
	}
	i = index;
	while (i < this->size - 1)
	{
		st[i + 1] = this->str[i];
		i = i + 1;
	}
	st[index] = ch;

	delete[] this->str;
	this->str = st;
	return this->size;
}

CString CString::left(int count) const
{
	CString leftExt;

	if (count < this->size)
	{
		leftExt.size = count;
		leftExt.str = new char[count + 1];
		for (int i = 0; i < count; i++)
		{
			leftExt.str[i] = this->str[i];
		}
		leftExt.str[count] = '\0';
	}
	else
	{
		cout << "The count of characters is greater than size of string.";
		leftExt.size = 0;
	}
	return leftExt;

}

CString CString::right(int count) const
{
	CString rightExt;
	if (count < this->size)
	{
		rightExt.size = count;
		rightExt.str = new char[count + 1];
		int index = 0;
		for (int i = size - count; i < this->size; i++)
		{
			rightExt.str[index] = this->str[i];
			index = index + 1;
		}
		rightExt.str[count] = '\0';

	}
	else
	{
		cout << "The count of characters is greater than size of string.";
		rightExt.size = 0;
	}
	return rightExt;
}


//start
int CString::remove(int index, int count)
{
	if (count < this->size - index - 2)
	{
		int i = index;
		while (this->str[i] != '\0')
		{
			this->str[i] = this->str[i + count];
			i = i + 1;
		}
		this->str[i + count] = '\0';
		return this->size - count;
	}
	else
	{
		cout << "The count of characters is greater than size of string.";
	}
	return -1;
}

int CString::remove(char ch)
{
	int count = 0;
	int i = 0;
	while (this->str[i] != '\0')
	{
		if (this->str[i] == ch)
		{
			count = count + 1;
			int j = i;
			while (this->str[j] != '\0')
			{
				this->str[j] = this->str[j + 1];
				j = j + 1;
			}
			i = i - 1;
		}
		i = i + 1;
	}
	return count;

}

void CString::replace(char newCh)
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		this->str[i] = newCh;
	}
}

int CString::replace(char old, char newCh)
{
	int i = 0, count = 0;
	while (this->str[i] != '\0')
	{
		if (this->str[i] == old)
		{
			this->str[i] = newCh;
			count = count + 1;
		}
	}
	return count;
}

int CString::replace(char * old, char * newStr)
{
	int	oldLength = getLength(old);
	int newStrLength = getLength(newStr);
	int count = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (this->find(old, i) != -1)
		{
			count = count + 1;
		}
	}
	char * temp = new char[this->size - (count * oldLength) + (count * newStrLength) + 1];

	int i = 0, j = 0;
	while (this->str[i] != '\0')
	{
		if (i == this->find(old, i))
		{
			int k = 0;
			while (newStr[k] != '\0')
			{
				temp[j] = newStr[k];
				j = j + 1;
				k = k + 1;
			}
			i = i + oldLength;
		}
		else
		{
			temp[j] = this->str[i];
			j = j + 1;
			i = i + 1;
		}
	}
	temp[j] = '\0';
	delete[] this->str;
	this->size = this->size - (count * oldLength) + (count * newStrLength);
	this->str = temp;

	return count;
}


void CString::trim()
{
	int i = 0;
	while (this->str[i] == ' ')
	{
		int j = i;
		while (this->str[j] != '\0')
		{
			this->str[j] = this->str[j + 1];
			j = j + 1;
		}
		this->size = this->size - 1;
	}
	i = 0;
	while (this->str[i] != '\0')
	{
		i = i + 1;
	}
	i = i - 1;
	while (this->str[i] == ' ')
	{
		this->str[i] = this->str[i + 1];
		i = i - 1;
		this->size = this->size - 1;
	}
}

void CString::trimLeft()
{

	while (this->str[0] == ' ')
	{
		int j = 0;
		while (this->str[j] != '\0')
		{
			this->str[j] = this->str[j + 1];
			j = j + 1;
		}
		this->size = this->size - 1;
	}
}

void CString::trimRight()
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		i = i + 1;
	}
	i = i - 1;
	while (this->str[i] == ' ')
	{
		this->str[i] = this->str[i + 1];
		i = i - 1;
		this->size = this->size - 1;
	}
}

void CString::makeUpper()
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		if (int(this->str[i]) > 96 && int(this->str[i]) < 123)
		{
			this->str[i] = (this->str[i]) - 32;
		}
		i = i + 1;
	}
}

void CString::makeLower()
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		if (int(this->str[i]) > 64 && int(this->str[i]) < 91)
		{
			this->str[i] = (this->str[i]) + 32;
		}
		i = i + 1;
	}
}

void CString::reverse()
{
	int j = this->size - 1;
	for (int i = 0; i < (this->size) / 2; i++)
	{
		int temp = this->str[i];
		this->str[i] = this->str[j];
		this->str[j] = this->str[i];

		j = j - 1;
	}
}

void CString::Resize(int add)
{
	if (this->size + add != 0)
	{
		char* temp = new char[this->size + add];
		int i = 0;
		while (this->str[i] != '\0')
		{
			temp[i] = this->str[i];
			i = i + 1;
		}
		temp[i] = '\0';
		this->size = this->size + add;
		delete[] this->str;
		this->str = temp;
	}
}

CString CString::concat(const CString & s2) const
{
	CString temp;
	temp.size = this->size + s2.size;
	temp.str = new char[temp.size + 1];
	int i = 0;
	if (this->size != 0)
	{
		while (this->str[i] != '\0')
		{
			temp.str[i] = this->str[i];
			i = i + 1;
		}
	}
	int j = 0;

	while (s2.str[j] != '\0')
	{
		temp.str[i] = s2.str[j];
		j = j + 1;
		i = i + 1;
	}
	temp.str[i] = '\0';
	return temp;
}


void CString::concatEqual(const CString & s2)
{
	char *newStr = new char[this->size + s2.size + 1];
	int index = 0;
	if (this->size != 0)
	{
		while (this->str[index] != '\0')
		{

			newStr[index] = this->str[index];
			index = index + 1;

		}

	}
	int j = 0;
	while (s2.str[j] != '\0')
	{
		newStr[index] = s2.str[j];
		j = j + 1;
		index = index + 1;

	}
	newStr[index] = '\0';

	delete[] this->str;
	this->str = newStr;
	this->size = this->size + s2.size;
}
void CString::concatEqual(const char * s2)
{
	int nSize = 0;
	while (s2[nSize] != '\0')
	{
		nSize = nSize + 1;
	}
	char * temp = new char[nSize + this->size + 1];
	int i = 0;
	if (this->size != 0)
	{
		while (this->str[i] != '\0')
		{
			temp[i] = this->str[i];
			i = i + 1;
		}

	}
	int j = 0;
	while (s2[j] != '\0')
	{
		temp[i] = s2[j];
		i = i + 1;
		j = j + 1;
	}
	temp[i] = '\0';
	delete[] this->str;
	this->str = temp;
	this->size = this->size + nSize;

}

int CString::isEqual(const CString & s2) const
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		if (this->str[i]>s2.str[i] || s2.str[i] == '\0')
		{
			return -1;
		}
		else if (this->str[i]<s2.str[i])
		{
			return 1;
		}
		i = i + 1;
	}
	if (s2.str[i] != '\0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int CString::isEqual(char * s2) const
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		if (this->str[i]>s2[i] || s2[i] == '\0')
		{
			return -1;
		}
		else if (this->str[i]<s2[i])
		{
			return 1;
		}
		i = i + 1;
	}
	if (s2[i] != '\0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void CString::input()
{
	char ch;
	cin.get(ch);

	while (ch != '\n')
	{
		this->concatEqual(ch);
		cin.get(ch);
	}
}

char & CString::at(int index)
{
	return this->str[index];
}

int CString::isEmpty()
{
	if (this->str[0] == '\0')
	{
		return 0;
	}
	else
	{
		return size;
	}
}

//
CString * CString::split(char c, int & newCount)
{
	int i = 0;
	newCount = 1;
	while (this->str[i] != '\0')
	{
		if (this->str[i] == c && this->str[i + 1] != '\0' && this->str[i - 1] != c)
		{
			newCount = newCount + 1;
		}
		i = i + 1;
	}
	if (newCount == 1)
	{
		CString * temp = new CString[1];
		return temp;
	}
	CString * subStrings = new CString[newCount];
	i = 0;
	int index = 0, j = 0, prevIndex = 0;
	while (this->str[i] != '\0')
	{
		int index = this->str[i];
		if (index == c)
		{
			subStrings[index].str = new char[index + 1];
			int k = 0;
			while (this->str[j] != c)
			{
				subStrings[index].str[k] = this->str[j];
				j = j + 1;
				k = k + 1;
			}
			subStrings[index].size = index - prevIndex;
			subStrings[index].str[k] = '\0';
			prevIndex = index;
			index = index + 1;
			j = i + 1;
		}
		i = i + 1;
	}
	if (this->str[i - 1] != c && this->str[i] == '\0')
	{
		int k = 0;
		subStrings[index].str = new char[i - j + 1];
		while (this->str[j] != '\0')
		{
			subStrings[index].str[k] = this->str[j];
			k = k + 1;
			j = j + 1;
		}
		subStrings[index].str[k] = '\0';
	}
	return subStrings;

}

CString * CString::split(char * c, int & newCount)
{
	int size1 = 0;
	while (c[size1] != '\0')
	{
		size1 = size1 + 1;
	}
	int count = 1, i = 0;
	while (this->str[i] != '\0')
	{
		if (find(c, i) != -1 && find(c, i)<this->size - size1)
		{
			count = count + 1;
			i = find(c, i) + 1;
		}
		else
		{
			i = i + 1;
		}
	}
	CString * newStr = new CString[count];
	int k = 0, objNo = 0, prevIndex = 0;
	while (this->str[k] != '\0')
	{
		int index = find(c, k);

		if (index != -1 && index <= this->size - size1)
		{
			newStr[objNo].str = new char[index - prevIndex + 1];
			int l = 0;
			while (k != index)
			{
				newStr[objNo].str[l] = this->str[k];
				l = l + 1;
				k = k + 1;
			}
			newStr[objNo].str[l] = '\0';
			newStr[objNo].size = index - prevIndex;
			objNo = objNo + 1;
			prevIndex = index + size1 - 1;
			k = prevIndex;
		}
		k = k + 1;
	}

	if (find(c, prevIndex) != this->size - size1)
	{

		newStr[objNo].str = new char[this->size - prevIndex + 1];
		int l = 0;
		k = prevIndex + 1;
		while (this->str[k] != '\0')
		{
			newStr[objNo].str[l] = this->str[k];
			l = l + 1;
			k = k + 1;
		}
		newStr[objNo].str[l] = '\0';
	}
	newCount = count;
	return newStr;
}

CString & CString::operator=(const CString & ref)
{
	this->size = ref.size;
	delete[] this->str;
	int ind = 0;
	this->str = new char[this->size + 1];
	while (ref.str[ind] != '\0')
	{
		this->str[ind] = ref.str[ind];
		ind = ind + 1;
	}
	this->str[ind] = '\0';
	return *this;
}

CString CString::operator+(const CString & s2) const
{
	CString temp;
	temp.concatEqual(*this);
	temp.concatEqual(s2);
	return temp;
}

CString CString::operator+(char * const s2) const
{
	CString temp;
	temp.concatEqual(*this);
	temp.concatEqual(s2);
	return temp;
}

void CString::operator+=(const CString & s2)
{
	this->concatEqual(s2);
}

void CString::operator+=(const char * s2)
{
	this->concatEqual(s2);
}

int CString::operator==(const CString & s2) const
{
	int ind = 0;
	if (this->str == nullptr && s2.str == nullptr)
	{
		return 0;
	}
	else if (this->str == nullptr && s2.str != nullptr)
	{
		return 1;
	}
	else if (this->str != nullptr && s2.str == nullptr)
	{
		return -1;
	}
	while (this->str[ind] != '\0')
	{
		if (this->str[ind]>s2.str[ind] || s2.str[ind] == '\0')
		{
			return -1;
		}
		else if (this->str[ind]<s2.str[ind])
		{
			return 1;
		}
		ind = ind + 1;
	}
	if (s2.str[ind] != '\0')
	{
		return 1;
	}
	return 0;
}

int CString::operator==(char * s2) const
{
	int ind = 0;
	if (this->str == nullptr && s2 == nullptr)
	{
		return 0;
	}
	else if (this->str == nullptr && s2 != nullptr)
	{
		return 1;
	}
	else if (this->str != nullptr && s2 == nullptr)
	{
		return -1;
	}
	while (this->str[ind] != '\0')
	{
		if (this->str[ind]>s2[ind] || s2[ind] == '\0')
		{
			return -1;
		}
		else if (this->str[ind]<s2[ind])
		{
			return 1;
		}
		ind = ind + 1;
	}
	if (s2[ind] != '\0')
	{
		return 1;
	}
	return 0;
}

char & CString::operator[](int index)
{
	return str[index];
}

int CString::operator!()
{
	if (this->str == nullptr)
	{
		return 0;
	}
	if (this->str[0] == '\0')
	{
		return 0;
	}
	return this->size;
}
CString CString::operator()(int start, int end) const
{

	if (start >= this->size)
	{
		CString temp('\0');
		return temp;
	}
	CString temp;
	int ind = start;
	while (this->str[ind] != '\0' && ind <= end)
	{
		temp.concatEqual(this->str[ind]);
		ind++;
	}
	return temp;
}

ostream & operator<<(ostream & os, CString strn)
{
	os << strn.str;

	return os;
}

istream & operator>>(istream & is, CString & str)
{
	char ch;
	cin.get(ch);

	while (ch != '\n')
	{
		str.concatEqual(ch);
		cin.get(ch);
	}
	return is;
}
