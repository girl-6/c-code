#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <algorithm>//�㷨ͷ�ļ�

#include <iostream>
using namespace std;

namespace LY
{
	template <class T>
	struct __ListNode       //��װ���
	{
		__ListNode<T>* _next;
		__ListNode<T>* _prev;
		T  _data;
		__ListNode(const T& x = T())     //��ȱʡֵ�Ĺ��캯��
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};
	template<class T, class Ref, class Ptr>
	struct __ListIterator      //��װ������
	{
		typedef __ListNode<T> Node;
		typedef __ListIterator<T, Ref, Ptr> Self;
		Node * _node;

		__ListIterator()      //����
			:_node(nullptr)
		{}

		__ListIterator(Node *node)
			:_node(node)
		{}

		Ref operator* ()           //����������
		{
			return _node->_data;
		}

		Ptr operator ->()          //������ָ���Զ�������
		{
			return &_node->_data;
		}

		Self& operator++ ()         //������++��������һ��λ�õĵ�����
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
		typedef __ListIterator <T, T&, T*> iterator;       //����������
		typedef __ListIterator<T, const T&, const T*> const_iterator;      //const ������
		iterator begin()  { return iterator(_head->_next); }
		iterator end()   { return iterator(_head); }
		const_iterator cbegin()const   { return const_iterator(_head->_next); }
		const_iterator cend()const   { return const_iterator(_head); }

		List()         //���캯��
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

		void PushBack(const T& x)           //β��
		{
			Node* tail = _head->_prev;      //���һ�����
			Node* newnode = new Node(x);     //����һ���½��
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}

		void PopBack()          //βɾ
		{
			Node* tail = _head->_prev;  //���һ�����
			Node* prev = tail->_prev;     //���һ������ǰһ��
			if (tail != _head)
			{
				prev->_next = _head;
				_head->_prev = prev;
				delete tail;
			}
		}
		void PushFront(const T&x)         //ͷ��
		{
			Node* head = _head->_next;          //��һ���ڵ�
			Node* newnode = new Node(x);
			newnode->_next = head;
			head->_prev = newnode;
			_head->_next = newnode;
			newnode->_prev = _head;
		}
		void PopFront()              //ͷɾ
		{
			Node* head = _head->_next;       //��һ���ڵ�
			Node* next = head->_next;       //��һ���ڵ����һ��
			if (head != _head)
			{
				_head->_next = next;
				next->_prev = _head;
				delete head;
			}
		}
		void Insert(iterator pos, const T&x)            //�����λ��posǰ����һ��x
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}
		void Erase(iterator pos)                         //ɾ��
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
		void Print()              //��ӡ
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

	void TestList1()//���Թ��캯����PushBack,PopBack,��������ʹ��
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
	void TestList2()  //����PushFront,PopFront,Insert��Erase��
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
		//����ʹ���㷨�е�find��find�Խ��յĵ�������һ��Ҫ��
		auto pos1 = l.begin();
		l.Insert(pos1, 30);//����Insert
		auto pos = l.begin();     //����posλ��
		l.Erase(pos);
		l.Print();

	}
}