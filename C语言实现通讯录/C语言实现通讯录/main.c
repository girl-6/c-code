#include"Contact.h"
//菜单函数
void menu()
{
	printf("****************************************\n");
	printf("******1、add         2、del      *******\n");
	printf("******3、search      3、modify   *******\n");
	printf("******5、show        6、empty    *******\n");
	printf("******7、sort        0、exit     *******\n");
	printf("****************************************\n");
}
void test()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	LoaContact(&con);
	do{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EMPTY:
			break;
		case SORT:
			break;
		case EXIT:
			DstoryContact(&con);//利用free释放malloc开辟的空间
			printf("退出通讯录！\n");
			break;

		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}
