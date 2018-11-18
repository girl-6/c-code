#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include <stdlib.h>
int Max(int x, int y)
{
	int z;
	if (x>y)	 z = x;
	else     z = y;
	return z;
}
int main()
{
	int a[10];
	printf("请输入10个数：");
	for (int i = 0; i<10; i++)
	{
		scanf("%d", &a[i]);
	}
	int max = a[0];
	for (int i = 0; i<10; i++)
	{
		//	if(a[i]>max)  max=a[i];
		max = Max(a[i], max);
	}
	printf("\n最大值为：%d\n", max);
	system（"pause"):
	return 0;
}