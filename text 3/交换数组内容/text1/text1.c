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
	printf("�����������AΪ��");
	for (i = 0; i < 10; i++)
	{
		printf("%d  ", A[i]);
	}
	printf("\n�����������BΪ��");
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
//	printf("������A��ʮ������");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	printf("\n������B��ʮ������");
//	for (j = 0; j < 10; j++)
//	{
//		scanf("%d", &B[j]);
//	}
//	for (k = 0; k < 10; k++)
//	{
//		Change(&A[k], &B[k]);
//	}
//	printf("\n����������A����:");
//	for (i = 0; i < 10; i++)
//	{
//        printf("%d  ",A[i]);
//	}		
//	printf("\n����������B����:");
//	for (j = 0; j < 10; j++)
//	{
//		printf("%d  ",B[j]);
//	}
//	printf("\n");
//	return 0;
//}