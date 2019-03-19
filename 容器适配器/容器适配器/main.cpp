#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdlib.h>

# pragma once
#include <stdio.h>
//#include <iostream>
//using namespace std;
//#include <deque>
//#include <vector>
//         //栈容器适配器
//template<class T,class Container=vector<T>>
//     //同样可以用template<class T,class Container=deque<T>>
//    //同样可以用template<class T,class Container=list<T>>
//class Stack
//{
//public:
//	Stack() {}
//void Push(const T&x)   { _c.push_back(x);}
//void Pop()             { _c.pop_back(); }
//T& Top()               { return _c.back(); }
//const T&Top() const    { const return  _c.back(); }
//size_t Size()const     { return _c.size(); }
//bool Empty()const      { return  _c.empty(); }
//private:
//	Container _c;
//};
//
//void Test1()
//{
//	//Stack<int,vector<int>> s;
//	Stack <int>s;     //模板参数给了缺省值，可以直接定义
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	s.Push(5);
//	cout <<"size: "<<s.Size() << endl;
//	cout <<"top:  "<< s.Top() << endl;
//	s.Pop();
//	s.Pop();
//	while (!s.Empty())
//	{
//		cout << s.Top() << " ";
//		s.Pop();
//	}
//	cout << endl;
//}

//       //queue的模拟实现
//template<class T,class Con=deque<T>>
//class Queue
//{
//public:
//	Queue()  {}
//	void Push(const T&x)   { _c.push_back(x); }
//	void Pop()             { _c.pop_front(); }
//	T& Back()              { return _c.back(); }
//	const T&Back() const   { const return  _c.back(); }
//	T& Front()             { return _c.front(); }
//	const T& Front()const  { const return _c.front(); }
//
//	size_t Size()const     { return _c.size(); }
//	bool Empty()const      { return  _c.empty(); }
//private:
//	Con _c;
//};
//void Test2()
//{
//	Queue<int> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	cout << "size: "<<q.Size() << endl;
//	cout << "back: " << q.Back() << endl;
//	cout << "front: " << q.Front() << endl;
//	while (!q.Empty())
//	{
//		cout << q.Front() << " ";
//		q.Pop();
//	}
//	cout << endl;
//}

//int main()
//{
//	//Test1();
//	Test2();
//	system("pause");
//	return 0;
//}


//         //容器适配器的使用
#include <iostream>
#include <vector>
// 使用容器适配器必须包含相应的头文件
#include <stack>

using namespace std;

int main()
{
	vector<int> v;

	/*
	* 将0-9存入vector容器并打印
	*/
	for (int i = 0; i<10; i++)
		v.push_back(i);
	cout << "输出Vector容器：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl << endl;

	// 给容器v配上容器适配器
	stack< int, vector<int> > s(v);
	/*
	* 使用栈容器适配器stack提供的函数处理数据
	*/
	cout << "自顶向下输出栈( stack容器适配器 )：" << endl;
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}
