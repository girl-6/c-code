#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;   //栈内元素数组
	int _top;       //栈顶指针
	int _capacity;    //栈的容量
}Stack;

void StackInit(Stack* ps);
//栈的初始化：构造一个空栈
void StackDestory(Stack* ps);
//栈的销毁：置空栈
void StackPush(Stack *ps, STDataType x);
//入栈：对已存在的栈，在栈顶插入一个元素，栈改变
void StackPop(Stack* ps);
//出栈：对已存在的栈，删除栈顶元素，栈改变
STDataType  StackTop(Stack* ps);
//取栈顶元素：读栈顶元素并返回其值，栈不变
int StackEmpty(Stack* ps);
//判断栈是否为空：若栈空则返回0，否则返回1
int StackSize(Stack* ps);
//计算栈内元素个数，并返回此值，栈不变
void StackPrint(Stack* ps);
//栈的打印：输出栈内元素

void TestStack();
//测试函数：测试上述函数功能