#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdlib.h>

# pragma once
#include <stdio.h>
//#include <iostream>
//using namespace std;
//#include <deque>
//#include <vector>
//         //ջ����������
//template<class T,class Container=vector<T>>
//     //ͬ��������template<class T,class Container=deque<T>>
//    //ͬ��������template<class T,class Container=list<T>>
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
//	Stack <int>s;     //ģ���������ȱʡֵ������ֱ�Ӷ���
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

//       //queue��ģ��ʵ��
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


//         //������������ʹ��
#include <iostream>
#include <vector>
// ʹ���������������������Ӧ��ͷ�ļ�
#include <stack>

using namespace std;

int main()
{
	vector<int> v;

	/*
	* ��0-9����vector��������ӡ
	*/
	for (int i = 0; i<10; i++)
		v.push_back(i);
	cout << "���Vector������" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
	cout << endl << endl;

	// ������v��������������
	stack< int, vector<int> > s(v);
	/*
	* ʹ��ջ����������stack�ṩ�ĺ�����������
	*/
	cout << "�Զ��������ջ( stack���������� )��" << endl;
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}
