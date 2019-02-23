#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出成功\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}

