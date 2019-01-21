#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;



class Date
{
public:

	int GetMonthDay(int year, int month)
	{
		static int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else return monthArray[month];
	}

	Date(int year = 2019, int month = 1, int day = 1)
	{
		if (year > 0 &&
			month > 0 && month<13 &&
			day>0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "日期非法！ " << endl;
	}

	//拷贝构造
	//Date copy(d2)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	//重载赋值+  复制
	Date operator=(const Date&d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//重载==
	bool operator==(const Date&d)
	{
		return _year == d._year&&
		_month == d._month&&
		_day == d._day;
	}

	//重载！=
	bool operator!=(const Date& d)
	{
		/*return _year != d._year ||
			_month != d._month ||
			_day != d._day;*/
		return !(*this == d);
	}

	//重载>
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
			}
			return false;
		}
	    else return false;
	}

	//重载>=
	bool operator>=(const Date& d)
	{
		/*if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day >= d._day)
					return true;
			}
			return false;
		}
		else return false;*/
		return (*this > d) || (*this == d);
	}

	//重载<
	bool operator<(const Date& d)
	{
		/*if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day < d._day)
					return true;
			}
		}
		 return false;*/
		//return !(*this == d) && !(*this > d);
		return !((*this == d) || (*this > d));
	}

	//重载<=
	bool operator<=(const Date& d)
	{
		/*if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day <= d._day)
					return true;
			}
		}
		return false;*/
		return !(*this > d);
	}

	//重载+
	Date const operator+(int day)
	{
		Date tmp(*this);
		tmp += day;
		return tmp;
	}

	//重载+=
	Date operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	Date operator-(int day)
	{
		Date tmp(*this);
		tmp -= day;
		return tmp;
	}


	//重载-=
	Date operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	//前置
	//加引用*this出了作用域，本身存在。后置则不用
	Date& operator++()
	{
		/**this += 1;
		return *this;*/
		if (++_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			if (++_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	Date& operator--()
	{
		if (--_day <= 0)
		{
			if (--_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day = GetMonthDay(_year, _month);
		}
		return *this;
		/**this -= 1;
		return *this;*/
	}
	//后置
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}
	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}


	//重载-
	int operator-(const Date&d)
	{
		int day = 0;
		int flag = 1;
		Date max=d;
		Date min=*this;
		if (min > max)
		{
			min = d;
			max = *this;
			flag = -1;
		}
		while (min != max)
		{
			day++;
			min++;
		}
		return  day*flag;
	}

	void Print()
	{
		cout << _year << " - " << _month << " - " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2000,2,29);
	d1.Print();

	cout <<endl<< "拷贝构造结果： ";
	Date d2(d1);
	d2.Print();

	//赋值重载
	cout << endl << "重载运算符： " << endl;
	Date d3(2019, 1, 1);
	Date d4(2019, 6, 2);
	Date d5;
	cout << "d3: ";d3.Print();
	cout << "d4: ";d4.Print();
	cout << endl << "d5=d3的结果： ";d5 = d3;d5.Print();
	cout <<"d3= =d4的结果："<< (d3 == d4) << endl;
	cout << "d3！=d4的结果：" << (d3 != d4) << endl;
	cout << "d3>d4 的结果是：" << (d3 > d4) << endl;
	cout << "d3<d4 的结果是：" << (d3 < d4) << endl;
	cout << "d3>=d4 的结果是：" << (d3 >= d4) << endl;

	cout << "d3<=d4 的结果是：" << (d3 <= d4) <<endl<<endl<< endl;
	cout << "d5=d4+70 的结果是："; d5 = d4 + 70;d5.Print();
	cout << "此时d4是："; d4.Print();
	cout << "d4+=5 的结果是："; (d4 += 5).Print();
	cout << "d5=d3-7 的结果是："; d5 = d3 - 7;d5 .Print();
	cout << "此时d3是："; d3.Print();
	cout << "d3-=10 的结果是："; (d3 -= 70).Print();

	Date d6; cout << endl<<endl<<"d6是："; d6.Print();
	//前置 d6.operator---(&d6)
	//后置 d6.operator---(&d6,0) 多一个参数
	cout << "--d6的结果是："; (--d6).Print();
	cout << "d6--的结果是："; (d6--).Print();
	Date d9; cout << endl << endl << "d9是："; d9.Print();
	//cout << "++d9的结果是："; (++d9).Print();
	cout << "d9++的结果是："; (d9++).Print();

	
	Date d7(2019, 6, 1); cout <<endl<<endl<< "d7是："; d7.Print();
	Date d8(2019, 4, 20); cout << "d8是："; d8.Print();
	cout << "d8-d7的结果是：" << (d8-d7) << endl;
	system("pause");
	return 0;
}