#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *fp;  //定义文件
char a;    //返回选择变量
float kq = 10;    //应到打卡次数

 struct  student
{
	char name[10];      //姓名
	char number[11];    //学号
	char sex;           //性别
	int year;           //出生日期--年
	int month;          //出生日期--月
	int day;            //出生日期--日
	int k;              //打卡次数
}stu[100];

void input();
void change();
void search();
void times();
void evaluate();
int main();

