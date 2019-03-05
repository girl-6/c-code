#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//class A
//{
//public:
//	friend ostream & operator<<(ostream& _cout, const A& a);
//	A(int a = 10)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//ostream & operator<<(ostream& _cout, const A& a)
//{
//	_cout << a._a;
//	return _cout;
//}

//class A
//{
//public:
//
//	A(int a = 10)
//	{
//		_a = a;
//	}
//	void operator<<(ostream &out)
//	{
//		out << _a;
//	}
//private:
//	int _a;
//};

//int main()
//{
//	A a;
//	cout << a << endl;
//	//a << cout;
//	//a.operator<<(cout) ;
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	friend ostream &operator <<(ostream& _cout, const Date& d);     //输出，所有加const表示只读数据
//	friend istream &operator >>(istream& _cin,  Date& d);          //输入，允许改写数据
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
//ostream &operator<<(ostream &_cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream &operator>>(istream &_cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d(2018,1,1);
//	cin >> d;
//	cout << d << endl;
//	system("pause");
//	return 0;
//}


//class Date;           //前置声明
//class Time
//{
//	friend class Date;     //声明为Date友元类，即Date类可直接访问Time类的私有成员
//public:
//	Time(int hour=11,int minute=59,int second=59)
//		:_hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void setTimeOfDate(int hour, int minute, int second)
//	{
//		//可以直接访问时间类的私有成员
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日"<< _t._hour 
//			<< "时" << _t._minute << "分" << _t._second << "秒"<<endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d;
//	d.setTimeOfDate(16,17,18);
//	d.Print();
//	system("pause");
//	return 0;
//}

//内部类
class A
{
private:
	static int _k;              //静态成员
	int _h;                     //私有成员
public:
	A()
	{
		_h = 10;
	}
	class B          //B是A的内部类，B可直接访问A的成员变量
	{
	public:
		void fun(const A&a)
		{
			cout << _k << "  " << a._h << endl;//_k是静态成员可直接访问，_h是私有成员要通过对象的调用
		}
	};
};
int A::_k = 10;               //静态成员必须在类外初始化
int main()
{
	A::B b;                                     // :: 访问限定符，表明B在A内
	b.fun(A());                           //未定义A类的对象，所以函数参数用A类构造一个对象
	cout << sizeof(A) << endl;      //4   static存在静态区，class B 内部类不占空间，故sizeof(int _h)=4
	cout << sizeof(A::B) << endl;       //1   B是空类，故为1
	system("pause");
	return 0;
}