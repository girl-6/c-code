
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�2550136832
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
	printf("��������Ҫ��ת������");
	scanf("%d", &a);
	unsigned int ret = reverse_bit(a);
	printf("%u\n", ret);
	system("pause");
	return 0;
}
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("��������Ҫ�����;");
//	scanf("%d%d", &a,& b);
//	int ret = ((a + b) >> 1);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//
//#define N 9  //������ֻ��һ�����ֳ�����һ�Σ������������ֶ��ǳɶԳ��ֵ�
//int main()
//{
//	int i = 0;
//	int a[N] = { 0 };
//	int ret = 0;
//	printf("������%d�����ݣ�",N);
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

//4.��һ���ַ����������Ϊ:"student a am i",
//			���㽫��������ݸ�Ϊ"i am a student".
//			Ҫ��
//			����ʹ�ÿ⺯����
//			ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

//�ȶ��ַ���������תһ�Σ��ٽ�ÿһ���Ӵ���ת
//���ַ������ȣ�Ϊ���ҵ������ַ�����β��
//int strlen(char*str)
//{
//	int count = 0;
//	while (*str++)
//	{
//		count++;
//	}
//	return count;
//}
////ʵ���ַ�������ת
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
//	//��ת�����ַ���
//	reverse(left, right);
//	while (*cur)
//	{
//		//Ѱ���Ӵ�������β��
//		char*star = cur;
//		while ((*cur != ' ') && (*cur != '\0'))
//		{
//			cur++;
//		}		
//		//��תÿһ���Ӵ�
//		reverse(star, cur - 1);
//		//�ҵ���һ���Ӵ������
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