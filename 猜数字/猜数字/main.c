#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
void menu()
{

	printf("******************************\n");
	printf("********** 1.game ************\n");
	printf("********** 0.exit ************\n");
	printf("******************************\n");
}
void game()
{
	int rand_num = rand() % 100 + 1;
	int input = 0;
	int count = 0;
	while (1)
	{
		printf("\n��������µ����֣�>");
		scanf("%d", &input);
		if (input < rand_num)
		{
			printf("\n��С�ˣ�");
			count++;
		}
		else if (input>rand_num)
		{
			printf("\n�´��ˣ�");
			count++;
		}
		else
		{
			count++;
			printf("\n��ϲ�㣬�¶��ˣ�");
			printf("\n��һ������%d��",count);
			break;
		}
	}
	printf("\n");
}
#include <time.h>
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("\n���������룡\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
