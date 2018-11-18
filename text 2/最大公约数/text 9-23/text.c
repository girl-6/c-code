#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
int main()
{
	int a, b;
	int c = 0;
	printf("请输入两个数：");
	scanf("%d%d", &a, &b);
	while (c = a%b)
	{
		a = b;
		b = c;
	}
	printf("\n最大公约数是：%d\n", b);
	return 0;
}