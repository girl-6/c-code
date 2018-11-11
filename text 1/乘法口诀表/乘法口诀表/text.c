#define _CRT_SECURE_NO_WARNINGS 1
# include <stdio.h>
# include<math.h>
int main()
{
	for (int i = 1; i<10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int k = i*j;
			printf("%d*%d=%d  ", i, j, k);
		}
		printf("\n");
	}
	return 0;
}
