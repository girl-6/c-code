#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string >
#include<iostream>
using namespace std;


//	// 使用RAII思想设计的SmartPtr类
//template<class T> 
//class SmartPtr 
//{
//public:
//	SmartPtr(T* ptr = nullptr) 
//		: _ptr(ptr)    
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			cout << "~Smarptr" << endl;
//		}
///	}
//private:    
//	T* _ptr;
//};
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int)*n);
//	SmartPtr<int> sp(tmp);      //智能指针托管tmp资源
//	//若tmp正常释放则不再托管；若tmp未完成释放则帮助释放
//	throw "aaa";
//	free(tmp);
//}
//int main()
//{
//	try
//	{ 
//		int a[5] = { 4, 5, 2, 3, 1 };        
//		MergeSort(a, 5); 
//	}
//	catch (const exception&e)    
//	{
//		cout << e.what() << endl; 
//	}
//	system("pause");
//	return 0;
//}


  //智能指针的原理：RAII+指针行为
//template<class T> 
//class SmartPtr
//{
//public:
//
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			cout << "~Smarptr" << endl;
//		}
//	}        
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//private:
//	T* _ptr;
//};
//struct Date 
//{
//	int _year;    
//	int _month;    
//	int _day;
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//};
//
//int main()
//{
//	SmartPtr<int> sp1(new int);
//    *sp1 = 10;     //sp1.operator*() = 10;
//    cout << *sp1 << endl;
//	SmartPtr<Date> sp2(new Date);
//	 //需要注意的是这里应该是sp2.operator->()->_year = 2019;    
//	 //本来应该是sp2->->_year这里语法上为了可读性，省略了一个->   
//	sp2->_year = 2019;
//	sp2->_month = 1;
//	sp2->_day = 1;
//	sp2->Display();
//	system("pause");
//	return 0;
//}

// C++库中的智能指针都定义在memory这个头文件中
#include <memory>
class Date
{
public:
	Date() { cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }
	int _year;
	int _month;
	int _day;
};


// 1.C++98智能指针auto_ptr的模拟实现：转移管理权
//namespace LY
//{
//	template<class T>
//	class AutoPtr//模拟实现auto_ptr
//	{
//	public:
//		AutoPtr(T* Ptr=NULL)
//			:_Ptr(Ptr)
//		{}
//		~AutoPtr()
//		{
//			if (_Ptr)
//			{
//				cout << "delete:" << _Ptr << endl;
//				delete _Ptr;
//			}
//		}
//		// LY::AutoPtr<int> copy(ap);拷贝构造
//		AutoPtr(AutoPtr<T>& ap)
//			:_Ptr(ap._Ptr)
//		{
//			ap._Ptr = nullptr;
//		}
//		AutoPtr<T>& operator=(AutoPtr<T>&ap)    //赋值重载
//		{
//			if (this != &ap)   //检测是否自己给自己赋值
//			{
//				if (_Ptr)       //释放当前对象资源
//					delete _Ptr;
//				_Ptr = ap._Ptr;      //转移ap的资源到当前对象中
//				ap._Ptr = NULL;
//			}
//			return *this;
//		}
//		T& operator*() { return *_Ptr; }
//		T* operator->(){ return _Ptr; }
//	private:
//		T* _Ptr;
//	};
//}
//int main()
//{
//	LY::AutoPtr<Date> ap(new Date);
//	LY::AutoPtr<Date> copy(ap);
//	/*auto_ptr<Date> ap(new Date);
//	auto_ptr<Date> copy(ap);*/
//	//ap->_year = 2019;        //程序崩溃
//	copy->_year = 2019;      //正常运行
//	system("pause");
//	return 0;
//}


// 2.C++11 unique_ptr模拟实现：简单粗暴的防拷贝
//namespace LY
//{
//	template<class T>
//	class UniquePtr
//	{
//	public:
//		UniquePtr(T* ptr)
//			:_Ptr(ptr)
//		{}
//
//		~UniquePtr()
//		{
//			cout << "deleteU:" << _Ptr << endl;
//			delete _Ptr;
//		}
//		T& operator*()     {	return *_Ptr; }
//		T* operator->()    {	return _Ptr;  }
//
//	private:
//		//C++98防拷贝方式，只声明不实现+声明为私有
//		//必须声明为私有，这样类外也无法实现，才能防拷贝
//		//只声明编译无错误，为了防止系统生成默认的拷贝构造函数
//		/*UniquePtr(UniquePtr<T> const& );
//		UniquePtr&<T> operator=(UniquePtr<T> const&);*/
//
//		//C++11防拷贝方式：=delete
//		UniquePtr(UniquePtr<T> const&) = delete;
//		UniquePtr&<T> operator=(UniquePtr<T> const&) = delete;
//		T* _Ptr;
//	};
//}
//int main()
//{
//	//unique_ptr<Date> ap(new Date);
//	//unique_ptr<Date> copy(ap);   //编译不通过
//	LY::UniquePtr<Date> ap(new Date);
//	LY::UniquePtr<Date> copy(ap);   //编译不通过
//	//ap->_year = 2019;   //正常运行
//	system("pause");
//	return 0;
//}


// 3.C++11 shared_ptr的模拟实现：引用计数，支持拷贝，鼓励使用
//namespace LY
//{
//	template <class T>
//	class SharedPtr
//	{
//	public:
//		SharedPtr(T* ptr)
//			:_Ptr(ptr)
//			, _pcount(new int(1))
//			, _pmtx(new mutex)//处理线程安全问题，保证只有一个线程对pcount进行++
//		{}
//		~SharedPtr()
//		{
//			/*if (--(*_pcount) == 0)
//			{
//			cout << "delete:" << _ptr << endl;
//			delete _ptr;
//			delete _pcount;
//			}*/
//			Release();
//		}
//
//		//LY::SharedPtr<int> copy(sp);
//		SharedPtr(SharedPtr<int> const& sp)
//			:_Ptr(sp._Ptr)
//			, _pcount(sp._pcount)
//			, _pmtx(sp._pmtx)
//		{
//			if (_Ptr)//若是一个空指针则不用计数
//				AddRefcount();
//		}
//
//		//sp = sp1
//		SharedPtr<int>& operator=(SharedPtr<int> const& sp)
//		{//先检查sp是否是最后一个指向资源的对象，如果是先释放资源
//			if (_Ptr != sp._Ptr)//如果不是相同的对象才进行赋值
//			{
//				Release();//释放原来的空间，指向新的空间
//
//				_Ptr = sp._Ptr;
//				_pcount = sp._pcount;
//				_pmtx = sp._pmtx;
//
//				AddRefcount();
//			}
//
//			return *this;
//		}
//
//		int AddRefcount()
//		{
//			//保证是原子操作
//			_pmtx->lock();
//			++(*_pcount);
//			_pmtx->unlock();
//
//			return *_pcount;
//		}
//
//		void Release()
//		{
//			bool deleteflag = false;
//			//引用计数减一，如果减到0即是最后一个使用资源的对象，就释放资源
//			if (--(*_pcount) == 0)
//			{
//				cout << "deleteS:" << _Ptr << endl;
//				delete _Ptr;
//				delete _pcount;
//				deleteflag = true;
//			}
//			if (deleteflag == true)//如果是最后一个对象，也把锁资源释放
//				delete _pmtx;
//		}
//		T& operator*()   {	return *_Ptr;}
//		T* operator->()  {	return _Ptr; }
//		int use_count()  {	return *_pcount;}
//		T* Get() { return _Ptr; }
//	private:
//		T* _Ptr;    //指向管理资源的指针
//		int* _pcount;     // 引用计数
//		mutex* _pmtx;     //互斥锁
//	};
//}
//int main()
//{
//	LY::SharedPtr<int> sp1(new int(10));
//	LY::SharedPtr<int> sp2(sp1);
//	*sp2 = 20;
//	cout << sp1.LY::SharedPtr<int>::use_count<< endl;
//	cout << sp2.LY::SharedPtr<int>::use_count << endl;
//	system("pause");
//	return 0;
//}


		//线程安全问题
//void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
//{
//	cout << sp.Get() << endl;
//	for (size_t i = 0; i < n; ++i)
//	{
//		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
//		//SharedPtr<Date> copy(sp);
//		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但是最
//		//终看到的结果，并一定是加了2n
//		copy->_year++;
//		copy->_month++;
//		copy->_day++;
//	}
//}
//int main()
//{
//	SharedPtr<Date> p(new Date);
//	cout << p.Get() << endl;
//
//	const size_t n = 100;
//	thread t1(SharePtrFunc, p, n);
//	thread t2(SharePtrFunc, p, n);
//	t1.join();
//	t2.join();
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//	return 0;
//}


		//循环引用问题
//#include <iostream>
//#include <memory>
//using namespace std;
//
//struct ListNode
//{
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}

		//循环引用的解决方法
// 解决方案：在引用计数的场景下，把节点中的_prev和_next改成weak_ptr就可以了
// 原理就是，node1->_next = node2;和node2->_prev = node1;时weak_ptr的_next和_prev不会增加
//node1和node2的引用计数。

struct ListNode
{
	int _data;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;
	~ListNode(){ cout << "~ListNode()" << endl; }
};
int main()
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	node1->_next = node2;
	node2->_prev = node1;
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	return 0;
}
