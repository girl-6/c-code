#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (9 == i % 10)
		{
			count++;
		}
		if (9 == i / 10)
		{
			count++;
		}
	}
	printf("1-100֮�乲��9�ǣ�%d��\n", count);
	system("pause");
	return 0;
}