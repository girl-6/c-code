#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
void Change(int *x, int *y)
{
	int t = 0;
	t= *x;
	*x = *y;
	*y = t;
}
int main()
{
	int a, b, c;
	printf("请输入三个数：");
	scanf("%d%d%d", &a, &b, &c);
	if (a<b) Change(&a, &b);
	if (a<c) Change(&a, &c);
	if (b<c) Change(&b, &c);
	printf("%d %d %d\n", a, b, c);
	system("pause");
	return 0;
}