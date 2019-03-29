#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

  //菱形继承及菱形虚拟继承
//class Person
//{
//public:
//	string _name;
//};
//class Student:virtual public Person    //虚拟继承方式
//{
//protected:
//	int _no;
//};
//class Teacher:virtual public Person   //虚拟继承方式
//{
//protected:
//	int _id;
//};
//class Assistant :public Student, public Teacher
//{
//	string _course;     //主修课程
//};
//void Test()
//{
//	Assistant a;
//	a._name = "ly";     //无virtual 关键字时，_name的二义性带来编译错误
//
//	//指明成员的作用域可以解决二义性，却带来了数据冗余问题
//	a.Student::_name = "ll";
//	a.Teacher::_name = "yy";
//}

   //多继承中的指针偏移
class A
{
public:
	int _a;
};
class B
{
public:
	int _b;
};
class C :public A, public B     //c对象成员与继承顺序有关
{
public:
	int _c;
};

int main()
{
	C c;
	A *p1 = &c;
	B *p2 = &c;
	C *p3 = &c;
	system("pause");
	return 0;
}

//A.p1==p2==p3
//B.p1<p2<p3
//C.p1==p3!=p2    正确
//D.p1!=p2!=p3