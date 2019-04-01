#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* str ="")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	CMyString(const CMyString& str)    //copy(s)
		:_str(new char[strlen(str._str)+1])
	{
		strcpy(_str, str._str);
	}
	~CMyString(void)
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
	void Print()
	{
		cout << _str << endl;
	}
	CMyString& operator=(const CMyString&str);
private:
	char *_str;
};
    //初级程序员
//CMyString& CMyString::operator=(const CMyString& str)
//{
//	if (this != &str)
//	{
//		delete[]_str;
//		_str = nullptr;
//		_str = new char[strlen(str._str) + 1];
//		strcpy(_str, str._str);
//	}
//	return *this;
//}

     //考虑到异常安全性
CMyString&CMyString::operator=(const CMyString&str)    //s2=s1
{
	if (this != &str)
	{
		CMyString strTemp(str);
		char* pTemp = strTemp._str;
		strTemp._str = _str;
		_str = pTemp;
	}
	return *this;
}

int main()
{
	CMyString s("string");
	s.Print();
	CMyString s1 = s;
	s1.Print();
	CMyString s2;
	s2 = s;
	s2.Print();
	system("pause");
	return 0;
}
