#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//
//#define N 10
//int main()
//{
//	int i = 0;
//	int j = N - 1;
//	int a[N] = { 0 };
//	printf("请输入%d个数：", N);
//    for (int x = 0; x < N; x++)
//	{
//		scanf("%d",&a[x]);
//	}
//	while (i< j)
//	{
//		//从左边找到第一个偶数
//		while (a[i] % 2 != 0)
//		{
//			i++;
//		}
//		//从右边找到第一个奇数
//		while(a[j] % 2 == 0)
//		{
//			j--;
//		}
//		//交换
//			int temp = a[i];
//			a[i] = a[j];
//			a[j] = temp;
//	}
//	for (int y = 0; y < N; y++)
//	{
//		printf("%d ", a[y]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//2.杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5

int search(int arr[3][3], int row, int col, int k, int *px, int*py)
{
	int i = 0;
	int j = col - 1;
	//从右上角开始查找	
		//在有效范围内查找
		while (i < row &&j >= 0)
		{
			if (arr[i][j] == k)
			{
				*px = i;
				*py = j;
				return 1;
			}
			else if (arr[i][j] < k)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		*px = -1;
		*py = -1;
		return 0;
}
int main()
{
	int a[3][3] = { 1, 2, 3, 2, 3, 4, 3, 4, 5 };
	int px;
	int py;
	search(a, 3, 3, 5,&px,&py);
	printf("%d %d\n", px,py);
	system("pause");
	return 0;
}
