#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//1.��ɲ�������Ϸ��
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
//		printf("\n��������µ����֣�>");
//		scanf("%d", &input);
//		if (input < rand_num)
//		{
//			printf("\n��С�ˣ�");
//		}
//		else if (input>rand_num)
//		{
//			printf("\n�´��ˣ�");
//		}
//		else
//		{
//			printf("\n��ϲ�㣬�¶��ˣ�");
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
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("\n���������룡\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}

//2.д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�

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
//	printf("������%d������", N);
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	sz = sizeof (a) / sizeof (a[0]);
//	printf("\n����������ҵ�����");
//	scanf("%d", &k);
//	int ret = bin_search(a, k, sz);
//	if (ret >= 0)
//	{
//		printf("\n����Ҫ�����ڵ�%dλ��\n", ret);
//	}
//	else
//		printf("\n�������޴�����\n");
//	system("pause");
//	return 0;
//}
//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����
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
//		printf("��������λ������;>");
//		scanf("%s", &a);
//		if(strcmp(password,a)==0)
//		{
//			printf("\n��½�ɹ���\n");
//			break;
//		}
//		else
//		{
//			printf("\n����������������룡\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("�˳���\n");
//	}
//	system("pause");
//	return 0;
//}
//4.��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������
//int main()
//{
//	int ch=0;
//	printf("����������;");
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

//5.ʵ��һ���������ж�һ�����ǲ���������
#include <math.h>
int Is_prime(int a)
{
	int i = 0;
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
		{
			return 0;//��������
		}
	}
	return 1;//������
}
int main()
{
	int n = 0;
	int ret = 0;
	printf("������Ҫ�жϵ�����");
	scanf("%d", &n);
	ret = Is_prime(n);
	if (ret == 1)
	{
		printf("%d��������\n", n);
	}
	else
	{
		printf("%d����������\n", n);
	}
	system("pause");
	return 0;
}