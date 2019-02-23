#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

//��ʼ������
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)    
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			arr[i][j] = set;                                      //���ó�ʼֵ
	}
}

//��ʾ����
void DisPlayBoard(char arr[ROWS][COLS], int row, int col)
{
	printf("0--");
	for (int i = 1; i < col ; i++)
		printf("%d-", i); 
	printf("%d", col);
	printf("\n\n");
	for (int j = 1; j < row + 1; j++)
	{
		printf("%d  ", j);
		for (int i = 1; i < col+1; i++)
		{
			printf("%c ", arr[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}

//����
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

//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < (row*col - EASY_COUNT))
	{
		printf("����������( 0<=x<=%d 0<=y<=%d )  >",ROW,COL);
		scanf("%d %d", &x, &y);
			if (mine[x][y] == '1')
			{
				printf("������˼������ը���ˣ�\n");
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
	if (win == (row*col - EASY_COUNT))
	{
		printf("��ϲ��Ӯ�ˣ�\n");
	}
}

//�õ���Χ�׵ĸ���
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x - 1][y] + mine[x + 1][y] +
		mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] -
		8 * '0';
}

//�˵�ѡ��
void menu()
{
	printf("****************************\n");
	printf("*****   1.play     *********\n");
	printf("****    0.exit     *********\n");
	printf("****************************\n");
}

//��Ϸ����
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ
	DisPlayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisPlayBoard(mine, ROW, COL);
	//����
	FindMine(mine, show, ROW, COL);
	DisPlayBoard(show, ROW, COL);
}
