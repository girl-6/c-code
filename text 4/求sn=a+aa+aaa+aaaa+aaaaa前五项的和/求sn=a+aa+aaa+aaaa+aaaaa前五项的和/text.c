#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int sum = 0;
	int tmp = 0;
	printf("输入一个数：");
	scanf("%d", &a);
	for (int i = 0; i<5; i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	printf("%d", sum);
	system("pause");
	return 0;
}