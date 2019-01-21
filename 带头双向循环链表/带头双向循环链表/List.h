#include "Common.h"

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plist);//链表初始化
void ListDestory(List* plist);//链表销毁
ListNode* BuyListNode(LTDataType x);//新建结点
void ListPushBack(List* plist, LTDataType x);//尾插
void ListPopBack(List* plist); //尾删
void ListPushFront(List* plist, LTDataType x);  //头插
void ListPopFront(List* plist);   //头删

ListNode* ListFind(List* plist, LTDataType x);//找到某个值
void ListInsert(ListNode* pos, LTDataType x);// 在pos位置进行插入 
ListNode* ListPos(List* plist, LTDataType x);   //找到pos位置
void ListErase(ListNode* pos);//删除pos位置的节点 
void ListRemove(List* plist, LTDataType x);   //删除某个值
int ListSize(List*plist);//计算个数
void ListPrint(List*plist);    //打印
void TestList();//测试函数