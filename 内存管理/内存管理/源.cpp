#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
using namespace std;

int globalvar = 1;
static int staticGlobalvar = 1;
void test()
{
	static int s = 1;
	int l = 1;
	int num[10] = { 1, 2, 3, 4 };
	char ch[] = "abcd";
	char *p3 = "abcd";
	int *p1 = (int*)malloc(sizeof(int)* 4);
	int *p2 = (int*)calloc(4, sizeof(int));
	int *p4 = (int*)realloc(p2, sizeof(int)* 4);
	free(p1);
	free(p4); 
}

int main()
{
	test(); 
	system("pause");
	return 0;
}