#include "SList.h"

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newnode =(SListNode*) malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* newnode = BuySListNode(x);
		newnode->_next = cur;
		plist->_head = newnode;
}

void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)   return cur;
	    cur = cur->_next;
	}
	return NULL;
}

// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* next = pos->_next;
	SListNode* newnode = BuySListNode(x);
	newnode->_next = next;
	pos->_next = newnode;
}

// 在pos的前面进行插入 
void SListInsertFront(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->_next = pos->_next;
	pos->_next = newnode;
	newnode->_data = pos->_data;
	pos->_data = x;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->_next->_next;
	if (pos->_next == NULL)  return;
	free(pos->_next);
	pos->_next = next ;	
}

void SListErase(SListNode* pos)
{
	assert(pos);
	SLTDataType n = pos->_next->_data;
	SListNode* next = pos->_next->_next;
	free(pos->_next);
	pos->_next = next;
	pos->_data = n;
}

void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	/*if (cur->_data == x)
	{
		free(plist->_head);
		plist->_head = cur->_next;
		return;
	}*/
	SListNode* prev = NULL;
	while (cur)
	{
		SListNode* next = cur->_next;
		if (cur->_data == x)
		{
			if (cur == plist->_head)
				plist->_head = next;
			else
			{
				prev->_next = next;
				free(cur);
				cur = NULL;
			}
			break;
		}
			prev = cur;
			cur = next;
	}
}

void SListPrint(SList* plist)
{
	SListNode* cur = plist->_head;
	while (cur)
	{
		printf("%d  ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}


void TestSList()
{
	SList s1;
	SListInit(&s1);

	SListPushFront(&s1, 1);
	SListPushFront(&s1, 2);
	SListPushFront(&s1, 3);
	SListPushFront(&s1, 4);
	printf("头插的结果是： ");
	SListPrint(&s1);
	printf("头删的结果是： ");
	SListPopFront(&s1);
	SListPrint(&s1);
	printf("在2后面插入4的结果是：  ");
	SListNode* n=SListFind(&s1, 2);
	if (n == NULL)  printf("位置不存在！原链表值为： \n");
	else  SListInsertFront(n, 4);
	SListPrint(&s1);
	printf("在2前面插入4的结果是：  ");
	 n = SListFind(&s1, 2);
	if (n == NULL)  printf("位置不存在！原链表值为： \n");
	else  SListInsertAfter(n, 4);
	SListPrint(&s1);
	printf("删除2位置的值; ");
	SListErase(n);
	SListPrint(&s1);
	printf("删除2后面的位置; ");
	SListEraseAfter(n);
	SListPrint(&s1);
	printf("删除3这个值; ");
	SListRemove(&s1, 3);
	SListPrint(&s1);

	SListDestory(&s1);
}