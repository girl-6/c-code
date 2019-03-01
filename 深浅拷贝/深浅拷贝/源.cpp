#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//class A
//{
//public:
//	A()      // 构造函数，p指向堆中分配的一空间
//	{
//		p = new int(10);
//	}
//	~A()     // 析构函数，释放动态分配的空间
//	{
//		cout << "~A()" << endl;
//		delete p;
//	}
//	A(const A &a)
//	{
//		w=a.w;
//		h = a.h;
//		p = new int;
//		*p = *(a.p);
//	}
//private:
//	int w;
//	int h;
//	int *p;     // 指针成员
//};
//
//int main()
//{
//	A a1;
//	a1.~A();
//	A a2(a1);   // 复制对象
//	a2.~A();
//	system("pause");
//	return 0;
//}

// 防止按值传递
class CExample
{
private:
	int a;

public:
	//构造函数
	CExample(int b)
	{
		a = b;
		cout << "creat: " << a << endl;
	}

//private:
	//拷贝构造，只是声明
	CExample(const CExample& C);
//public:
	~CExample()
	{
		cout << "delete: " << a << endl;
	}
	void Show()
	{
		cout << a << endl;
	}
};

//全局函数
void g_Fun(CExample C)
{
	cout << "test" << endl;
}

int main()
{
	CExample test(1);
	g_Fun(test);   //按值传递将出错
	system("pause");
	return 0;
}

