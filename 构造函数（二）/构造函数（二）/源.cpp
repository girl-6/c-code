#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
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

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:                    //初始化
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:                  //声明
//	A _aobj;              //类类型且没有默认的构造函数
//	int & _ref;           //引用
//	const int _n;        //const
//};

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//	system("pause");
//	return 0;
//}

//class Array
//{
//public:                    //先初始化了_array 再是_size
//	Array(int size)
//		:_size(size)
//		, _array((int *)malloc(sizeof(int)*_size))
//	{}
//private:
//	int* _array;
//	int _size;
//};
class Date
{
public:
	/*Date(int year)
	:_year(year)
	{}*/
	explicit Date(int year)      //禁止隐式类型转换
		:_year(year)
	{}
	void show()
	{
		cout << _year << endl;
		cout << _month << endl;
	}
private:
	int _year;
	int _month;
};
void Test()
{
	Date d1(2018);   //_year=2018,_month为随机值
	//Date d2 = 12;   //因为有 explicit，故编译失败
	d1.show();
}
int main()
{
	Test();
	system("pause");
	return 0;
}