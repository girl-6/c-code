#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Date
{
public:
	void Display()
	{
		cout << "Display()" << endl;
		cout << "year:" << _year << endl;
	}
	void Display()const
	{
		cout << "Display()const" << endl;
		cout << "year:" << _year << endl;
	}
private:
	int _year;
};
void Test()
{
	Date d1;
	d1.Display();
	const Date d2;
	d2.Display();
}


int main()
{
	Test();
	system("pause");
	return 0;
}