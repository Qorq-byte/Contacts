#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define DEFAULT_SZ 3
#define INC_SZ 2
#define MAX 100
#define MAX_NAME 20
#define	MAX_SEX 10
#define	MAX_TELE 12
#define MAX_ADDR 30

//类型声明
//人的信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR ];
}PeoInfo;

//通讯录
// 静态版本
//typedef struct  Contact
//{
//	PeoInfo date[MAX];//存放人的信息
//	int count ;//记录当前通讯录中实际的人数
//}Contact;


//动态版本
typedef struct  Contact
{
	PeoInfo *date;//存放人的信息
	int count ;//记录当前通讯录中实际的人数
	int capacity;//当前通讯录的容量
}Contact;

//初始化通讯录
int InitContact(Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);

//增加联系人到通讯录
void AddContact(Contact* pc);

//打印通讯录信息
void ShowContact(const Contact* pc);

//删除指定联系人
void DelContact(Contact*pc);

//查找指定联系人
void SearchContact(Contact* pc);

//修改指定联系人
void ModifyContact(Contact* pc);

//排序通讯录的内容
void SortContact(Contact* pc);

//保存通讯录信息到文件

//加载文件的信息到通讯录中
















