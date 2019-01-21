//���У�������һ����������Ա�����֮��������ֻ�����ڱ��ǰ�˽���ɾ��������ֻ�ڱ�ĺ�˽��в������
//�Ⱥ�ջһ����������һ�������Ƶ����Ա����в�������Ķ�Ϊ��β������ɾ�������Ķ�Ϊ��ͷ

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType _data;    //��ǰ���洢����
	struct QueueNode* _next;   //ָ����һ���ڵ�
}QNode;

typedef struct Queue
{
	QNode* _head;     //ָ����е�ͷ
	QNode* _tail;     //ָ����е�β
}Qu;

void QueueInit(Qu*pq);   
//���еĳ�ʼ��������һ���ն�
void QueueDestory(Qu* pq);    
//���е����٣��ÿն���
void QueuePrint(Qu* pq);      
// ���еĴ�ӡ���������������
QNode* BuyQueueNode(QDataType x);    
//�½���㣺�������
void QueuePush(Qu* pq, QDataType x);    
// ��β���루��ӣ������Ѵ��ڵĶ��У�����һ��Ԫ�ص���β���ӷ����仯
void QueuePop(Qu* pq);               
//��ͷɾ�������ӣ������Ѵ��ڶ��У�ɾ��һ������Ԫ�أ��ӷ����仯
QDataType QueueFront(Qu* pq);        
//ȡ��ͷԪ�أ�������Ԫ�أ���������ֵ���Ӳ���
QDataType QueueBack(Qu*pq);        
//ȡ��ͷԪ�أ�����βԪ�أ���������ֵ���Ӳ���
int QueueEmpty(Qu* pq);         
//�ж϶����Ƿ�Ϊ�գ���Ϊ�ն����򷵻�0�����򷵻�1
int QueueSize(Qu* pq);        
//������е�Ԫ�ظ��������ش�ֵ���Ӳ���

void TestQueue();           
//���Ժ���������������������