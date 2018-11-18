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
	printf("1-100之间共有9是：%d个\n", count);
	system("pause");
	return 0;
}