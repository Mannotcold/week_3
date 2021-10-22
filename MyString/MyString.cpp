#include "MyString.h"

istream& operator>>(istream& inStr, MyString& s)
{
	char* tmp = new char[100];
	inStr >> tmp;

	s.size = strlen(tmp);

	s.str = new char[s.size + 1];

	strcpy_s(s.str, s.size + 1, tmp);


	delete[] tmp;
	tmp = NULL;

	return inStr;
}

ostream& operator<<(ostream& outStr, const MyString& s)
{
	outStr << s.str;
	return outStr;
}


char* MyString::operator +(const MyString& s2) {

	char* tmp = new char[size + s2.size + 1];

	for (int i = 0; i < strlen(str);i++)
		tmp[i] = str[i];
	for (int i = 0;i < strlen(s2.str); i++)
		tmp[strlen(str) + i] = s2.str[i];

	tmp[strlen(str) + strlen(s2.str)] = '\0';

	return tmp;
}

int MyString::length()
{
	return this->size;
}


char* MyString::subString(const int& start, const int& count)
{
	if (start < 0 || start >= size || count < 0)
		return NULL;

	int len = count + 1;
	char* tmp = new char[len];	
	int sizeStr = 0;

	for (int i = start; i < start + count && i < size; i++)
		tmp[sizeStr++] = this->str[i];

	tmp[sizeStr] = '\0';

	return tmp;
}



char* MyString::insert(const int& idx, const MyString& s) {

	char* tmp = new char[size + s.size + 1];

	if (idx < 0 || idx > size)
		return NULL;

	for (int i = 0; i < idx; i++)			
		tmp[i] = str[i];

	for (int i = 0; i < s.size; i++)		
		tmp[i + idx] = s.str[i];

	for (int i = idx; i <= size; i++)		
		tmp[i + s.size] = str[i];

	return tmp;
}

char* MyString::erase(const int& start, const int& count)
{
	if (start < 0) return NULL;

	if (start < this->size) {
		char* tmp = this->subString(0, start);

		if (start + count < this->size) {			//Check the number of elements is deleted
			int i = start + count;
			int j = start;
			for (; i < this->size; i++,j++)
				tmp[j] = this->str[i];
			tmp[j] = '\0';
		}
		return tmp;
	}
	return this->str;
}


char* MyString::replace(const int& start, const int& length, const MyString& s2)
{
	if (start > this->size || start < 0) return NULL;

	char* tmp = this->insert(start, s2);
	int dis = start + length;

	if (start < this->size && dis < strlen(tmp)) {			 //Check the number of elements is replaced
		int len = strlen(s2.str), i = start + len;

		for (int j = 0;; i++, j++) {
			if (tmp[i + length] == NULL) break;
			tmp[i] = tmp[i + length];
		}

		tmp[i] = '\0';
	}
	else if (dis >= strlen(tmp)) {
		tmp[start + s2.size] = '\0';
	}

	return tmp;
}

bool MyString::find(const int& start, const MyString& s2)
{
	int j, i;
	for (i = start; i < size; i++)
	{
		for (j = 0; j < s2.size; j++)
		{
			if (str[i + j] != s2.str[j])
				break;
		}
		if (j == s2.size)
			return true;
	}
	return false;
}
