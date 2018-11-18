#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}
void DisPlayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < col + 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i < row + 1; i++)
	{
		printf("%d", i);
		for (j = 1; j < col + 1; j++)
		{

			printf(" %c", arr[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<(row*col - EASY_COUNT))
	{
		printf("请输入坐标：>");
		scanf("%d %d", &x, &y);
		if (x<0 || x>row || y<0 || y>col)
		{
			printf("请重新输入：");
		}
		else
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了！\n");
				DisPlayBoard(mine, ROW, COL);

			}
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisPlayBoard(show, ROW, COL);
				win++;

			}
		}
	}
	if (win == (row*col - EASY_COUNT))
	{
		printf("你赢了！\n");
	}


}
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x - 1][y] + mine[x + 1][y] +
		mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] -
		8 * '0';
}