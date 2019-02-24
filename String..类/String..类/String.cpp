#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<assert.h>
#include <string>
#include<iostream>
using namespace std;


namespace myString
{
	class String
	{
	public:
		typedef char* Iterator;  //迭代器
		Iterator begin()
		{
			return _str;
		}
		Iterator  end()
		{
			return _str + _size;
		}
		String(const char* str = "")    //构造
		{
			if (nullptr == str)
			{
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		String(const String& s)           //拷贝构造
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			this->Swap(tmp);
		}

		void Swap(String& s)      //交换对象
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		String& operator=(String s)   //赋值重载
		{
			this->Swap(s);
			return *this;
		}

		~String()        //析构函数
		{
			if (_str)
			{
				delete[]_str;
				_size = 0;
				_capacity = 0;
			}
		}
		
		char* c_str()    // 用C语言格式输出字符串
		{
			return _str;
		}

		bool operator<(const String& s)
		{
			return strcmp(_str, s._str) < 0;
		}
		bool operator>(const String& s)
		{
			return strcmp(_str, s._str) > 0;
		}
		bool operator<=(const String& s)
		{
			return ((*this < s) || (*this == s));
			// return !(*this>s);
		}
		bool operator>=(const String& s)
		{
			return !(*this < s);
		}
		bool operator==(const String& s)
		{
			return strcmp(_str, s._str) == 0;

		}
		bool operator!=(const String& s)
		{
			return !(*this == s);
		}

		void Reserve(size_t n)       //判断容量，并实现扩容
		{
			if (_capacity < n)
			{
				cout << "扩容" << endl;
				char* str = new char[n+1];
				strcpy(str, _str);
				delete[] _str;
				_str = str;
				_capacity = n;
			}
			return;
		}

		void PushBack(char ch)    //追加一个字符
		{
			Reserve(_size *2);
			_str[_size++] = ch;
			_str[_size] = '\0';

		}

		 //"hello"  "xxxxxxxxxxxxxxxxxxxxxxxxxx"
		void Append(const char* str)     //追加一个字符串
		{
			Reserve(_size + strlen(str)+1);
			strcpy(_str + _size, str);
			_size += strlen(str);
			/*for (size_t i = 0; i < strlen(str); i++)
			{
				PushBack(str[i]);
			}*/
		}

		String& operator+=(char ch)
		{
			PushBack(ch);
			return *this;
		}
		String& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}
		
		void Insert(size_t pos, char ch)   //插入一个字符
		{
			assert(pos <= _size);
				Reserve(_size + 1);
			size_t end = _size ;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;
		}
		void Insert(size_t pos, const char* str)   //插入一个字符串
		{
			assert(pos <= _size);
			Reserve(_size + strlen(str) + 1);
			for (size_t i = 0; i < strlen(str) - 1; i++)
			{
				Insert(pos, str[i]);
			}
		}

		void Erase(size_t pos, size_t len)     //删除len长度的字符串
		{
			assert(pos <= _size);
			size_t start = pos + len;
			size_t end = _size;
			while (start<=end)
			{
				_str[pos++] = _str[start++];
			}
			_size -= len;
		}

		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		size_t Find(char ch, size_t pos = 0)       //从pos开始，找一个字符
		{
			size_t i = 0;
			while (_str[i])
			{
				if (_str[i] == ch)
					return i;
				i++;
			}
			return npos;
		}

		size_t Find(const char* str, size_t pos = 0)   //从pos开始，找一个字符串
		{
			size_t begin = 0;
			size_t len = strlen(str);
			size_t end = _size - 1 - len;
			size_t flg = 0;
			if (_size < len)
				return npos;
			while (begin <= end)
			{
				size_t i = 0;
				size_t f = Find(str[0], begin);
				pos = f;
					while (i < len)
					{
						if (_str[pos] == str[i])
						{
							pos++;
							i++;
						}
						else
						{
							flg++;
							break;
						}
					}
				if (flg==0)  return f;
				begin+=f;
			}
			return npos;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static size_t npos;
	};
	size_t String::npos = -1;
	void Test1()     //默认函数的测试
	{
		String s1;
		String s2("hello");
		String s3(s2);
		cout << "s1=" << s1.c_str() << endl;
		s1 = s3;
		cout << "s1=" << s1.c_str() << endl;
		cout << "s2=" << s2.c_str() << endl;
		cout << "s3=" << s3.c_str() << endl;
	}
	void Test2()    //比较函数的测试
	{
		String s1("hello");
		//String s2(s1);
		String s2("world");
		cout << (s1 < s2) << endl;
		cout << (s1 > s2) << endl;
		cout << (s1 <= s2) << endl;
		cout << (s1 >= s2) << endl;
		cout << (s1 == s2) << endl;
		cout << (s1 != s2) << endl;
	}
	void Test3()     //运算符重载测试
	{
		String s1("hello ");
		s1.PushBack('c');
		cout << s1.c_str() << endl;
		s1.Append(" world xxxxxxxxxx");
		cout << s1.c_str() << endl;
		s1+='a';
		cout << s1.c_str() << endl;
		s1 += "  bxxxxxxxxxxxx";
		cout << s1.c_str() << endl;
		

	}
	void Test4()       //功能实现测试
	{
		String s1("hello");
		s1.Insert(2, 'y');
		cout << s1.c_str() << endl;
		s1.Insert(2, "asdf");
		cout << s1.c_str() << endl;
		s1.Erase(2, 4);
		cout << s1.c_str() << endl;
		cout << s1.Find('e') << endl;
		String s2("hello student");
		cout << s2.Find("stu") << endl;
	}
}
int main()
{
	//myString::Test1();
	//myString::Test2();
	myString::Test3();
	myString::Test4();



	system("pause");
	return 0;
}