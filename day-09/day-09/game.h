
//1.完成课堂中的扫雷程序，并优化：
//1>第一次下子，不炸死。
//2>坐标周围没雷，可以实现展开。#define _CRT_SECURE_NO_WARNINGS 1
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