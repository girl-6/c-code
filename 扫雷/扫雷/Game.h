#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __GAME_H__
#define __GAME_H__

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#define ROW 9           //定义行
#define COL 9           //定义列
#define ROWS ROW+2      
#define COLS COL+2
#define EASY_COUNT 10     //设置雷的个数

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set);    //初始化棋盘
void DisPlayBoard(char arr[ROWS][COLS], int row, int col);             //显示棋盘
void SetMine(char mine[ROWS][COLS], int row, int col);                 //埋雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);       //排雷
int GetMineCount(char mine[ROWS][COLS], int x, int y);                //得到周围雷的个数
void nemu();                                                          //菜单选择
void game();                                                          //游戏设置


#endif  //__GAME_H__
