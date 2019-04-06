#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton& GetInstance();
private:
	Singleton(){};
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
};
Singleton& Singleton::GetInstance()
{
	static Singleton instance;
	return instance;
}
int main()
{
	Singleton& s = Singleton::GetInstance();
	system("pause");
	return 0;
}