#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include<assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;   //ջ��Ԫ������
	int _top;       //ջ��ָ��
	int _capacity;    //ջ������
}Stack;

void StackInit(Stack* ps);
//ջ�ĳ�ʼ��������һ����ջ
void StackDestory(Stack* ps);
//ջ�����٣��ÿ�ջ
void StackPush(Stack *ps, STDataType x);
//��ջ�����Ѵ��ڵ�ջ����ջ������һ��Ԫ�أ�ջ�ı�
void StackPop(Stack* ps);
//��ջ�����Ѵ��ڵ�ջ��ɾ��ջ��Ԫ�أ�ջ�ı�
STDataType  StackTop(Stack* ps);
//ȡջ��Ԫ�أ���ջ��Ԫ�ز�������ֵ��ջ����
int StackEmpty(Stack* ps);
//�ж�ջ�Ƿ�Ϊ�գ���ջ���򷵻�0�����򷵻�1
int StackSize(Stack* ps);
//����ջ��Ԫ�ظ����������ش�ֵ��ջ����
void StackPrint(Stack* ps);
//ջ�Ĵ�ӡ�����ջ��Ԫ��

void TestStack();
//���Ժ���������������������