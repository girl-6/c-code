#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <algorithm>//算法头文件

#include <iostream>
using namespace std;

namespace LY
{
	template <class T>
	struct __ListNode       //封装结点
	{
		__ListNode<T>* _next;
		__ListNode<T>* _prev;
		T  _data;
		__ListNode(const T& x = T())     //带缺省值的构造函数
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};
	template<class T, class Ref, class Ptr>
	struct __ListIterator      //封装迭代器
	{
		typedef __ListNode<T> Node;
		typedef __ListIterator<T, Ref, Ptr> Self;
		Node * _node;

		__ListIterator()      //构造
			:_node(nullptr)
		{}

		__ListIterator(Node *node)
			:_node(node)
		{}

		Ref operator* ()           //迭代器引用
		{
			return _node->_data;
		}

		Ptr operator ->()          //迭代器指向自定义类型
		{
			return &_node->_data;
		}

		Self& operator++ ()         //迭代器++，返回下一个位置的迭代器
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator ++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		Self& operator --()
		{
			_node = _node->_prev;
			return *this;
		}

		Self& operator --(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator==(const Self& self)
		{
			return _node == self._node;
		}

		bool operator !=(const Self&self)
		{
			return _node != self._node;
		}
	};

	template <class T>
	class List
	{
		typedef __ListNode<T> Node;
	public:
		typedef __ListIterator <T, T&, T*> iterator;       //声明迭代器
		typedef __ListIterator<T, const T&, const T*> const_iterator;      //const 迭代器
		iterator begin()  { return iterator(_head->_next); }
		iterator end()   { return iterator(_head); }
		const_iterator cbegin()const   { return const_iterator(_head->_next); }
		const_iterator cend()const   { return const_iterator(_head); }

		List()         //构造函数
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//List <int> l2(l3)
		List(const List<T> &l);
		
		// l2=l3
		List <T>& operator=(const List<T> &l)
		{};
		~List()  {}

		void PushBack(const T& x)           //尾插
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);     //创建一个新结点
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		void PopBack()          //尾删
		{
			Node* tail = _head->_prev;
			Node* prev = tail->_prev;
			if (tail != _head)
			{
				prev->_next = _head;
				_head->_prev = prev;
				delete tail;
			}
		}
		void PushFront(const T&x)
		{
			Node* head = _head->_next;
			Node* newnode = new Node(x);
			newnode->_next = head;
			head->_prev = newnode;
			_head->_next = newnode;
			newnode->_prev = _head;
		}
		void PopFront()
		{
			Node* head = _head->_next;
			Node* next = head->_next;
			if (head != _head)
			{
				_head->_next = next;
				next->_prev = _head;
				delete head;
			}
		}
		void Insert(iterator pos, const T&x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		void Erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* next = cur->_next;
			Node* prev = cur->_prev;
			if (cur != _head)
			{
				next->_prev = prev;
				prev->_next = next;
				delete cur;
			}
		}
		void Print()
		{
			List<T>::iterator it = begin();
			while (it != end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}
		
	private:
		Node* _head;
	};
	struct Date
	{
	public:
		Date(int year = 0, int month = 1, int day = 1)
			:_year(year)
			, _month(month)
			, _day(day)
		{}

		int _year;
		int _month;
		int _day;
	};
	
	void TestList1()//测试构造函数，PushBack,PopBack,迭代器的使用
	{
		List<int> l;
		l.PushBack(1);
		l.PushBack(2);
		l.PushBack(3);
		l.PushBack(4);
		l.PushBack(5);

		l.PopBack();
		l.Print();
	}
	void TestList2()
	{
		List<int>l;
		l.PushFront(1);
		l.PushFront(2);
		l.PushFront(3);
		l.PushFront(4);
		l.PushFront(5);
		l.PopFront();
		l.Print();

		l.Insert(l.begin(), 8);
		l.Erase(l.begin());
		l.Print();

	}	
}