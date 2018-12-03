#define _CRT_SECURE_NO_WARNINGS 1
#include "Common.h"
#pragma once
typedef int SLDataType;

// ˳���Ķ�̬�洢 
typedef struct SeqList
{
	SLDataType* _array; // ָ��̬���ٵ����� 
	size_t _size; // ��Ч���ݸ��� 
	size_t _capacity; // �����ռ�Ĵ�С 
}SeqList;
// ������ɾ��Ľӿ� 
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);

void CheckCapacity(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);

//SLDataType SeqListFind(SeqList* psl, SLDataType x);
void SeqListFind(SeqList* psl, SLDataType x);

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);

void SeqListTest1();

// ��չ������ʵ�� 
void SeqListBubbleSort(SeqList* psl);
void SeqListBinaryFind(SeqList* psl, SLDataType x);
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);
void SeqListEmpty(SeqList* psl);