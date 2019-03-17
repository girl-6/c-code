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
			Node* tail = _head->_prev;      //最后一个结点
			Node* newnode = new Node(x);     //创建一个新结点
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		void PopBack()          //尾删
		{
			Node* tail = _head->_prev;  //最后一个结点
			Node* prev = tail->_prev;     //最后一个结点的前一个
			if (tail != _head)
			{
				prev->_next = _head;
				_head->_prev = prev;
				delete tail;
			}
		}
		void PushFront(const T&x)         //头插
		{
			Node* head = _head->_next;          //第一个节点
			Node* newnode = new Node(x);
			newnode->_next = head;
			head->_prev = newnode;
			_head->_next = newnode;
			newnode->_prev = _head;
		}
		void PopFront()              //头删
		{
			Node* head = _head->_next;       //第一个节点
			Node* next = head->_next;       //第一个节点的下一个
			if (head != _head)
			{
				_head->_next = next;
				next->_prev = _head;
				delete head;
			}
		}
		void Insert(iterator pos, const T&x)            //在随机位置pos前插入一个x
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		void Erase(iterator pos)                         //删除
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
		void Print()              //打印
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
	void TestList2()  //测试PushFront,PopFront,Insert，Erase，
	{
		List<int>l;
		l.PushFront(1);
		l.PushFront(2);
		l.PushFront(3);
		l.PushFront(4);
		l.PushFront(5);
		l.PopFront();
		l.Print();
		//List<int>::iterator pos = find(l.begin(), l.end(), 3);
		//不能使用算法中的find，find对接收的迭代器有一定要求
		auto pos1 = l.begin();
		l.Insert(pos1, 30);//调用Insert
		auto pos = l.begin();     //更新pos位置
		l.Erase(pos);
		l.Print();

	}
}