#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

     //友元关系不能继承
//class Student;      //声明一个类
//class Person
//{
//public:
//	friend void Display(const Person & p, const Student&s);
//protected:
//	string _name;
//};
//class Student :public Person
//{
//protected:
//	int _No;
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	//下面编译不通过，因为基类的友元函数无法访问派生类成员
//	cout << s._No << endl;  
//}

    //继承中定义的静态成员，在整个体系中都是同一个变量
//class Person
//{
//public:
//	Person()   { ++_count; }
//protected:
//	string _name;
//public:
//	static int _count;   //统计人数
//};
//int Person::_count = 0;    //静态成员要在类外定义
//class Student :public Person
//{
//protected:
//	int _No;
//};
//class Graduade :public Student
//{
//protected:
//	int _ID;
//};
//void Test()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduade g1;
//	cout <<"人数:"<< Person::_count << endl;    //4
//	Student::_count = 0;
//	cout << "重置后人数:" << Person::_count << endl;     //0,说明基类中定义的static成员在整个继承体系在只有一个
//}

       //继承和组合
  //Car和BMW Benz 构成is-a 的关系
class Car
{
protected:
	string _colour = "白色";     //颜色
	string _num = "陕A123";     //车牌号
};
class BMW :public Car
{
public:
	void Drive()
	{
		cout << "简单" << endl;
	}
};
class Benz :public BMW
{
public:
	void Drive()
	{
		cout << "舒适" << endl;
	}
};
void Test1()
{
	Benz car;
	car.Drive();
}

  //Tire和Car构成has-a 的关系
//class Tire
//{
//protected:
//	string _brand = "Michelin";   //品牌
//};
//class Car
//{
//protected:
//	string _colour = "白色";    //颜色
//	string _num = "陕A123";    //车牌号
//	Tire _t;               //轮胎
//};
//void Test1()
//{
//	Car _c;
//
//}
int main()
{
	//Test();
	Test1();
	system("pause");
	return 0;
}