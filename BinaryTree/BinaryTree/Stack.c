#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_a);
	ps->_a = NULL;
}

void StackPush(Stack *ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity == 0 ? 4 : ps->_capacity * 2);
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top]= x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	ps->_top--;
}

STDataType  StackTop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	return ps->_a[ps->_top - 1];
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return 0;
	else return 1;
}

int StackSize(Stack* ps)
{
	assert(ps);
	STDataType size = ps->_top;
	return size;
}

void StackPrint(Stack* ps)
{
	assert(ps);
	while (StackEmpty(ps) != 0)
	{
		printf("%d ", StackTop(ps));
		StackPop(ps);
	}
	printf("\n");
}

//void TestStack()
//{
//	Stack st;
//	StackInit(&st);
//	printf("初始化完成！ \n");
//	printf("尾插的结果是：");
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 3);
//	StackPrint(&st);
//	printf("尾删的结果是：");
//	StackPop(&st);
//	StackPrint(&st);
//	printf("栈顶元素是： %d\n", StackTop(&st));
//	STDataType i=StackEmpty(&st);
//	if (i == 0) printf("栈为空！\n");
//	else printf("栈未空！ \n");
//	printf("栈内元素有%d 个\n", StackSize(&st));
//	StackDestory(&st);
//	printf("销毁成功！ \n");
//}