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
//定义一个结构体
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
	int sz;//通讯录中有效信息的个数
	int capacity;//通讯录所能存放的最大容量
}Contact;

void InitContact(Contact* pcon);     //初始化通讯录
void DstoryContact(Contact* pcon);    //销毁通讯录
void AddContact(Contact* pcon);       //添加联系人
void ShowContact(Contact* pcon);      // 查看联系人
void DelContact(Contact* pcon);         //删除联系人
void SaveContact(Contact* pcon);        //保存联系人
void LoaContact(Contact* pcon);         //加载文件

#endif //__CONTACT_H__
