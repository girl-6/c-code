#define _CRT_SECURE_NO_WARNINGS 1
#include "Common.h"
#pragma once

typedef int SLDataType;

// ˳���Ķ�̬�洢 
typedef struct SeqList
{
	SLDataType* _array;   // ָ��̬���ٵ����� 
	size_t _size;        // ��Ч���ݸ��� 
	size_t _capacity;    // �����ռ�Ĵ�С 
}SeqList;
// ������ɾ��Ľӿ� 
void SeqListInit(SeqList* psl, size_t capacity);    
//��ʼ��������һ����˳���
void SeqListDestory(SeqList* psl);    
// ���٣��ͷ�����ֵ

void CheckCapacity(SeqList* psl);      
// ��������������������ݣ�����ֱ��׷��
void SeqListPushBack(SeqList* psl, SLDataType x);       
//β�壺Ҫ�ǵü��������ֱ�Ӳ��룬���ݸ����ı�
void SeqListPopBack(SeqList* psl);                    
//βɾ;����_size���ƣ�ֱ�Ӳ��������ݸ����ı�
void SeqListPushFront(SeqList* psl, SLDataType x);      
//ͷ�壺�ǵü���������ҽ�����ֵ�����ٲ����һ��λ�ã����ݸ����ı�
void SeqListPopFront(SeqList* psl);                    
//ͷɾ���ӵڶ�������ʼ������ǰ�ƣ����ݸ����ı�

//SLDataType SeqListFind(SeqList* psl, SLDataType x);
int SeqListFind(SeqList* psl, SLDataType x);       
//��˳����е�ĳ��ֵ���ҵ��˷���1�����򷵻�0
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);      
//��ָ��λ�ò��룺��ָ��λ�ü�֮���ֵ������ƣ��ٲ���x,���ݸ����ı�
void SeqListErase(SeqList* psl, size_t pos);                   
//ɾ��ָ��λ�ã���ָ��λ��֮���ֵ������ǰ�ƣ����ݸ����ı�
void SeqListRemove(SeqList* psl, SLDataType x);                   
//ɾ��ָ��ֵ���ҵ�x��������ֵ����ǰ��
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);       
//�޸�ָ��λ�õ�ֵ��ֱ�ӽ�ָ��λ�õ�ֵ��x����
void SeqListPrint(SeqList* psl);                                   
//��ӡ˳����������ӡ

void SeqListTest1();

// ��չ������ʵ�� 
void SeqListBubbleSort(SeqList* psl);                           
//˳���������ð�����򣬼��Ƚ����ڵ�����ֵ���ж��Ƿ񽻻�
int SeqListBinaryFind(SeqList* psl, SLDataType x);              
//���ֲ��ң��ҵ����أ����򷵻�0

// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);               
//ɾ������x���ظ���ɾ��ָ��ֵ�Ĳ���
int SeqListEmpty(SeqList* psl);                                 
//�ж��Ƿ�Ϊ�գ���Ϊ0�����򷵻�1