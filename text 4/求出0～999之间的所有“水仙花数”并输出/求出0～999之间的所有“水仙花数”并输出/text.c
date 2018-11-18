#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i = 0;
	for (i = 0; i < 1000; i++)
	{
		int count = 1; 
		int tmp = i;
		int sum = 0;
		while (tmp / 10)
		{
			count++;
			tmp = tmp / 10;
		}
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, count);
			tmp = tmp / 10;
		}
		if (sum == i)
			printf("%d ", i);
	}
	/*int i = 0;
	int sum = 0;
	printf("水仙花数是：");
	for (i = 0; i < 1000; i++)
	{
		int tmp = i;
		int a = tmp / 100;
		int b = tmp % 100 / 10;
		int c = tmp % 100 % 10;
		if (a != 0)
			sum = (int)pow(a, 3) + (int)pow(b, 3) + (int)pow(c, 3);
		if (a == 0 && b != 0)
			sum = (int)pow(b, 2) + (int)pow(c, 2);
		if (a == 0 && b == 0)
			sum = c;
		if (sum == i)
			printf("%d  ", i);
	}*/
	system("pause");
	return 0;
}
