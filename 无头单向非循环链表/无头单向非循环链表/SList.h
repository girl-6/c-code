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

void SListInit(SList* plist);//�����ʼ��
void SListDestory(SList* plist);//��������
SListNode* BuySListNode(SLTDataType x);//�½����
void SListPushFront(SList* plist, SLTDataType x);//ͷ��
void SListPopFront(SList* plist);//ͷɾ
SListNode* SListFind(SList* plist, SLTDataType x);//�ҵ�ĳ��ֵ
void SListInsertAfter(SListNode* pos, SLTDataType x);// ��pos�ĺ�����в��� 
void SListInsertFront(SListNode* pos, SLTDataType x);// ��pos��ǰ����в��� 
void SListEraseAfter(SListNode* pos);//ɾ��pos�����ֵ
void SListErase(SListNode* pos);//ɾ��posλ�õ�ֵ
void SListRemove(SList* plist, SLTDataType x);//ɾ������x
void SListPrint(SList* plist);//��ӡ
void TestSList();//���Ժ���