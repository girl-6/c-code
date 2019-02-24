#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int FirstMeet(string  s)
{
	int countchar[256] = { 0 };
	for (int i = 0; i < s.size(); i++)
	{
		countchar[s[i]]++;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (countchar[s[i]] == 1)
			return i;
	}
	return -1;
}

int main()
{
	string z ;
	while (cin >> z)
	{
		int a = FirstMeet(z);
		if (a >= 0)
			cout << z[a] << endl;
		else
			cout << a << endl;
	}
	system("pause");
	return 0;
}