#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
 

  //��̬
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "ȫ��Ʊ" << endl;
//	}
//};
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "���Ʊ" << endl;
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
//	func(p);     //���ɶ�̬����ͬ�̳й�ϵ����������ͬһ����
//	func(s);
//	system("pause");
//	return 0;
//}

//     //�����ɶ�̬,��ͬ�Ķ��������ͬ����
//int main()
//{
//	Person p;
//	Student s;
//	p.BuyTicket();
//	s.BuyTicket();
//	return 0;
//}
   //Э��
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


//������������д
//class Person
//{
//public:
//	virtual ~Person() { cout << "~Person" << endl; }
//};
//class Student :public Person
//{
//public:
//	virtual ~Student() { cout << "~Studennt" << endl; }  //�ɲ���virtual�ؼ��֣���������������
//};
//int main()
//{
//	Person *p1 = new Person;    //ָ�����ָ��
//	Person *p2 = new Student;    //ָ�������ָ��
//	delete p1;    
//	delete p2;
//	system("pause");
//	return 0;
//}

    //������
//class Car
//{
//public:
//	virtual void Drive() = 0;    //���麯��
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "����" << endl; }
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive() { cout << "��" << endl; }
//};
//void Test()
//{
//	//Car c;    //Car�ǳ����࣬�޷�ʵ��������
//	Car *p1 = new Benz;
//	p1->Drive();
//	Car *p2 = new BMW;
//	p2->Drive();
//}

   //override ǿ�������麯��������д
//class Car
//{
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() override { cout << "����" << endl; }
//};
  //final ���λ����麯��������д
class Car
{
public:
	virtual void Drive() final {}
};
class Benz :public Car
{
public:
	//virtual void Drive() { cout << "����" << endl; }  //�����޷�ͨ������
};