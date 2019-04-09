#define _CRT_SECURE_NO_WARNINGS
#include<string.h>`
#include<assert.h>
#include<stdio.h>
#include<errno.h>
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdlib.h>
#define DEFAULT_SZ 2
#define INC_SZ 3
#define MAX 1000
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	EMPTY,
	SORT,
};
#define NAME_MAX 20
#define SEX_MAX 10
#define TELE_MAX 20
#define ADDR_MAX 30
//����һ���ṹ��
typedef struct PeoInfo
{
	char Name[NAME_MAX];
	char Sex[SEX_MAX];
	short int Age;
	char Tele[TELE_MAX];
	char Addr[ADDR_MAX];
}PeoInfo;
typedef struct Contact
{
	PeoInfo* data;
	int sz;//ͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;//ͨѶ¼���ܴ�ŵ��������
}Contact;

void InitContact(Contact* pcon);     //��ʼ��ͨѶ¼
void DstoryContact(Contact* pcon);    //����ͨѶ¼
void AddContact(Contact* pcon);       //�����ϵ��
void ShowContact(Contact* pcon);      // �鿴��ϵ��
void DelContact(Contact* pcon);         //ɾ����ϵ��
void SaveContact(Contact* pcon);        //������ϵ��
void LoaContact(Contact* pcon);         //�����ļ�

#endif //__CONTACT_H__
