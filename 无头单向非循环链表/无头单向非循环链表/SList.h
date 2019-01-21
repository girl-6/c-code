#include "Common.h"

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);//链表初始化
void SListDestory(SList* plist);//链表销毁
SListNode* BuySListNode(SLTDataType x);//新建结点
void SListPushFront(SList* plist, SLTDataType x);//头插
void SListPopFront(SList* plist);//头删
SListNode* SListFind(SList* plist, SLTDataType x);//找到某个值
void SListInsertAfter(SListNode* pos, SLTDataType x);// 在pos的后面进行插入 
void SListInsertFront(SListNode* pos, SLTDataType x);// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos);//删除pos后面的值
void SListErase(SListNode* pos);//删除pos位置的值
void SListRemove(SList* plist, SLTDataType x);//删除所有x
void SListPrint(SList* plist);//打印
void TestSList();//测试函数