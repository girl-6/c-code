
//1.��ɿ����е�ɨ�׳��򣬲��Ż���
//1>��һ�����ӣ���ը����
//2>������Χû�ף�����ʵ��չ����#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);
void DisPlayBoard(char arr[ROWS][COLS], int row, int col);
void SetMine(char mine[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);

#endif