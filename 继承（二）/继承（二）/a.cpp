#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

     //��Ԫ��ϵ���ܼ̳�
//class Student;      //����һ����
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
//	//������벻ͨ������Ϊ�������Ԫ�����޷������������Ա
//	cout << s._No << endl;  
//}

    //�̳��ж���ľ�̬��Ա����������ϵ�ж���ͬһ������
//class Person
//{
//public:
//	Person()   { ++_count; }
//protected:
//	string _name;
//public:
//	static int _count;   //ͳ������
//};
//int Person::_count = 0;    //��̬��ԱҪ�����ⶨ��
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
//	cout <<"����:"<< Person::_count << endl;    //4
//	Student::_count = 0;
//	cout << "���ú�����:" << Person::_count << endl;     //0,˵�������ж����static��Ա�������̳���ϵ��ֻ��һ��
//}

       //�̳к����
  //Car��BMW Benz ����is-a �Ĺ�ϵ
class Car
{
protected:
	string _colour = "��ɫ";     //��ɫ
	string _num = "��A123";     //���ƺ�
};
class BMW :public Car
{
public:
	void Drive()
	{
		cout << "��" << endl;
	}
};
class Benz :public BMW
{
public:
	void Drive()
	{
		cout << "����" << endl;
	}
};
void Test1()
{
	Benz car;
	car.Drive();
}

  //Tire��Car����has-a �Ĺ�ϵ
//class Tire
//{
//protected:
//	string _brand = "Michelin";   //Ʒ��
//};
//class Car
//{
//protected:
//	string _colour = "��ɫ";    //��ɫ
//	string _num = "��A123";    //���ƺ�
//	Tire _t;               //��̥
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