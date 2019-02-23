#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"

//用于层序遍历和判断完全二叉树

void QueueInit(Qu* pq)
{
	QDataType x = 0;
	assert(pq);
	pq->_head = BuyQueueNode(x);
	pq->_tail = pq->_head;
}

void QueueDestory(Qu* pq)
{
	QNode* cur = pq->_head->_next;
	while (cur != NULL)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
} 

QNode* BuyQueueNode(QDataType x)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

void QueuePush(Qu* pq, QDataType x)
{	
	QNode* newnode = BuyQueueNode(x);
	pq->_tail->_next = newnode;
	pq->_tail = newnode;
}

void QueuePop(Qu* pq)
{
	assert(pq);
	QNode* 	cur = pq->_head->_next;
	if (cur == NULL)
	{
		return;
	}
	if (cur == pq->_tail)
	{
		pq->_tail = pq->_head;
	}
	pq->_head->_next = cur->_next;
	free(cur);
}

QDataType QueueFront(Qu* pq)
{
	QNode* 	cur = pq->_head->_next;
	assert(pq);
	return cur->_data;
}

QDataType QueueBack(Qu*pq)
{
	assert(pq);
	return pq->_tail->_data;
}

int QueueEmpty(Qu* pq)
{
	QNode* 	cur = pq->_head->_next;
	if (cur == NULL)
		return 0;
	else return 1;
}

int QueueSize(Qu* pq)
{
	int count = 0;
	QNode* 	cur = pq->_head->_next;
	if (cur == NULL)
		return 0;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

void QueuePrint(Qu* pq)
{
	QNode* 	cur = pq->_head->_next;
	assert(pq);
	while (cur != NULL)
	{
		printf("%d  ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

/*void TestQueue()
{
	int i = 0;
	Qu queue;
	QueueInit(&queue);
	printf("初始化队列完成 \n");
	printf("尾插的结果是： ");
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePrint(&queue);
	printf("头删的结果是： ");
	QueuePop(&queue);
	QueuePrint(&queue);
	printf("队列的头结点是： %d \n", QueueFront(&queue));
	printf("队列的尾结点是： %d \n", QueueBack(&queue));
    i = QueueEmpty(&queue);
	if (i == 0)  printf("队列为空！\n ");
	else   printf("队列非空 \n ");
	printf("队列的个数是： %d \n", QueueSize(&queue));
	QueueDestory(&queue);
	printf("销毁成功！\n");

}*/