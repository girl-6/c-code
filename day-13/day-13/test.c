#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
//
//#define N 10
//int main()
//{
//	int i = 0;
//	int j = N - 1;
//	int a[N] = { 0 };
//	printf("������%d������", N);
//    for (int x = 0; x < N; x++)
//	{
//		scanf("%d",&a[x]);
//	}
//	while (i< j)
//	{
//		//������ҵ���һ��ż��
//		while (a[i] % 2 != 0)
//		{
//			i++;
//		}
//		//���ұ��ҵ���һ������
//		while(a[j] % 2 == 0)
//		{
//			j--;
//		}
//		//����
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
//2.���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5

int search(int arr[3][3], int row, int col, int k, int *px, int*py)
{
	int i = 0;
	int j = col - 1;
	//�����Ͻǿ�ʼ����	
		//����Ч��Χ�ڲ���
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
