#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Person
{
public:
	string _name;
};
class Student:virtual public Person    //虚拟继承方式
{
protected:
	int _no;
};
class Teacher:virtual public Person   //虚拟继承方式
{
protected:
	int _id;
};
class Assistant :public Student, public Teacher
{
	string _course;     //主修课程
};
void Test()
{
	Assistant a;
	a._name = "ly";     //无virtual 关键字时，_name的二义性带来编译错误

	//指明成员的作用域可以解决二义性，却带来了数据冗余问题
	a.Student::_name = "ll";
	a.Teacher::_name = "yy";
}
int main()
{
	Test();
	system("pause");
	return 0;
}