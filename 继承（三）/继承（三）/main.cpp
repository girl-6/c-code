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
class Student:virtual public Person    //����̳з�ʽ
{
protected:
	int _no;
};
class Teacher:virtual public Person   //����̳з�ʽ
{
protected:
	int _id;
};
class Assistant :public Student, public Teacher
{
	string _course;     //���޿γ�
};
void Test()
{
	Assistant a;
	a._name = "ly";     //��virtual �ؼ���ʱ��_name�Ķ����Դ����������

	//ָ����Ա����������Խ�������ԣ�ȴ������������������
	a.Student::_name = "ll";
	a.Teacher::_name = "yy";
}
int main()
{
	Test();
	system("pause");
	return 0;
}