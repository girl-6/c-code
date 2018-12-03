#define _CRT_SECURE_NO_WARNINGS 1
#include "Common.h"
#pragma once
typedef int SLDataType;

// 顺序表的动态存储 
typedef struct SeqList
{
	SLDataType* _array; // 指向动态开辟的数组 
	size_t _size; // 有效数据个数 
	size_t _capacity; // 容量空间的大小 
}SeqList;
// 基本增删查改接口 
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

// 扩展面试题实现 
void SeqListBubbleSort(SeqList* psl);
void SeqListBinaryFind(SeqList* psl, SLDataType x);
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);
void SeqListEmpty(SeqList* psl);