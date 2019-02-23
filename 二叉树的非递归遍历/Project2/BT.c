#define _CRT_SECURE_NO_WARNINGS 1
#include "BT.h"


BTNode *BinaryTreeCreate(BTDataType*a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_left = root->_right = NULL;
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);
	return root;
}

void BinaryTreeDestory(BTNode* root)
{
	if (root)
	{
		BinaryTreeDestory(root->_left);
		BinaryTreeDestory(root->_right);
		free(root);
		root = NULL;
	}
}
void BinaryPrevOrder(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur != NULL)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&st);
		StackPop(&st);
		cur = top->_right;
	}
}

void BinaryInOrder(BTNode* root)
{
	Stack st;
	StackInit(&st);
	BTNode* cur = root;
	while (StackEmpty(&st) != 0 || cur != NULL)
	{
		while (cur != NULL)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&st);
		printf("%c ", top->_data);
		StackPop(&st);
		cur = top->_right;
	}
}

void BinaryPostOrder(BTNode* root)
{
	BTNode* cur = root;
	BTNode* prev = NULL;
	Stack st;
	StackInit(&st);
	while (cur || StackEmpty(&st) != 0)
	{
		while (cur != NULL)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&st);
		if (top->_right == NULL || top->_right == prev)
		{
			StackPop(&st);
			printf("%c ", top->_data);
			prev = top;
		}
		else cur = top->_right;
	}
}


void Test()
{
	char a[20] = "ABD##E#H##CF##G##";
	int pi = 0;
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &pi);
	printf("树创建成功！\n");
	printf("树前序遍历的结果是： ");
	BinaryPrevOrder(root);
	printf("\n");
	printf("树中序遍历的结果是： ");
	BinaryInOrder(root);
	printf("\n");
	printf("树后序遍历的结果是： ");
	BinaryPostOrder(root);
	printf("\n");
	BinaryTreeDestory(root);
	printf("销毁成功！\n");
}