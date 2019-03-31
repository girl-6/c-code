#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

   //虚函数表
//class Base    //sizeof(Base)=8
//{
//public:
//	virtual void func1() { cout << "func1" << endl; }
//	virtual void func2() { cout << "func2" << endl; }
//	void func3() { cout << "func3" << endl; }
//private:
//	int _b = 1;
//};
////我们增加一个派生类去继承Base，在派生类中重写func1
////基类Base中增加一个虚函数和一个普通函数
//class Derive :public Base
//{
//public:
//	virtual void func1() { cout << "Derive" << endl; }
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	cout << sizeof(b) << endl;      //8
//	cout << sizeof(d) << endl;      //12
//	system("pause");
//	return 0;
//}

    //单继承中的虚函数表
//class Base   
//{
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "func2" << endl; }
//private:
//	int _b = 1;
//};
//class Derive :public Base
//{
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "fun3" << endl; }
//	virtual void func4() { cout << "fun4" << endl; }
//private:
//	int _d = 2;
//};
//typedef void(*VFPTR)();
//void PrintVTable(VFPTR VTable[])
//{
//	cout << "虚表地址" << VTable << endl;    
//	for (int i = 0; VTable[i] != nullptr; ++i)
//	{
//		printf("第%d个虚函数的地址：0x%x,->", i, VTable[i]);
//		VFPTR f = VTable[i];
//		f();
//	}
//	cout << endl;
//}
// /* 1）取出b, d对象的头4个字节即虚表指针
//	  具体做法将对象地址取出强转成（int*）的指针，再解引用取值时就是头四个字节的值，这个值就是指向虚表的指针
//    2）将值强转成(VFPTR*)，因为虚表是存VFPTR类型(虚函数指针)的指针数组
//    3）虚表指针传递给PrintVTable()函数进行打印虚表（nullptr是虚表结束标志）
//    4）注意：这里程序如果崩溃不是代码的问题，而是编译器的问题因为它对之前虚表的处理不干净，我们只需要生成 - 清理解决方案，再编译运行就可以了*/
//int main()
//{
//	Base b;
//	Derive d;
//	VFPTR *tb = (VFPTR*)(*(int*)&b);
//	PrintVTable(tb);
//	VFPTR *td = (VFPTR*)(*(int*)&d);
//	PrintVTable(td);
	//system("pause");
	//return 0;
//}

      //多继承中的虚函数表
class Base1
{
public:
	virtual void func1()  { cout << "B1:func1" << endl; }
	virtual void func2()  { cout << "B1:func2" << endl; }
private:
	int b1;
};
class Base2
{
public:
	virtual void func1()  { cout << "B2:func1" << endl; }
	virtual void func2()  { cout << "B2:func2" << endl; }
private:
	int b2;
};
class Derive :public Base1, public Base2
{
public:
	virtual void func1()  { cout << "D:func1" << endl; }
	virtual void func3()  { cout << "D:func3" << endl; }
private:
	int d;
};
typedef void(*VFPTR)();
void PrintVTable(VFPTR VTable[])
{
	cout << "虚表地址" << VTable << endl;
	for (int i = 0; VTable[i] != nullptr; ++i)
	{
		printf("第%d个虚函数的地址：0x%x,->", i, VTable[i]);
		VFPTR f = VTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Derive d;
	VFPTR *t1 = (VFPTR*)(*(int*)&d);         //Derive中Base1的虚表地址
	PrintVTable(t1);
	VFPTR *t2 = (VFPTR*)(*(int *)((char*)&d + sizeof(Base1)));    //Derive中Base2的虚表地址
	PrintVTable(t2);
	system("pause");
	return 0;
}