#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>    //greater算法的头文件
#include<iostream>
using namespace std;

//   //1.priority_queue 中放内置类型时
//void TestPQ1()
//{
//	//priority_queue<int> q1;       //默认建大堆
//	priority_queue<int, vector<int>, greater<int>> q1;      //建小堆，加头文件换参数
//	q1.push(1);
//	q1.push(2);
//	q1.push(3);
//	q1.push(4);
//	q1.push(5);
//	while (!q1.empty())
//	{
//		cout << q1.top() << " ";
//		q1.pop();
//	}
//	cout << endl;
//}

//    //2.priority_queue 中放自定义类型时，要重载> <
//class Date
//{
//public:
//	Date(int year = 1999, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	bool operator < (const Date& d)const          //重载小于号
//	{
//		return (_year < d._year) || (_year == d._year && _month < d._month)
//			   || (_year == d._year && _month == d._month && _day < d._day);
//	}
//	bool operator >(const Date& d)const         //重载大于号
//	{
//		return (_year > d._year) || (_year == d._year && _month > d._month)
//			|| (_year == d._year && _month == d._month && _day > d._day);
//	}
//	friend  ostream &operator<<(ostream& _cout, const Date& d)       //重载输出符号
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestPQ2()
//{
//	//priority_queue<Date> q2;       //默认建大堆
//	priority_queue<Date, vector<Date>, greater<Date>> q2;
//	q2.push(Date(2018, 12, 11));
//	q2.push(Date(2014, 11, 01));
//	q2.push(Date(2014, 12, 14));
//	q2.push(Date(2015, 03, 21));
//	while (!q2.empty())
//	{
//		cout << q2.top() << " ";
//		q2.pop();
//	}
//}

//     //有些情况下，用户提供比较器规则    
//class Goods
//{
//public:
//	bool operator<(const Goods r) const
//	{
//		return _price < r._price;
//	}
//public:
//	int _price;
//	int _sales_volume;
//	int _evaluation;
//	int _comprehensive;
//};
//
//struct GoodsPriceLess         //大堆的比较规则
//{
//	bool operator()(const Goods& l, const Goods& r)
//	{
//		return l._price < r._price;
//	}
//};
//
//struct GoodsPriceGreater         //小堆的比较规则
//{
//	bool operator()(const Goods& l, const Goods& r)
//	{
//		return l._price > r._price;
//	}
//};
//void TestPQ3()
//{
//	priority_queue<Goods, vector<Goods>, GoodsPriceLess> goodspq;
//	goodspq.push(Goods{ 1, 8, 8, 4 });
//	goodspq.push(Goods{ 9, 8, 7, 6 });
//
//	Goods top = goodspq.top();
//	cout << top._price << "  ";
//	cout << top._sales_volume << "  ";
//	cout << top._evaluation << "  ";
//	cout << top._comprehensive << endl;
//}

template<class T, class Container = vector<T>, class Compare = less<T>>
class PriorityQueue
{
public:
	void Adjustup(int child)
	{
		int parent = (child - 1) >> 1;
		while (child > 0)
		{
			Compare com;
			if (com(_con[parent], _con[child]))
			{
				swap(_con[parent], _con[child]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}

	void Push(const T& x)
	{
		_con.push_back(x);
		Adjustup(_con.size() - 1);
	}

	void AdjustDown(int parent)
	{
		int child = parent * 2 + 1;
		while (child < _con.size())
		{
			Compare com;
			if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
			{
				++child;
			}

			if (com(_con[parent], _con[child]))
			{
				swap(_con[parent], _con[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	void Pop()
	{
		swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		AdjustDown(0);
	}

	const T& Top()
	{
		return _con[0];
	}

	size_t Size()
	{
		return _con.size();
	}

	bool Empty()
	{
		return _con.empty();
	}
private:
	Container _con;
};
void TestPQ4()
{
	PriorityQueue<int> q4;
	q4.Push(4);
	q4.Push(3);
	q4.Push(8);
	q4.Push(1);
	cout << q4.Top() << endl;
}

int main()
{
	//TestPQ1();
	//TestPQ2();
	//TestPQ3();
	TestPQ4();
	system("pause");
	return 0;
}

