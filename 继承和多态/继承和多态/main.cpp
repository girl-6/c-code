#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream >
using namespace std;

   // �̳�
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
//	string _sex ="Ů";
//};
//class Student :public Person     //public �̳���
//{
//public:
//	void Display()
//	{
//		Print();       //���Է��ʻ����public ��Ա����
//		cout << _age << endl;    //���Է��ʻ����protect ��Ա����
//		//cout << _sex << endl; //���ɷ��ʻ����private��Ա���������Ա��벻ͨ����
//		cout << _id << endl;     //���Է����������protected ��Ա
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

   //��ֵת��
//class Person
//{
//protected:
//	string _name;    //����
//	int  _age;      //����
//	string _sex;    //�Ա�
//};
//class Student :public Person
//{
//public:
//	int _id;     //ѧ��
//};
//void Test()
//{
//	Student s;
//	//1�����������Ը�ֵ�����ࣨ��Ƭ��
//	Person p = s;      //����
//	Person *pp = &s;   //ָ��
//	Person &rp = s;   //����
//
//	//2����������ܸ�ֵ�����������
//	//s = p;      //���벻ͨ��
//
//	//3)����ָ�����ͨ��ǿ������ת����ֵ��������ָ��
//	pp = &s;       //����ָ��ppԭ��ָ������
//	//pp->_id = 10;    //��ʱpp�޷���������ĳ�Ա
//	Student *ps1 = (Student*)pp;   //������ָ��ǿתΪ����ָ��
//	ps1->_id = 10;       //pp���Է��������Ա
//	
//	pp = &p;       //����ָ��ppԭ��ָ����
//	Student *ps2 = (Student*)pp;   //Ҳ����ת���ɹ����������Խ����ʵ�����
//	ps2->_id = 10;
//}

    //�̳��е�������
//class Person
//{
//protected:
//	string _name = "С��";
//	int _num = 111;
//};
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << "������ "<<_name << "  ";        //С��
//		cout << "���֤�ţ�" << Person::_num << "  ";      //111
//		//cout << "���֤�ţ�"<<_num << "  ";   //��ָ��_num��������ʱ��Ĭ�����99
//		cout <<"ѧ�ţ�"<< _num << endl;             //99
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
//		//fun();   //δָ�������򣬱��벻ͨ������
//		cout << "B->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);  //���������������Ա
//	b.A::fun();  //����������ͬ�������Ա����ָ��������
//	//b.fun();    //1.����fun���������� 2.����fun������ƥ�䣬���벻ͨ������
//	A a;
//	a.fun();   //���������ø����Ա
//	//a.fun(10);   //��������޷����������Ա�����벻ͨ������
//
//}

   //�������Ĭ�ϳ�Ա����
//class Person                           //����
//{
//public:
//	Person(const char* name = "ly")    //����,���д��ȫȱʡ����������ֱ�ӵ���
//		:_name(name)
//	{
//		cout << "Person()"<< endl;
//	}
//	Person(const Person& p)     //��������
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator =(const Person&p)     //��ֵ����
//	{
//		cout << "Person& operator =(const Person&p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()                 //����
//	{ 
//		cout << "~Person()" << endl;
//	}       
//protected:
//	string _name;
//};
//
//class Student :public Person        //����
//{
//public:
//	Student(const char* name, int num)    //����
//		:Person(name)  //���಻���Լ���ʼ�������Ա����������_name("ly")��ʼ�� 
//		, _num(num)
//	{
//		cout << "Student(const char* name, int num)" << endl;
//	}
//	Student(const Student&s)     //��������
//		: Person(s)       //��Ƭ��ɿ�������
//		, _num(s._num)
//	{
//		cout << "Student(const Student&s) " << endl;
//	}
//	Student &operator=(const Student &s)    //��ֵ����
//	{
//		cout << "Student &operator=(const Student &s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s);    //����operator=�����ຯ���ṹ�����أ����Ա���ָ��������
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()         //����
//	{
//		cout << "~Student() " << endl;   //����ռ��������������
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

   //�����⣺ʵ��һ�����ܱ��̳е���
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
