#define _CRT_SECURE_NO_WARNINGS
#include"contact.h" 
//静态版本

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
void meun()
{
	printf("*********************************\n");
	puts("1.添加");
	puts("5.显示");
	printf("****0.退出                  ****\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********************************\n");

} 

int main()
{
	int input = 0;
	Contact con;//通讯录 
	 //初始话通讯录
	InitContact(&con);

	do
	{
		meun();
		printf("请选择:");
		scanf_s("%d", &input);
		switch(input)
		{
			case ADD:
				AddContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case EXIT:
				DestoryContact(&con);
				printf("退出通讯录\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	} while (input);
}






