#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//重载全局 operator==
//1.公有成员变量，类外实现重载
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day; 
//	}
// //private 限定类外无法访问。 重载全局运算符就要求它们为公有成员所以暂时屏蔽
//	int _year;
//	int _month;
//	int _day;
//};
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year&& d1._month == d2._month&&d1._day == d2._day;
//}
//void Test()
//{
//	Date d1(2001, 1, 1);
//	Date d2(2010, 2, 3);
//	cout << (d1 == d2) << endl; 
//}
//2.私有成员变量，类内重载实现
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator==( const Date &d2)   //第一个操作数默认为this指向的调用函数的对象
//	{
//		return _year == d2._year&&_month == d2._month&&_day == d2._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2001, 1, 1);
//	Date d2(2010, 2, 3);
//	cout << (d1 == d2) << endl;    //或d1.operator==(d2)
//}

//赋值运算符重载
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	Date operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//// 默认赋值重载运算符
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
// //Test();
//	Date d1;
//	Date d2(2019, 1, 2);
//	d1 = d2;   //这里d1会调用编译器生成的operator=完成赋值
//	system("pause");
//	return 0;
//}

// String 类
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
	//解决方法：
	String& operator=(const String& s)   //重载赋值运算符
	{
		if (this != &s)
		{
			char* pstr = (char*)malloc(strlen(s._str) + 1);
			strcpy(pstr, s._str);
			delete[]_str;
			_str = pstr;
		}
		return *this;
	}
private:
	char* _str;
};
//int main()
//{
//	String s1("hello");
//	String s2("world");
//	s1 = s2;    //程序在这里会崩溃，因为要调用两次~String()
//}

String(const String& s)
:_str(new char[strlen(s._str)+1])
{
	strcpy(_str, s._str);
}
