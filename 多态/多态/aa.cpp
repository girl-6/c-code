#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
 

  //多态
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "全价票" << endl;
//	}
//};
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "半价票" << endl;
//	}
//};
//void func(Person &p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person p;
//	Student s;
//	func(p);     //构成多态，不同继承关系的类对象调用同一函数
//	func(s);
//	system("pause");
//	return 0;
//}

//     //不构成多态,不同的对象调用相同函数
//int main()
//{
//	Person p;
//	Student s;
//	p.BuyTicket();
//	s.BuyTicket();
//	return 0;
//}
   //协变
//class A{};
//class B :public A{};
//class Person
//{
//public:
//	virtual A* f()  { return new A; }
//};
//class Student :public Person
//{
//public:
//	virtual B* f()  { return new B; }
//};


//析构函数的重写
//class Person
//{
//public:
//	virtual ~Person() { cout << "~Person" << endl; }
//};
//class Student :public Person
//{
//public:
//	virtual ~Student() { cout << "~Studennt" << endl; }  //可不加virtual关键字，但不建议这样做
//};
//int main()
//{
//	Person *p1 = new Person;    //指向父类的指针
//	Person *p2 = new Student;    //指向子类的指针
//	delete p1;    
//	delete p2;
//	system("pause");
//	return 0;
//}

    //抽象类
//class Car
//{
//public:
//	virtual void Drive() = 0;    //纯虚函数
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "舒适" << endl; }
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive() { cout << "简单" << endl; }
//};
//void Test()
//{
//	//Car c;    //Car是抽象类，无法实例化对象
//	Car *p1 = new Benz;
//	p1->Drive();
//	Car *p2 = new BMW;
//	p2->Drive();
//}

   //override 强制子类虚函数必须重写
//class Car
//{
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() override { cout << "舒适" << endl; }
//};
  //final 修饰基类虚函数不能重写
class Car
{
public:
	virtual void Drive() final {}
};
class Benz :public Car
{
public:
	//virtual void Drive() { cout << "舒适" << endl; }  //编译无法通过！！
};