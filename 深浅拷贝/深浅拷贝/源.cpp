#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//class A
//{
//public:
//	A()      // ���캯����pָ����з����һ�ռ�
//	{
//		p = new int(10);
//	}
//	~A()     // �����������ͷŶ�̬����Ŀռ�
//	{
//		cout << "~A()" << endl;
//		delete p;
//	}
//	A(const A &a)
//	{
//		w=a.w;
//		h = a.h;
//		p = new int;
//		*p = *(a.p);
//	}
//private:
//	int w;
//	int h;
//	int *p;     // ָ���Ա
//};
//
//int main()
//{
//	A a1;
//	a1.~A();
//	A a2(a1);   // ���ƶ���
//	a2.~A();
//	system("pause");
//	return 0;
//}

// ��ֹ��ֵ����
class CExample
{
private:
	int a;

public:
	//���캯��
	CExample(int b)
	{
		a = b;
		cout << "creat: " << a << endl;
	}

//private:
	//�������죬ֻ������
	CExample(const CExample& C);
//public:
	~CExample()
	{
		cout << "delete: " << a << endl;
	}
	void Show()
	{
		cout << a << endl;
	}
};

//ȫ�ֺ���
void g_Fun(CExample C)
{
	cout << "test" << endl;
}

int main()
{
	CExample test(1);
	g_Fun(test);   //��ֵ���ݽ�����
	system("pause");
	return 0;
}

