#define _CRT_SECURE_NO_WARNINGS 1
#include "Common.h"
#pragma once

typedef int SLDataType;

// 顺序表的动态存储 
typedef struct SeqList
{
	SLDataType* _array;   // 指向动态开辟的数组 
	size_t _size;        // 有效数据个数 
	size_t _capacity;    // 容量空间的大小 
}SeqList;
// 基本增删查改接口 
void SeqListInit(SeqList* psl, size_t capacity);    
//初始化：定义一个空顺序表
void SeqListDestory(SeqList* psl);    
// 销毁：释放所有值

void CheckCapacity(SeqList* psl);      
// 检查容量：若不足则扩容，数组直接追加
void SeqListPushBack(SeqList* psl, SLDataType x);       
//尾插：要记得检查容量，直接插入，数据个数改变
void SeqListPopBack(SeqList* psl);                    
//尾删;可用_size控制，直接操作，数据个数改变
void SeqListPushFront(SeqList* psl, SLDataType x);      
//头插：记得检查容量，且将所有值后移再插入第一个位置，数据个数改变
void SeqListPopFront(SeqList* psl);                    
//头删：从第二个数开始，依次前移，数据个数改变

//SLDataType SeqListFind(SeqList* psl, SLDataType x);
int SeqListFind(SeqList* psl, SLDataType x);       
//找顺序表中的某个值：找到了返回1，否则返回0
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);      
//在指定位置插入：将指定位置及之后的值都向后移，再插入x,数据个数改变
void SeqListErase(SeqList* psl, size_t pos);                   
//删除指定位置：将指定位置之后的值依次向前移，数据个数改变
void SeqListRemove(SeqList* psl, SLDataType x);                   
//删除指定值：找到x，将其后的值依次前移
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);       
//修改指定位置的值：直接将指定位置的值用x覆盖
void SeqListPrint(SeqList* psl);                                   
//打印顺序表：按数组打印

void SeqListTest1();

// 扩展面试题实现 
void SeqListBubbleSort(SeqList* psl);                           
//顺序表排序：用冒泡排序，即比较相邻的两个值，判断是否交换
int SeqListBinaryFind(SeqList* psl, SLDataType x);              
//二分查找：找到返回，否则返回0

// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);               
//删除所有x，重复做删除指定值的操作
int SeqListEmpty(SeqList* psl);                                 
//判断是否为空：空为0，否则返回1