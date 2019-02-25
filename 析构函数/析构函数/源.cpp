#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//typedef int DataType;
//class Seqlist
//{
//public:
//	Seqlist(int capacity = 10)
//	{
//		_pData = (DataType*)malloc(capacity* sizeof(DataType));
//		assert(_pData);
//		_size = 0;
//		_capacity = capacity;
//	}
//	~Seqlist()         //析构函数
//	{
//		if (_pData)
//		{
//			free(_pData);
//			_pData = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int *_pData;
//	size_t _size;
//	size_t _capacity;
//};

class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

class Person
{
private:
	//自定义类型
	String _name;
	//内置类型
	int _age;
};


int main()
{
	Person p;
	system("pause");
	return 0;
}


