#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include<iostream>
using std::cout;
using std::endl;

//   //����ģ���ػ�
//   //��������޷�ʵ���ַ����ıȽ�
template<class T>
bool IsEqual( T& left, T& right)
{
	return left == right;
}
//template<>
//bool IsEqual<char*>( char*& left, char* & right)
//{
//	return strcmp(left, right)==0;
//}
//bool IsEqual(char* left, char* right)
//{
//	return (strcmp(left, right) == 0);
//}
//void Test1()
//{
//	char *p1 = "hello";
//	char *p2 = "hello";
//	if (IsEqual(p1, p2))
//		cout << "��ͬ" << endl;
//	else
//		cout << "����ͬ" << endl;
//}

//��ģ���ػ�
//template<class T1,class T2>
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date<T1,T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<>
//class Date<int,char>
//{
//public:
//	Date()
//	{
//		cout << "Date<int,char>" << endl;
//	}
//private:
//	int  _d1;
//	char _d2;
//};
//void Test2()
//{
//	Date<int, int> d1;
//	Date<int, char> d2;
//}

// �����ػ�����ģ������е�һ���ֲ����ػ�
template<class T1>
class Date<T1,int >
{
public:
	Date()
	{
		cout << "Date<T1,int>" << endl;
	}
private:
		int  _d1;
		char _d2;
};
// ��������һ�����ƣ����ģ�����һ����������������Ƶ��ػ��汾
//��������ƫ�ػ�Ϊָ������
template<typename T1,typename T2>
class Date<T1*, T2*>
{
public:
	Date() { cout << "Date<T1*,T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//��������ƫ�ػ�Ϊ��������
template<typename T1, typename T2>
class Date<T1&, T2&>
{
public:
	Date(const T1&d1, const T2&d2)
		:_d1(d1)
		, _d2(d2)
	{
		cout << "Date<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};
int main()
{
	Date<double,int >d1;
	system("pause");
	return 0;
}