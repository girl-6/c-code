#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int year;
	printf("请输入1000-2000间的任意年份： ");
	scanf("%d", &year);
	if (year >= 1000 && year <= 2000)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			printf("  此年为闰年\n");
		else
			printf("  此年为平年\n");
	}
	else
		printf("请重新输入年份！\n");
	return 0;
}