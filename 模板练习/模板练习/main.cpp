#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

// 函数模板
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

//    //隐式推演
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

//通用处理加法的函数
template<class T>
T Add(const T&left,const T&right)
{
	return left + right;
}
// 只处理int类型的加法
int Add(const int &left, const int &right)
{
	return left + right;
}

void Test2()
{
	Add(1, 2);           //与非模板函数完全匹配，调用非模板函数
	Add(1, 1.2);         //函数模板能生成更加匹配的版本，调用函数模板
}

//void  Test1()
//{
//	Add(1, 2);      //与非模板函数匹配，编译器无需特化
//	Add<int>(1, 2);     //调用编译器特化的Add版本
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
////类模板
//template<class T>
//class Vector
//{
//public:
//	Vector()
//		: _pData(nullptr)
//		, _size(10)
//		, _capacity(10)
//	{}
//	~Vector();      //用于演示 在类中声明，在类外定义
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//// 注意：类模板中的函数放在类外定义时，需要加模板参数列表
//template<class T>
//Vector<T> ::~Vector()
//{
//	if (_pData)  { delete[] _pData; }
//}
