#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//class Date
//{
//public:
//	Date()      //�޲ι��캯��
//	{}
//	Date(int year, int month, int day)        //���ι��캯��
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
//	Date d1;    //�����޲ι��캯��
//	d1.Print();
//	Date d2(2015, 1, 1);       //���ô��ι��캯��
//	d2.Print();
//	Date d3();       //�У�����ʾ������d3�������ú����޲Σ��������������
//}

//class Date
//{
//public:
//	//�û������ʽ�����˹��캯��������������������
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
//	//δ���幹�캯��������Ҳ���Դ����ɹ�
//	//�ɴ�֤���˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��
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
	//�������ͣ�δ���в�����
	int _year;
	int _month;
	int _day;
	//�Զ������ͣ��ѳ�ʼ����
	Time _t;
};

int main()
{
	Date d;
	system("pause");
	return 0;
}
