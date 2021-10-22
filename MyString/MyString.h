#pragma once
#ifndef _MY_STRING_H_

#include <iostream>
#include <fstream>
using namespace std;
class MyString
{
	char* str;
	int size;
public:
	MyString() {
		size = 0;
		str = new char[1];
		str[0] = NULL;
	}
	~MyString() {
		if (str != NULL)
		{
			size = 0;
			delete str;
			str[0] = '\0';
		}
	}

	friend istream& operator>>(istream&, MyString&);
	friend ostream& operator<<(ostream&, const MyString&);

	int length();
	char* subString(const int&, const int&);
	char* operator+(const MyString&);

	char* insert(const int& , const MyString& );
	char* erase(const int&, const int&);
	char* replace(const int& , const int& , const MyString& );
	bool find(const int&, const MyString&);
};

#endif // !_MY_STRING_H_