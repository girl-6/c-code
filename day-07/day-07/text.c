#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
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
//	printf("����Ҫ��ӡ��������");
//	scanf("%d", &n);
//	Print(n);
//	system("pause");
//	return 0;
//}

//2.ʹ�ú���ʵ���������Ľ�����
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
//	printf("��������������");
//	scanf("%d%d", &a, &b);
//	swap(&a, &b);
//	printf("���������Ϊ��%d  %d\n", a, b);
//	system("pause");
//	return 0;
//}
//3.ʵ��һ�������ж�year�ǲ������ꡣ
//
//void leap_year(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		printf("%d�����ꡣ\n", year);
//	}
//	else
//	{
//		printf("%d�������ꡣ\n", year);
//	}
//}
//int main()
//{
//	int y = 0;
//	printf("������Ҫ�����ݣ�");
//	scanf("%d", &y);
//	leap_year(y);
//	system("pause");
//	return 0;
//}
//4.����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
//
//void init(int *a,int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	printf("��ʼ���������Ϊ��");
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
//	printf("��պ������Ϊ��");
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
//	printf("���ú������Ϊ��");
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
//	printf("����Ҫ����Ĵ�С�ǣ�");
//	scanf("%d",&n);
//	arr = (int*)malloc(n);
//	printf("��ʼ�����飺");
//	init(arr,n);
//	reverse(arr, n);
//	empty(arr,n);
//	system("pause");
//	return 0;
//}

//5.ʵ��һ���������ж�һ�����ǲ���������
//# include<math.h>
//int is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i < sqrt(n); i++)
//	{
//		if (n%i == 0)
//		{
//			return 0;//������������0
//		}
//	}
//	return 1;//����������1
//}
//int main()
//{
//	int a;
//	int ret = 0;
//	printf("������Ҫ�жϵ�����");
//	scanf("%d", &a);
//    int ret=is_prime(a);
//	if (ret == 1)
//	{
//		printf("%d��������\n",a);
//	}
//	else
//	{
//		printf("%d����������\n",a);
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
			printf("%d����������\n", n);
		}
	}
	printf("%d��������\n", n);
}
int main()
{
	int a;
	printf("������Ҫ�жϵ�����");
	scanf("%d", &a);
	is_prime(a);
	system("pause");
	return 0;
}