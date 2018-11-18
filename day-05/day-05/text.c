#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//1.完成猜数字游戏。
//
//void menu()
//{
//	
//	printf("******************************\n");
//	printf("********** 1.game ************\n");
//	printf("********** 0.exit ************\n");
//	printf("******************************\n");
//}
//void game()
//{
//	int rand_num = rand() % 100 + 1;
//	int input = 0;
//	while (1)
//	{
//		printf("\n请输入你猜的数字：>");
//		scanf("%d", &input);
//		if (input < rand_num)
//		{
//			printf("\n猜小了！");
//		}
//		else if (input>rand_num)
//		{
//			printf("\n猜大了！");
//		}
//		else
//		{
//			printf("\n恭喜你，猜对了！");
//			break;
//		}
//	}
//	printf("\n");
//}
//#include <time.h>
//int main()
//{
//	int input = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("\n请重新输入！\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}

//2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回 - 1.（折半查找）

//#define N 10
//int bin_search(int arr[], int key, int sz)
//{
//
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		if (key > arr[(left + right) / 2])
//		{
//			left = (left + right) / 2 + 1;
//		}
//		else if (key < arr[left + (right - left) / 2])
//		{
//			right = left + (right - left) / 2 - 1;
//		}
//		else
//		{
//			return (left + (right - left) / 2 + 1);
//		}
//		//int mid = left + (right - left) / 2;
//		/*if (key > arr[mid])
//		{
//		left = mid + 1;
//		}
//		else if (key < arr[mid])
//		{
//		right = mid - 1;
//		}
//		else
//		return mid;*/
//	}
//	return  -1;
//}
//
//int main()
//{
//	int i = 0;
//	int k = 0;
//	int sz = 0;
//	int a[N] = { 0 };
//	printf("请输入%d个数：", N);
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	sz = sizeof (a) / sizeof (a[0]);
//	printf("\n请输入想查找的数：");
//	scanf("%d", &k);
//	int ret = bin_search(a, k, sz);
//	if (ret >= 0)
//	{
//		printf("\n你想要的数在第%d位！\n", ret);
//	}
//	else
//		printf("\n数组中无此数！\n");
//	system("pause");
//	return 0;
//}
//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
//
//#include<string.h>
//#define PW "zaq"
//#define N 10
//int main()
//{
//	//char password []=  "zaq" ;
//	char password[] = PW;
//	char a[N] = {0};
//	int i = 0;	
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入三位数密码;>");
//		scanf("%s", &a);
//		if(strcmp(password,a)==0)
//		{
//			printf("\n登陆成功！\n");
//			break;
//		}
//		else
//		{
//			printf("\n密码错误，请重新输入！\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("退出！\n");
//	}
//	system("pause");
//	return 0;
//}
//4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
//int main()
//{
//	int ch=0;
//	printf("请输入内容;");
//	while ((ch = getchar()) != 0)
//	{
//		if (ch<='z'&&ch>='a')
//		{
//			printf("%c", ch - 32);
//		}
//		if (ch<='Z'&&ch>='A')
//		{
//			printf("%c", ch + 32);
//		}
//		if (ch<='9'&&ch>='0')
//			printf(" ");
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//5.实现一个函数，判断一个数是不是素数。
#include <math.h>
int Is_prime(int a)
{
	int i = 0;
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
		{
			return 0;//不是素数
		}
	}
	return 1;//是素数
}
int main()
{
	int n = 0;
	int ret = 0;
	printf("输入你要判断的数：");
	scanf("%d", &n);
	ret = Is_prime(n);
	if (ret == 1)
	{
		printf("%d是素数！\n", n);
	}
	else
	{
		printf("%d不是素数！\n", n);
	}
	system("pause");
	return 0;
}