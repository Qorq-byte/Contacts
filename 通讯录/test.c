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
	printf("****1.增加             2.删除****\n");
	printf("****3.搜索             4.修改****\n");
	printf("****5.显示             6.排序****\n");
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
			case DEL:
				DelContact(&con);   
				break;
			case SEARCH:
				SearchContact(&con);
				break;
			case MODIFY:
				ModifyContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case EXIT:
				SaveContact(&con);
				DestoryContact(&con);
				printf("退出通讯录\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	} while (input);
}






