#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

// ����ģ��
//void Swap(int &left, int &right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double &left,double &right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char &left,char &right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

//    //��ʽ����
//template <typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a1 = 2, a2 = 3;
//	Swap(a1,a2);
//
//	double d1 = 2.0, d2 = 3.0;
//	Swap(d1, d2);
//
//	char c1 = '2', c2 = '3';
//	Swap(c1, c2);
//
//	system("pause");
//	return 0;
//}

//ͨ�ô���ӷ��ĺ���
template<class T>
T Add(const T&left,const T&right)
{
	return left + right;
}
// ֻ����int���͵ļӷ�
int Add(const int &left, const int &right)
{
	return left + right;
}

void Test2()
{
	Add(1, 2);           //���ģ�庯����ȫƥ�䣬���÷�ģ�庯��
	Add(1, 1.2);         //����ģ�������ɸ���ƥ��İ汾�����ú���ģ��
}

//void  Test1()
//{
//	Add(1, 2);      //���ģ�庯��ƥ�䣬�����������ػ�
//	Add<int>(1, 2);     //���ñ������ػ���Add�汾
//}
int main()
{
	Test2();
	//int a1 = 10, a2 = 20;
	//double b1 = 10.1, b2 = 20.3;
	//Add(a1, a2);
	//Add(b1, b2);
	//  //Add(a1, (int)b2);
	//Add<int>(a1, b2);
	system("pause");
	return 0;
}

//
////��ģ��
//template<class T>
//class Vector
//{
//public:
//	Vector()
//		: _pData(nullptr)
//		, _size(10)
//		, _capacity(10)
//	{}
//	~Vector();      //������ʾ �����������������ⶨ��
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//// ע�⣺��ģ���еĺ����������ⶨ��ʱ����Ҫ��ģ������б�
//template<class T>
//Vector<T> ::~Vector()
//{
//	if (_pData)  { delete[] _pData; }
//}
