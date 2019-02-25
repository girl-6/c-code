#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date()      //无参构造函数
//	{}
//	Date(int year, int month, int day)        //带参构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void TestDate()
//{
//	Date d1;    //调用无参构造函数
//	d1.Print();
//	Date d2(2015, 1, 1);       //调用带参构造函数
//	d2.Print();
//	Date d3();       //有（）表示声明了d3函数，该函数无参，返回日期类对象
//}

//class Date
//{
//public:
//	//用户如果显式定义了构造函数，编译器将不再生成
//	/*Date(int year, int month, int day)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	//未定义构造函数，对象也可以创建成功
//	//由此证明此处调用的是编译器生成的默认构造函数
//	Date d;
//}

class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
private:
	//内置类型（未进行操作）
	int _year;
	int _month;
	int _day;
	//自定义类型（已初始化）
	Time _t;
};

int main()
{
	Date d;
	system("pause");
	return 0;
}
