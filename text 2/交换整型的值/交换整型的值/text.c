#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a, b, c;
	printf("��������������");
	scanf("%d%d", &a, &b);
	//���������ַ��� 1.���õ��������ͱ���2.�����������Ӽ� 3.�ö�����λ�����
	//c=a;
	//a=b;
	//b=c;

	a = a - b;
	b = a + b;
	a = b - a;

	//	a=a^b;
	//	b=a^b;
	//	a=a^b;
	printf("���������Ϊ��%d %d\n", a, b);
	return 0;
}
