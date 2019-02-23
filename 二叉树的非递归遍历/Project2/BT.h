#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __TREE_H__
#define __TREE_H__ 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//创建树
BTNode *BinaryTreeCreate(BTDataType*a, int*pi);
void BinaryTreeDestory(BTNode* root);
//非递归遍历
void BinaryPrevOrder(BTNode* root);
void BinaryInOrder(BTNode* root);
void BinaryPostOrder(BTNode* root);

void Test();

typedef BTNode* STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack *ps, STDataType x);
void StackPop(Stack* ps);
STDataType  StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void StackPrint(Stack* ps);

#endif//__TREE_H__