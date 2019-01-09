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

//������
BTNode *BinaryTreeCreate(BTDataType*a, int*pi);

void BinaryTreeDestory(BTNode* root);
//���Ľ��
int BinaryTreeSize(BTNode* root);
//����Ҷ�ӽ��
int BinaryTreeLeafSize(BTNode* root);
//��ĳһ��Ľ��
int BinaryTreeLevelkSize(BTNode* root, int k);

BTNode *BinaryTreeFind(BTNode* root, BTDataType x);
//����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
//�������
void BinaryTreeLevelOrder(BTNode* root);
//�ж��Ƿ���ȫ������
int BinaryTreeComplete(BTNode* root);
//�ǵݹ����
void BinaryPrevOrder(BTNode* root);
void BinaryInOrder(BTNode* root);
void BinaryPostOrder(BTNode* root);

void Test();



typedef BTNode* QDataType;
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QNode;

typedef struct Queue
{
	QNode* _head;
	QNode* _tail;
}Qu;

void QueueInit(Qu*pq);
void QueueDestory(Qu* pq);
void QueuePrint(Qu* pq);
QNode* BuyQueueNode(QDataType x);
void QueuePush(Qu* pq, QDataType x);
void QueuePop(Qu* pq);
QDataType QueueFront(Qu* pq);
QDataType QueueBack(Qu*pq);
int QueueEmpty(Qu* pq);
int QueueSize(Qu* pq);

void TestQueue();


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

void TestStack();

#endif//__TREE_H__

