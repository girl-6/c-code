#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	printf("输出100到200间所有的素数：\n");
	int  i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j <= i; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			count++;
			printf("%d  ", i);
		}

	}
	printf("\ncount=%d\n", count);
	return 0;
}

/*
#include <stdio.h>
#include <math.h>
int main()
{
printf("输出100到200间所有的素数：\n");
for(int i=100;i<=200;i++)
{
int j=0;
for( j=2;j<=sqrt(i);j++)
if(i%j==0)
{
break;
}
if(j>sqrt(i))
{
printf("%d  ",i);
}
}

return 0;
} */