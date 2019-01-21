//队列：队列是一种特殊的线性表，特殊之处在于它只允许在表的前端进行删除操作，只在表的后端进行插入操作
//既和栈一样，队列是一种受限制的线性表。进行插入操作的端为队尾，进行删除操作的端为队头

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType _data;    //当前结点存储数据
	struct QueueNode* _next;   //指向下一个节点
}QNode;

typedef struct Queue
{
	QNode* _head;     //指向队列的头
	QNode* _tail;     //指向队列的尾
}Qu;

void QueueInit(Qu*pq);   
//队列的初始化：构造一个空队
void QueueDestory(Qu* pq);    
//队列的销毁：置空队列
void QueuePrint(Qu* pq);      
// 队列的打印：输出队列中数据
QNode* BuyQueueNode(QDataType x);    
//新建结点：单独结点
void QueuePush(Qu* pq, QDataType x);    
// 队尾插入（入队）：对已存在的队列，插入一个元素到队尾，队发生变化
void QueuePop(Qu* pq);               
//队头删除（出队）：对已存在队列，删除一个队首元素，队发生变化
QDataType QueueFront(Qu* pq);        
//取队头元素：读队首元素，并返回其值，队不变
QDataType QueueBack(Qu*pq);        
//取队头元素：读队尾元素，并返回其值，队不变
int QueueEmpty(Qu* pq);         
//判断队列是否为空：若为空队列则返回0，否则返回1
int QueueSize(Qu* pq);        
//计算队列的元素个数并返回此值，队不变

void TestQueue();           
//测试函数：测试上述函数功能