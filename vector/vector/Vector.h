#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;

namespace LY
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//Vector()          //无参构造函数
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _endOfStorage(nullptr)
		//{}
		Vector() = default;

		//Vector <int>copy=v1 或 copy(v1)
		Vector(const Vector<T>& v)       //拷贝构造函数
		{
			_start = new T[v.Capacity()];
			//memcpy(_start, v._start, sizeof(T)*v.Size());   这里是浅拷贝
			for (size_t i = 0; i < Size(); ++i)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}

		//v3 = v2;
		Vector <T>& operator =(Vector <T> v)        //赋值重载  
		{
			Swap(v);
			return *this;
		}
		void Swap(Vector <T> &v)
		{
			std::swap(_start, v._start);
			std::swp(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		~Vector()    //析构函数
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
		}

		iterator begin() { return _start; }
		iterator end()  { return _finish; }
		const_iterator cbegin()const { return _start; }
		const_iterator cend()const  { return _finish; }
		size_t Size()   { return _finish - _start; }
		size_t Capacity(){ return _endOfStorage - _start; }

		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}

		void Resize(size_t n, const T& value = T())
		{
			if (n <= Size())
			{
				_finish = _start + Size();
			}
			else
			{
				if (n > Capacity())
				{
					Reserve(n);
				}
				while (_finish != _start + n)
				{
					*_finish = value;
					++_finish;
				}
			}
		}

		void PushBack(const T&x)
		{
			Insert(end(),x);
		}
		void Insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			size_t posindex = pos - _start;
			if (_finish == _endOfStorage)
			{
				size_t newCapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				Reserve(newCapacity);
				pos = _start + posindex;
			}
			iterator end = _finish;
			while (end>pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = x;
			++_finish;
		}

		void PopBack()
		{
			//--_finish;
			Erase(--end());
		}
		iterator Erase(iterator pos)
		{
			assert(pos < end());
			iterator next = pos;
			while (pos < _finish - 1)
			{
				*pos = *(pos + 1);
				++pos;
			}
			--_finish;
			return next;
		}

		T& operator[](size_t pos)
		{
			assert(pos < Size());
			return _start[pos];
		}

		/*const T&operator[](size_t pos)const
		{
		assert(pos < Size());
		return _start[pos];
		}*/

		size_t Size()const { return _finish - _start; }
		size_t Capacity() const { return _endOfStorage - _start; }


	private:
		iterator _start = nullptr;           //指向数据块的开始
		iterator _finish = nullptr;        //指向有效数据的结尾
		iterator _endOfStorage = nullptr;  //指向储存容量的尾
	};
	void Test1()   
	{
		Vector<int> v1;
		v1.PushBack(1);
		v1.PushBack(2);
		v1.PushBack(3);
		v1.PushBack(4);
		/*for (size_t i = 0; i < v1.Size(); i++)
		{
			cout << v1[i] << "  ";
		}
		cout << endl;*/

		v1.Resize(3);
		Vector<int>::iterator it1 = v1.begin();
		while (it1 != v1.end())
		{
			cout << *it1 << " ";
			++it1;
		}
		cout << endl;

		v1.Resize(10, 5);
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	oid TestVector2()
	{
		Vector<int> v1;
		v1.PushBack(1);
		v1.PushBack(2);
		v1.PushBack(3);
		v1.PushBack(4);
		v1.PushBack(5);

		auto pos = std::find(v1.begin(), v1.end(), 3);
		if (pos != v1.end())
		{
			v1.Insert(pos, 30);
		}
		pos = std::find(v1.begin(), v1.end(), 3);
		v1.Erase(pos);

		for (size_t i = 0; i < v1.Size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
	}

	void TestVector3()
	{
		Vector<int> v1;
		v1.PushBack(1);
		v1.PushBack(2);
		v1.PushBack(3);
		v1.PushBack(4);
		v1.PushBack(5);

		Vector<int> copy = v1; // copy(v1)
		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;

		Vector<int> v2;
		v2.PushBack(10);
		v2.PushBack(20);

		copy = v2;
		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void TestVector4()
	{
		Vector<std::string> v;
		v.PushBack("111");
		v.PushBack("222");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		v.PushBack("333");
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

}