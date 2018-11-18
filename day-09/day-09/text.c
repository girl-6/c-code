#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

void menu()
{
	printf("****************************\n");
	printf("*****   1.play     *********\n");
	printf("****    0.exit     *********\n");
	printf("****************************\n");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印
	DisPlayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	DisPlayBoard(mine, ROW, COL);
	//排雷
	FindMine(mine, show, ROW, COL);
	DisPlayBoard(show, ROW, COL);
}
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

