#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int year;
	printf("������1000-2000���������ݣ� ");
	scanf("%d", &year);
	if (year >= 1000 && year <= 2000)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			printf("  ����Ϊ����\n");
		else
			printf("  ����Ϊƽ��\n");
	}
	else
		printf("������������ݣ�\n");
	return 0;
}