#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;

//��������д����˼��������
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

//C++11 ��Ա��ʼ��
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
	//�Ǿ�̬��Ա���������ڶ���ʱֱ�ӳ�ʼ��
private:
	int a = 10;
	B b = 20;
	int *p = (int *)malloc(4);
	static int c;     //��̬��Ա�������������ⶨ��
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