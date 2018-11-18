#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//
//void Print(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf(" %2d*%2d=%4d", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n;
//	printf("输入要打印的行数：");
//	scanf("%d", &n);
//	Print(n);
//	system("pause");
//	return 0;
//}

//2.使用函数实现两个数的交换。
//
//void swap(int *a, int *b)
//{
//	int temp = 0;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入两个数：");
//	scanf("%d%d", &a, &b);
//	swap(&a, &b);
//	printf("交换后的数为：%d  %d\n", a, b);
//	system("pause");
//	return 0;
//}
//3.实现一个函数判断year是不是润年。
//
//void leap_year(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		printf("%d是闰年。\n", year);
//	}
//	else
//	{
//		printf("%d不是闰年。\n", year);
//	}
//}
//int main()
//{
//	int y = 0;
//	printf("输入你要查的年份：");
//	scanf("%d", &y);
//	leap_year(y);
//	system("pause");
//	return 0;
//}
//4.创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//
//void init(int *a,int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	printf("初始化后的数组为：");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d", a[i]);
//	}
//	printf("\n");
//}
//void empty(int *a, int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		a[i] = 0;
//	}
//	printf("清空后的数组为：");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d", a[i]);
//	}
//	printf("\n");
//}
//void reverse(int *a, int len)
//{
//	int i = 0;
//	int temp = 0;
//	for (i = 0; i < len / 2; i++)
//	{
//		temp = a[i];
//		a[i] = a[len-i-1];
//		a[len-i-1] = temp;
//	}
//	printf("逆置后的数组为：");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d", a[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int *arr;
//	int n = 0;
//	printf("你想要数组的大小是：");
//	scanf("%d",&n);
//	arr = (int*)malloc(n);
//	printf("初始化数组：");
//	init(arr,n);
//	reverse(arr, n);
//	empty(arr,n);
//	system("pause");
//	return 0;
//}

//5.实现一个函数，判断一个数是不是素数。
//# include<math.h>
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i < sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;//不是素数返回0
//		}
//	}
//	return 1;//是素数返回1
//}
//int main()
//{
//	int a;
//	int ret = 0;
//	printf("请输入要判断的数：");
//	scanf("%d", &a);
//    int ret=is_prime(a);
//	if (ret == 1)
//	{
//		printf("%d是素数！\n",a);
//	}
//	else
//	{
//		printf("%d不是素数！\n",a);
//	}
//	system("pause");
//	return 0;
//}

# include<math.h>
void is_prime(int n)
{
	int i = 0;
	for (i = 2; i < sqrt(n); i++)
	{
		if (n%i == 0)
		{
			printf("%d不是素数！\n", n);
		}
	}
	printf("%d是素数！\n", n);
}
int main()
{
	int a;
	printf("请输入要判断的数：");
	scanf("%d", &a);
	is_prime(a);
	system("pause");
	return 0;
}