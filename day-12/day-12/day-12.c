
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：2550136832
//
//
#include <math.h>
unsigned int reverse_bit(int n)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < 32; i++)
	{
		sum += pow(2, 31 - i)*((n >> i) & 1);
	}
	return sum;
}

int main()
{
	int  a= 0;
	printf("请输入你要逆转的数：");
	scanf("%d", &a);
	unsigned int ret = reverse_bit(a);
	printf("%u\n", ret);
	system("pause");
	return 0;
}
//2.不使用（a + b） / 2这种方式，求两个数的平均值。
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入你要求的数;");
//	scanf("%d%d", &a,& b);
//	int ret = ((a + b) >> 1);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//
//#define N 9  //数据中只有一个数字出现了一次，其他所有数字都是成对出现的
//int main()
//{
//	int i = 0;
//	int a[N] = { 0 };
//	int ret = 0;
//	printf("请输入%d个数据：",N);
//	for (i = 0; i < N; i++)
//	{
//       scanf("%d", &a[i]);
//	}
//	for (i = 0; i < N; i++)
//	{
//		ret ^= a[i];
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//4.有一个字符数组的内容为:"student a am i",
//			请你将数组的内容改为"i am a student".
//			要求：
//			不能使用库函数。
//			只能开辟有限个空间（空间个数和字符串的长度无关）。

//先对字符串整体逆转一次，再将每一个子串逆转
//求字符串长度，为了找到整个字符串的尾点
//int strlen(char*str)
//{
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}
////实现字符串的逆转
//void reverse(char*star, char*end)
//{
//	char temp = 0;
//	while (star < end)
//	{
//		temp = *star;
//		*star = *end;
//		*end = temp;
//		star++;
//		end--;
//	}
//}
//
//void reverse_str(char*str)
//{
//	char *cur = str;
//	char*left = str;
//	char* right = str + strlen(str)-1;
//	//逆转整个字符串
//	reverse(left, right);
//	while (*cur)
//	{
//		//寻找子串的起点和尾点
//		char*star = cur;
//		while ((*cur != ' ') && (*cur != '\0'))
//		{
//			cur++;
//		}		
//		//逆转每一个子串
//		reverse(star, cur - 1);
//		//找到下一个子串的起点
//		if (*cur == ' ')
//		{
//			cur++;
//		}
//	}	
//}
//	
//int main()
//{
//	char a[] = { "student a am i" };
//	reverse_str(a);
//	printf("%s\n", a);
//	system("pause");
//	return 0;
//}