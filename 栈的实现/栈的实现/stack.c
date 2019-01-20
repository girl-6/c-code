#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;    //栈容量为0
	ps->_top = 0;       //栈顶指针指向最后一个元素的后一个位置
}

void StackDestory(Stack* ps)
{
	assert(ps);
	ps->_capacity = 0;
	ps->_top = 0;
	free(ps->_a);    //释放栈内所有元素
	ps->_a = NULL;
}

void StackPush(Stack *ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)       //若栈满则扩容
	{
		size_t newcapacity = (ps->_capacity == 0 ? 4 : ps->_capacity * 2);
		ps->_a = (STDataType*)realloc(ps->_a, sizeof(STDataType)*newcapacity);
		assert(ps->_a);           //判断扩容是否成功
		ps->_capacity = newcapacity;     //扩容的结果为新容量
	}
	ps->_a[ps->_top] = x;     //注意栈顶指针的初始位置
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps && (ps->_top > 0));
	ps->_top--;       //栈顶指针控制栈内元素
}

STDataType  StackTop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	return ps->_a[ps->_top-1];   //注意栈顶指针的初始位置
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
	return ps->_top;    //栈内元素个数=栈顶指针
}

void StackPrint(Stack* ps)
{
	assert(ps);
	for (int i = 0; i < ps->_top; i++)
	{
		printf("%d ", ps->_a[ps->_top-1 - i]);   //按数组下标输出
	}
	printf("\n");
}
//下面的方法也可以输出，但是慎用。因为每输出一次栈就被清空一次
//void StackPrint(Stack* ps)
//{
//	assert(ps);
//	while (StackEmpty(ps) != 0)
//	{
//		printf("%d ", StackTop(ps));
//		StackPop(ps);
//	}
//	printf("\n");
//}

void TestStack()
{
	Stack st;
	StackInit(&st);
	printf("初始化完成！ \n");
	printf("入栈的结果是：");
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 3);
	StackPrint(&st);
	printf("出栈的结果是：");
	StackPop(&st);
	StackPrint(&st);
	printf("栈顶元素是： %d\n", StackTop(&st));
	STDataType i = StackEmpty(&st);
	if (i == 0) printf("栈为空！\n");
	else printf("栈未空！ \n");
	printf("栈内元素有%d 个\n", StackSize(&st));
	StackDestory(&st);
	printf("销毁成功！ \n");
}