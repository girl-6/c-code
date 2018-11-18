#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i=1;
	float sum = 0;
	while (i <= 100)
	{
		if (i % 2 == 0)
		{
			sum -= 1 / (i++*1.0);
		}
		else
		{
			sum += 1 / (i++*1.0);
		}
	}
	printf("%f\n", sum);
	return 0;
}