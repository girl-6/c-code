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
//	friend ostream &operator <<(ostream& _cout, const Date& d);     //��������м�const��ʾֻ������
//	friend istream &operator >>(istream& _cin,  Date& d);          //���룬�����д����
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


//class Date;           //ǰ������
//class Time
//{
//	friend class Date;     //����ΪDate��Ԫ�࣬��Date���ֱ�ӷ���Time���˽�г�Ա
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
//		//����ֱ�ӷ���ʱ�����˽�г�Ա
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//	void Print()
//	{
//		cout << _year << "��" << _month << "��" << _day << "��"<< _t._hour 
//			<< "ʱ" << _t._minute << "��" << _t._second << "��"<<endl;
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

//�ڲ���
class A
{
private:
	static int _k;              //��̬��Ա
	int _h;                     //˽�г�Ա
public:
	A()
	{
		_h = 10;
	}
	class B          //B��A���ڲ��࣬B��ֱ�ӷ���A�ĳ�Ա����
	{
	public:
		void fun(const A&a)
		{
			cout << _k << "  " << a._h << endl;//_k�Ǿ�̬��Ա��ֱ�ӷ��ʣ�_h��˽�г�ԱҪͨ������ĵ���
		}
	};
};
int A::_k = 10;               //��̬��Ա�����������ʼ��
int main()
{
	A::B b;                                     // :: �����޶���������B��A��
	b.fun(A());                           //δ����A��Ķ������Ժ���������A�๹��һ������
	cout << sizeof(A) << endl;      //4   static���ھ�̬����class B �ڲ��಻ռ�ռ䣬��sizeof(int _h)=4
	cout << sizeof(A::B) << endl;       //1   B�ǿ��࣬��Ϊ1
	system("pause");
	return 0;
}