#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream >
using namespace std;

   // 继承
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//	
//protected:
//	string _name = "ly";
//	int _age = 21;
//private:
//	string _sex ="女";
//};
//class Student :public Person     //public 继承下
//{
//public:
//	void Display()
//	{
//		Print();       //可以访问基类的public 成员函数
//		cout << _age << endl;    //可以访问基类的protect 成员变量
//		//cout << _sex << endl; //不可访问基类的private成员变量！所以编译不通过！
//		cout << _id << endl;     //可以访问派生类的protected 成员
//	}
//protected:
//	int _id= 160;
//};
//class Teacher :public Person
//{
//protected:
//	int _tid;
//};
//int main()
//{
//	Student s;
//	s.Display();
//	system("pause");
//	return 0;
//}

   //赋值转换
//class Person
//{
//protected:
//	string _name;    //姓名
//	int  _age;      //年龄
//	string _sex;    //性别
//};
//class Student :public Person
//{
//public:
//	int _id;     //学号
//};
//void Test()
//{
//	Student s;
//	//1）子类对象可以赋值给父类（切片）
//	Person p = s;      //对象
//	Person *pp = &s;   //指针
//	Person &rp = s;   //引用
//
//	//2）基类对象不能赋值给派生类对象
//	//s = p;      //编译不通过
//
//	//3)基类指针可以通过强制类型转换赋值给派生类指针
//	pp = &s;       //父类指针pp原本指向子类
//	//pp->_id = 10;    //此时pp无法访问子类的成员
//	Student *ps1 = (Student*)pp;   //将父类指针强转为子类指针
//	ps1->_id = 10;       //pp可以访问子类成员
//	
//	pp = &p;       //父类指针pp原本指向父类
//	Student *ps2 = (Student*)pp;   //也可以转换成功，但会存在越界访问的问题
//	ps2->_id = 10;
//}

    //继承中的作用域
//class Person
//{
//protected:
//	string _name = "小明";
//	int _num = 111;
//};
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名： "<<_name << "  ";        //小明
//		cout << "身份证号：" << Person::_num << "  ";      //111
//		//cout << "身份证号："<<_num << "  ";   //不指定_num的作用域时，默认输出99
//		cout <<"学号："<< _num << endl;             //99
//
//	}
//protected:
//	int _num = 99;
//};
//void Test()
//{
//	Student s;
//	s.Print();
//}

//class A
//{
//public:
//	void fun() { cout << "A" << "  "; }
//};
//class B  :public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		//fun();   //未指定作用域，编译不通过！！
//		cout << "B->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);  //子类对象调用子类成员
//	b.A::fun();  //子类对象调用同名父类成员，已指定作用域
//	//b.fun();    //1.父类fun函数被隐藏 2.子类fun函数不匹配，编译不通过！！
//	A a;
//	a.fun();   //父类对象调用父类成员
//	//a.fun(10);   //父类对象无法调用子类成员，编译不通过！！
//
//}

   //派生类的默认成员函数
//class Person                           //父类
//{
//public:
//	Person(const char* name = "ly")    //构造,最好写成全缺省，方便子类直接调用
//		:_name(name)
//	{
//		cout << "Person()"<< endl;
//	}
//	Person(const Person& p)     //拷贝构造
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator =(const Person&p)     //赋值重载
//	{
//		cout << "Person& operator =(const Person&p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()                 //析构
//	{ 
//		cout << "~Person()" << endl;
//	}       
//protected:
//	string _name;
//};
//
//class Student :public Person        //子类
//{
//public:
//	Student(const char* name, int num)    //构造
//		:Person(name)  //子类不能自己初始化父类成员，即不能用_name("ly")初始化 
//		, _num(num)
//	{
//		cout << "Student(const char* name, int num)" << endl;
//	}
//	Student(const Student&s)     //拷贝构造
//		: Person(s)       //切片完成拷贝构造
//		, _num(s._num)
//	{
//		cout << "Student(const Student&s) " << endl;
//	}
//	Student &operator=(const Student &s)    //赋值重载
//	{
//		cout << "Student &operator=(const Student &s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);    //父类operator=和子类函数会构成隐藏，所以必须指明作用域
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()         //析构
//	{
//		cout << "~Student() " << endl;   //父类空间编译器负责清理
//	}
//protected:
//	int _num;
//};
//void Test()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s3 = s1;
//}

   //面试题：实现一个不能被继承的类
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};
//class NonInherit final
//{};
int main()
{
	//Test();
	system("pause");
	return 0;
}
