#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *fp;  //�����ļ�
char a;    //����ѡ�����
float kq = 10;    //Ӧ���򿨴���

 struct  student
{
	char name[10];      //����
	char number[11];    //ѧ��
	char sex;           //�Ա�
	int year;           //��������--��
	int month;          //��������--��
	int day;            //��������--��
	int k;              //�򿨴���
}stu[100];

void input();
void change();
void search();
void times();
void evaluate();
int main();

