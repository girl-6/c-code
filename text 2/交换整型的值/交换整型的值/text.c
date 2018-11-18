#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, b, c;
	printf("请输入两个数：");
	scanf("%d%d", &a, &b);
	//可以有三种方法 1.利用第三个整型变量2.用两个变量加减 3.用二进制位的异或
	//c=a;
	//a=b;
	//b=c;

	a = a - b;
	b = a + b;
	a = b - a;

	//	a=a^b;
	//	b=a^b;
	//	a=a^b;
	printf("交换后的数为：%d %d\n", a, b);
	return 0;
}
