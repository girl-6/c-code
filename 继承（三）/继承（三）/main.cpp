#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

  //���μ̳м���������̳�
//class Person
//{
//public:
//	string _name;
//};
//class Student:virtual public Person    //����̳з�ʽ
//{
//protected:
//	int _no;
//};
//class Teacher:virtual public Person   //����̳з�ʽ
//{
//protected:
//	int _id;
//};
//class Assistant :public Student, public Teacher
//{
//	string _course;     //���޿γ�
//};
//void Test()
//{
//	Assistant a;
//	a._name = "ly";     //��virtual �ؼ���ʱ��_name�Ķ����Դ����������
//
//	//ָ����Ա����������Խ�������ԣ�ȴ������������������
//	a.Student::_name = "ll";
//	a.Teacher::_name = "yy";
//}

   //��̳��е�ָ��ƫ��
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
class C :public A, public B     //c�����Ա��̳�˳���й�
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
//C.p1==p3!=p2    ��ȷ
//D.p1!=p2!=p3