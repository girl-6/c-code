#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A[10] = { 0 };
	int B[10] = { 3, 4, 5, 6, 7, 2, 1, 11, 9, 8 };
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		int tmp = 0;
		tmp = A[i];
		A[i] = B[i];
		B[i] = tmp;
	}
	printf("交换后的数组A为：");
	for (i = 0; i < 10; i++)
	{
		printf("%d  ", A[i]);
	}
	printf("\n交换后的数组B为：");
	for (i = 0; i < 10; i++)
	{
		printf("%d  ", B[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

//void Change(int *a, int *b)
//{
//	int t;
//	t = *a;
//	*a = *b;
//	*b = t;
//}
//int main()
//{
//	int A[10];
//	int B[10];
//	int i, j, k;
//	printf("请输入A的十个数：");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	printf("\n请输入B的十个数：");
//	for (j = 0; j < 10; j++)
//	{
//		scanf("%d", &B[j]);
//	}
//	for (k = 0; k < 10; k++)
//	{
//		Change(&A[k], &B[k]);
//	}
//	printf("\n输出交换后的A数组:");
//	for (i = 0; i < 10; i++)
//	{
//        printf("%d  ",A[i]);
//	}		
//	printf("\n输出交换后的B数组:");
//	for (j = 0; j < 10; j++)
//	{
//		printf("%d  ",B[j]);
//	}
//	printf("\n");
//	return 0;
//}