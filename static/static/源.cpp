#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;

//计算程序中创建了几个类对象
//class A
//{
//public:
//	A() { ++_count; }
//	A(const A& a)  { ++_count; }
//	static int GetCount(){ return _count; }
//private:
//	static int _count;
//	int a;
//};
//int A::_count = 0;
//void Test()
//{
//	cout << A::GetCount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetCount() << endl;
//}

//C++11 成员初始化
class B
{
public:
	B(int b = 0)
		:_b(b)
	{}
	int _b;
};
class A
{
public:
	void print()
	{
		cout << a << endl;
		cout << b._b << endl;
		cout << p << endl;
		cout << c << endl;
	}
	//非静态成员变量可以在定义时直接初始化
private:
	int a = 10;
	B b = 20;
	int *p = (int *)malloc(4);
	static int c;     //静态成员变量必须在类外定义
};
int A::c = 1;
int main()
{
	//Test();
	A x;
	x.print();
	system("pause");
	return 0;
}