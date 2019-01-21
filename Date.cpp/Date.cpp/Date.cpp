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
			cout << "���ڷǷ��� " << endl;
	}

	//��������
	//Date copy(d2)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	//���ظ�ֵ+  ����
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

	//����==
	bool operator==(const Date&d)
	{
		return _year == d._year&&
		_month == d._month&&
		_day == d._day;
	}

	//���أ�=
	bool operator!=(const Date& d)
	{
		/*return _year != d._year ||
			_month != d._month ||
			_day != d._day;*/
		return !(*this == d);
	}

	//����>
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

	//����>=
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

	//����<
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

	//����<=
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

	//����+
	Date const operator+(int day)
	{
		Date tmp(*this);
		tmp += day;
		return tmp;
	}

	//����+=
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


	//����-=
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

	//ǰ��
	//������*this���������򣬱�����ڡ���������
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
	//����
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


	//����-
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

	cout <<endl<< "������������ ";
	Date d2(d1);
	d2.Print();

	//��ֵ����
	cout << endl << "����������� " << endl;
	Date d3(2019, 1, 1);
	Date d4(2019, 6, 2);
	Date d5;
	cout << "d3: ";d3.Print();
	cout << "d4: ";d4.Print();
	cout << endl << "d5=d3�Ľ���� ";d5 = d3;d5.Print();
	cout <<"d3= =d4�Ľ����"<< (d3 == d4) << endl;
	cout << "d3��=d4�Ľ����" << (d3 != d4) << endl;
	cout << "d3>d4 �Ľ���ǣ�" << (d3 > d4) << endl;
	cout << "d3<d4 �Ľ���ǣ�" << (d3 < d4) << endl;
	cout << "d3>=d4 �Ľ���ǣ�" << (d3 >= d4) << endl;

	cout << "d3<=d4 �Ľ���ǣ�" << (d3 <= d4) <<endl<<endl<< endl;
	cout << "d5=d4+70 �Ľ���ǣ�"; d5 = d4 + 70;d5.Print();
	cout << "��ʱd4�ǣ�"; d4.Print();
	cout << "d4+=5 �Ľ���ǣ�"; (d4 += 5).Print();
	cout << "d5=d3-7 �Ľ���ǣ�"; d5 = d3 - 7;d5 .Print();
	cout << "��ʱd3�ǣ�"; d3.Print();
	cout << "d3-=10 �Ľ���ǣ�"; (d3 -= 70).Print();

	Date d6; cout << endl<<endl<<"d6�ǣ�"; d6.Print();
	//ǰ�� d6.operator---(&d6)
	//���� d6.operator---(&d6,0) ��һ������
	cout << "--d6�Ľ���ǣ�"; (--d6).Print();
	cout << "d6--�Ľ���ǣ�"; (d6--).Print();
	Date d9; cout << endl << endl << "d9�ǣ�"; d9.Print();
	//cout << "++d9�Ľ���ǣ�"; (++d9).Print();
	cout << "d9++�Ľ���ǣ�"; (d9++).Print();

	
	Date d7(2019, 6, 1); cout <<endl<<endl<< "d7�ǣ�"; d7.Print();
	Date d8(2019, 4, 20); cout << "d8�ǣ�"; d8.Print();
	cout << "d8-d7�Ľ���ǣ�" << (d8-d7) << endl;
	system("pause");
	return 0;
}