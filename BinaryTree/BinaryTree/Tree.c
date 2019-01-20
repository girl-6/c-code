#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"


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


int BinaryTreeSize(BTNode* root)
{
	if (root == NULL) 
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		if ((root->_left == NULL) && (root->_right == NULL))
			return 1;
		else
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
	}
}

int BinaryTreeLevelkSize(BTNode* root, int k)
{
	if (root == NULL)		return 0;
	if (k==1)
		return 1;
	return BinaryTreeLevelkSize(root->_left,k-1) + BinaryTreeLevelkSize(root->_right,k-1);
}

BTNode *BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root == NULL)	
		return NULL;
	if (root->_data == x)   
		return root;
	 ret = BinaryTreeFind(root->_left, x);
	{
		if (ret)
			return ret;
		ret = BinaryTreeFind(root->_right, x);
		if (ret)
			return ret;
	}	
	return NULL;
}


void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Qu q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
		while (QueueEmpty(&q) != 0)
		{
			BTNode* front = QueueFront(&q);
			printf("%c ", front->_data);
			QueuePop(&q);

			if (front->_left)
			    QueuePush(&q, front->_left);
			if (front->_right)
			    QueuePush(&q, front->_right);
		}
	}
}

int BinaryTreeComplete(BTNode* root)
{
	Qu q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
		while (QueueEmpty(&q))
		{
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			if (front == NULL)
				break;
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		while (QueueEmpty(&q) )
		{
			BTNode* front = QueueFront(&q);
			if (front != NULL)
			{
				QueueDestory(&q);
				return 0;
			}	
			QueuePop(&q);
		}
		return 1;
	}	
	return 0;
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
		cur=top->_right;
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
		else cur=top->_right;
	} 
}

void Test()
{
   char a[20] = "ABD##E#H##CF##G##";
   //int sz = (sizeof(a) / sizeof(a[0]));
   int pi = 0;
   int i = 0;
   BTNode* root = BinaryTreeCreate(a, &pi);
   printf("�������ɹ���\n");
   printf("����ĸ����ǣ� ");
   printf("%d\n", BinaryTreeSize(root));
   printf("��Ҷ�ӽ��ĸ����ǣ� ");
   printf("%d\n", BinaryTreeLeafSize(root));
   printf("��3����ĸ����ǣ� ");
   printf("%d\n", BinaryTreeLevelkSize(root, 3));
   printf("��ǰ������Ľ���ǣ� ");
   BinaryTreePrevOrder(root);
   printf("\n");
   printf("����������Ľ���ǣ� ");
   BinaryTreeInOrder(root);
   printf("\n");
   printf("����������Ľ���ǣ� ");
   BinaryTreePostOrder(root);
   printf("\n");
   printf("����������Ľ���ǣ� ");
   BinaryTreeLevelOrder(root);
   printf("\n");
   i=BinaryTreeComplete(root);
   if (i == 1) printf("��������ȫ��������\n ");
   else  printf("��������ȫ��������\n ");
   printf("\n\n\n ���������ķǵݹ������\n");
   printf("��ǰ������Ľ���ǣ� ");
   BinaryPrevOrder(root);
   printf("\n");
   printf("����������Ľ���ǣ� ");
   BinaryInOrder(root);
   printf("\n");
   printf("����������Ľ���ǣ� ");
   BinaryPostOrder(root);
   printf("\n");
  BinaryTreeDestory(root);
  printf("���ٳɹ���\n");
}

