#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int n=0;
	int i, j,k;
	printf("你想输出菱形的行数是奇数几：");
		scanf("%d",&n );
	printf("你想要的菱形如下：\n");
	for (i = 1; i <= (n / 2 + 1); i++)
	{
		for (j = 1; j <= (n/2+1-i); j++)
			printf(" ");
        for (k = 1; k <= (2 * i -1); k++)
		    printf("*");		
		printf("\n");
	}
	for (i = 1 ; i <= n / 2; i++)
	{
		for (j = 1; j <= i; j++)
			printf(" ");
		for (k = 1; k <= (n - 2 * i); k++)
			printf("*");
		printf("\n");
	}
	system("pause");
	return 0;
}