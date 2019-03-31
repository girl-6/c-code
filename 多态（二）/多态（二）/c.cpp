#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

   //�麯����
//class Base    //sizeof(Base)=8
//{
//public:
//	virtual void func1() { cout << "func1" << endl; }
//	virtual void func2() { cout << "func2" << endl; }
//	void func3() { cout << "func3" << endl; }
//private:
//	int _b = 1;
//};
////��������һ��������ȥ�̳�Base��������������дfunc1
////����Base������һ���麯����һ����ͨ����
//class Derive :public Base
//{
//public:
//	virtual void func1() { cout << "Derive" << endl; }
//private:
//	int _d = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	cout << sizeof(b) << endl;      //8
//	cout << sizeof(d) << endl;      //12
//	system("pause");
//	return 0;
//}

    //���̳��е��麯����
//class Base   
//{
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "func2" << endl; }
//private:
//	int _b = 1;
//};
//class Derive :public Base
//{
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "fun3" << endl; }
//	virtual void func4() { cout << "fun4" << endl; }
//private:
//	int _d = 2;
//};
//typedef void(*VFPTR)();
//void PrintVTable(VFPTR VTable[])
//{
//	cout << "����ַ" << VTable << endl;    
//	for (int i = 0; VTable[i] != nullptr; ++i)
//	{
//		printf("��%d���麯���ĵ�ַ��0x%x,->", i, VTable[i]);
//		VFPTR f = VTable[i];
//		f();
//	}
//	cout << endl;
//}
// /* 1��ȡ��b, d�����ͷ4���ֽڼ����ָ��
//	  ���������������ַȡ��ǿת�ɣ�int*����ָ�룬�ٽ�����ȡֵʱ����ͷ�ĸ��ֽڵ�ֵ�����ֵ����ָ������ָ��
//    2����ֵǿת��(VFPTR*)����Ϊ����Ǵ�VFPTR����(�麯��ָ��)��ָ������
//    3�����ָ�봫�ݸ�PrintVTable()�������д�ӡ���nullptr����������־��
//    4��ע�⣺�����������������Ǵ�������⣬���Ǳ�������������Ϊ����֮ǰ���Ĵ����ɾ�������ֻ��Ҫ���� - �������������ٱ������оͿ�����*/
//int main()
//{
//	Base b;
//	Derive d;
//	VFPTR *tb = (VFPTR*)(*(int*)&b);
//	PrintVTable(tb);
//	VFPTR *td = (VFPTR*)(*(int*)&d);
//	PrintVTable(td);
	//system("pause");
	//return 0;
//}

      //��̳��е��麯����
class Base1
{
public:
	virtual void func1()  { cout << "B1:func1" << endl; }
	virtual void func2()  { cout << "B1:func2" << endl; }
private:
	int b1;
};
class Base2
{
public:
	virtual void func1()  { cout << "B2:func1" << endl; }
	virtual void func2()  { cout << "B2:func2" << endl; }
private:
	int b2;
};
class Derive :public Base1, public Base2
{
public:
	virtual void func1()  { cout << "D:func1" << endl; }
	virtual void func3()  { cout << "D:func3" << endl; }
private:
	int d;
};
typedef void(*VFPTR)();
void PrintVTable(VFPTR VTable[])
{
	cout << "����ַ" << VTable << endl;
	for (int i = 0; VTable[i] != nullptr; ++i)
	{
		printf("��%d���麯���ĵ�ַ��0x%x,->", i, VTable[i]);
		VFPTR f = VTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Derive d;
	VFPTR *t1 = (VFPTR*)(*(int*)&d);         //Derive��Base1������ַ
	PrintVTable(t1);
	VFPTR *t2 = (VFPTR*)(*(int *)((char*)&d + sizeof(Base1)));    //Derive��Base2������ַ
	PrintVTable(t2);
	system("pause");
	return 0;
}