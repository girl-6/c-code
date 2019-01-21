#include "Common.h"
#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_prev = NULL;
	newnode->_next = NULL;
	return newnode;
}
void ListInit(List* plist)
{
	assert(plist);
	ListNode* head = BuyListNode(0);
	head->_next = head;
	head->_prev = head;
	plist->_head = head;
}

void ListDestory(List* plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(head);
}

void ListPushBack(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* prev = head->_prev;
	ListNode* newnode = BuyListNode(x);
	prev->_next = newnode;
	newnode->_next = head;
	head->_prev = newnode;
	newnode->_prev = prev;
}

void ListPopBack(List* plist)
{
	assert(plist&&plist->_head->_next!=plist->_head);
	ListNode* head = plist->_head;
	ListNode*tail = head->_prev;
	ListNode* prev = tail->_prev;
	free(tail);
	head->_prev = prev;
	prev->_next = head;	
}

void ListPushFront(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* newnode = BuyListNode(x);
	head->_next = newnode;
	newnode->_next = cur;
	cur->_prev = newnode;
	newnode->_prev = head;
}

void ListPopFront(List* plist)
{
	assert(plist&&plist->_head->_next);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	ListNode* next =cur->_next;
	free(cur);
	head->_next = next;
	next->_prev = head;
}

//找到某个值
ListNode*  ListFind(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur->_next!=head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;
}

//找到pos位置
ListNode* ListPos(List* plist, LTDataType x)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (--x)
	{
		cur = cur->_next;
	}
	return cur;
}

// 在pos的前面进行插入 
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	prev->_next = newnode;
	newnode->_next = pos;
	pos->_prev = newnode;
	newnode->_prev = prev;
}

// 删除pos位置的节点 
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->_next;
	ListNode* prev = pos->_prev;
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}

//删除某个值
void ListRemove(List* plist, LTDataType x)
{
	assert(plist&&plist->_head->_next != plist->_head);
	ListNode* head = plist->_head;
	//ListNode* cur = head->_next;
	ListNode* pos = ListFind(plist, x);
	if (pos != NULL)
	{
		ListNode* prev = pos->_prev;
		ListNode* next = pos->_next;
		prev->_next = next;
		next->_prev = prev;
	}
	else
		printf("本链表中无此值！  链表为： ");
}

int ListSize(List*plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	int count = 0;
	while (cur != head)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

void ListPrint(List*plist)
{
	assert(plist);
	ListNode* head = plist->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		printf("%d  ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void TestList()
{
	List s2;
	ListInit(&s2);

	ListPushBack(&s2, 1);
	ListPushBack(&s2, 2);
	ListPushBack(&s2, 3);
	ListPushBack(&s2, 4);
	ListPushBack(&s2, 5);
	ListPushBack(&s2, 5);
	ListPushBack(&s2, 5);
	printf("尾插的结果是： ");
	ListPrint(&s2);

	ListPopBack(&s2);
	ListPopBack(&s2);
	printf("尾删的结果是： ");
	ListPrint(&s2);

	ListPushFront(&s2, 1);
	ListPushFront(&s2, 2);
	printf("头插的结果是： ");
	ListPrint(&s2);

	ListPopFront(&s2);
	ListPopFront(&s2);
	printf("头删的结果是： ");
	ListPrint(&s2);

	printf("找3的结果： ");
	ListNode* find1=ListFind(&s2, 3);
	if (find1 !=NULL) printf("找到了！\n");
	else           printf("找不到！\n");
	printf("找6的结果： ");
	find1 = ListFind(&s2, 6);
	if (find1 != NULL) printf("找到了！\n");
	else           printf("找不到！\n");

	
	ListNode* find2 = ListPos(&s2, 2);
	ListInsert(find2, 9);
	printf("在第2个位置前面插入9的结果是： ");
	ListPrint(&s2);

	ListNode* find3 = ListPos(&s2, 2);
	ListErase(find3);
	printf("删除第2个位置之后的结果是： ");
	ListPrint(&s2);

	printf("删除4之后的结果是： ");
	ListRemove(&s2, 4);
	ListPrint(&s2);
	printf("删除6之后的结果是： ");
	ListRemove(&s2, 6);
	ListPrint(&s2);

	int size=ListSize(&s2);
	printf("链表中元素个数是：%d\n",size);

	ListDestory(&s2);
}