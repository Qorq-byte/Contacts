#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
//静态版本
//void InitContact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->date, 0, sizeof(pc->date));
//}

void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->date, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("AddContact::%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->date = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
	}
}


//动态版本
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->date = (PeoInfo*)calloc(DEFAULT_SZ,sizeof(PeoInfo));
	if (pc->date == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;
	//加载文件的信息到通讯录中
	return 0;
}

void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
}

//静态版本
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	if (pc->count == 100)
//	{
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//
//	printf("请输入名字:");
//	scanf("%s", pc->date[pc->count].name);
//	printf("请输入年龄:");
//	scanf("%d", &(pc->date[pc->count].age));
//	printf("请输入性别:");
//	scanf("%s", pc->date[pc->count].sex);
//	printf("请输入电话:");
//	scanf("%s", pc->date[pc->count].tele);
//	printf("请输入地址:");
//	scanf("%s", pc->date[pc->count].addr);
//	pc->count++;
//	printf("增加成功\n");
//}


//动态版本
void AddContact(Contact* pc)
{
	assert(pc);
	//增容
	CheckCapacity(pc);
	//
	printf("请输入名字:");
	scanf("%s", pc->date[pc->count].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->date[pc->count].age));
	printf("请输入性别:");
	scanf("%s", pc->date[pc->count].sex);
	printf("请输入电话:");
	scanf("%s", pc->date[pc->count].tele);
	printf("请输入地址:");
	scanf("%s", pc->date[pc->count].addr);
	pc->count++;
	printf("增加成功\n");
}











//按照名字来排序
















