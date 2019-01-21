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

void ListInit(List* plist);//�����ʼ��
void ListDestory(List* plist);//��������
ListNode* BuyListNode(LTDataType x);//�½����
void ListPushBack(List* plist, LTDataType x);//β��
void ListPopBack(List* plist); //βɾ
void ListPushFront(List* plist, LTDataType x);  //ͷ��
void ListPopFront(List* plist);   //ͷɾ

ListNode* ListFind(List* plist, LTDataType x);//�ҵ�ĳ��ֵ
void ListInsert(ListNode* pos, LTDataType x);// ��posλ�ý��в��� 
ListNode* ListPos(List* plist, LTDataType x);   //�ҵ�posλ��
void ListErase(ListNode* pos);//ɾ��posλ�õĽڵ� 
void ListRemove(List* plist, LTDataType x);   //ɾ��ĳ��ֵ
int ListSize(List*plist);//�������
void ListPrint(List*plist);    //��ӡ
void TestList();//���Ժ���