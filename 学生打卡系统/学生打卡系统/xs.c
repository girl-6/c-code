#include "xs.h"

int main()
{
	int it = 0;
	printf("\t\t★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("\t\t★         ※欢迎进入学生考勤系统             ★\n");
	printf("\t\t★                                            ★\n");
	printf("\t\t★         1.学生信息及打卡情况录入           ★\n");
	printf("\t\t★                                            ★\n");
	printf("\t\t★         2.修改某个学生的打卡情况           ★\n");
	printf("\t\t★                                            ★\n");
	printf("\t\t★         3.查询某个学生的打卡记录           ★\n");
	printf("\t\t★                                            ★\n");
	printf("\t\t★         4.旷课学生的姓名及次数             ★\n");
	printf("\t\t★                                            ★\n");
	printf("\t\t★         5.学生打卡的总评分数计算           ★\n");
	printf("\t\t★                                            ★\n");
	printf("\t\t★         6.退出系统                         ★\n");
	printf("\t\t★                                            ★\n");
	printf("\t\t★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("\t *******请选择您需要的操作*******  ");
	scanf("%d", &it);
	switch (it)
	{
	case 1: input(); break;
	case 2:change(); break;
	case 3:search(); break;
	case 4:times(); break;
	case 5:evaluate(); break;
	case 6:           break;
	default: printf("请重新输入！\n");
	}
	if (it == 6)
		printf("\t\t\t退出考勤系统，欢迎下次使用！");
	system("pause");
	return 0;
}

void input()
{
	int i = 0;
	int j = 0;
	int x = 1;
	printf("************1.学生信息及打卡情况录入************\n");
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		printf("文件打开失败！ \n");
		main();
	}
	for (i = 0; x == 1; i++)
	{
		for (; j == 0;)
		{
			getchar();
			printf("请输入第%d个学生的姓名：", i + 1);
			gets(stu[i].name);
			printf("请输入第%d个学生的学号：", i + 1);
			gets(stu[i].number);
			printf("请输入第%d个学生的性别（男-m 女-f）：", i + 1);
			stu[i].sex = getchar();
			printf("请输入第%d个学生的出生日期（格式:年-月-日）：", i + 1);
			scanf("%d%d%d", &stu[i].year, &stu[i].month, &stu[i].day);
			printf("请输入第%d个学生当前的打卡次数：", i + 1);
			scanf("%d", &stu[i].k);
			printf("您输入的信息为： 姓名%s  学号%s   性别%c   出生日期 %d年%d月%d日   打卡次数%d  \n ",
				stu[i].name, stu[i].number, stu[i].sex,stu[i].year, stu[i].month, stu[i].day, stu[i].k);
			printf("请确定信息 （重输-0 确定-1)： ");
			scanf("%d", &j); //输入确认
		}		
		j = 0;
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			printf("文件写入错误！ \n");  // 写入文件
		printf("是否继续输入下一个学生的信息  终止-0 继续-1： ");
		scanf("%d", &x);   //继续输入的选择
	}
	fclose(fp);
	printf("返回主菜单-0 ：");
	getchar();
	a = getchar();
	getchar();
	if (a == '0')
		main();      //返回主菜单
}      //录入数据函数结束

void change()
{
	printf("************2.修改某个学生的打卡情况************\n");
	int i = 0;
	int j = 0;
	int t = 10;
	int it = 10;
	int x = 10;;
	char name[10] = { 0 };
	char number[10] = { 0 };
	if ((fp = fopen("data.txt", "r")) == NULL)   //将文件内容读入内存
	{
		printf("文件打开失败！ \n");
		main();
	}
	for (i = 0; feof(fp) == 0; ++i)
	{
		fread(&stu[i], sizeof(struct student), 1, fp);  //读取文件内容
	}
	printf("选择修改对象:按姓名查找-1 按学号查找-2： ");
 	scanf("%d", &it);
	if (it == 1)     //按姓名查找开始
	{
		printf("请输入需要修改学生的姓名： ");
		scanf("%s", &name);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].name, name);
		if (j == i)
		{
			t = 0;
			printf("未找到该学生信息，请重新输入！ \n");
			fclose(fp);
		}
		if (j < i)   //查询成功
		{
			printf("您查询的信息为： 姓名%s  学号%s   性别%c   打卡次数%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex, stu[j - 1].k);
		}
		printf("是否确认修改该生打卡信息 否-0  是-1： ");
		scanf("%d", &x);
		if (x == 1)
		{
			printf("请输入新的打卡次数： ");
			scanf("%d", &stu[j-1].k);    //输入新的打卡次数
			if ((fp = fopen("data.txt", "w")) == NULL) //以只写方式打开
			{
				printf("文件打开失败！ \n");
				main();
			}
			if (fwrite(&stu[j], sizeof(struct student), 1, fp) != 1)
				printf("文件写入错误！ \n");    //写入文件
		}
		fclose(fp);
	}//按姓名查找结束
	if (it == 2)    //按学号查找开始
	{
		printf("请输入需要修改学生的学号：");
		scanf("%s", &number);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].number, number);
		if (j == i)
		{
			t = 0;
			printf("未找到该学生信息，请重新输入！ \n");
		}
		if (j < i)   //查询成功
		{
			printf("您查询的信息为： 姓名%s  学号%s   性别%c  打卡次数%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex,  stu[j - 1].k);
		}
		printf("是否确认修改该生打卡信息 否-0 是-1：");
		scanf("%d", &x);
		if (x == 1)
		{
			printf("请输入新的打卡次数： ");
			scanf("%d", &stu[j-1].k);    //输入新的打卡次数
			if ((fp = fopen("data.txt", "w")) == NULL) //以只写方式打开
			{
				printf("文件打开失败！ \n");
				main();
			}
			if (fwrite(&stu[j], sizeof(struct student), 1, fp) != 1)
				printf("文件写入错误！ \n");    //写入文件
		}
		fclose(fp);
	}//按学号查询结束
	printf("是否继续修改其他学生打卡信息 返回主菜单-0 继续-1： ");
	scanf("%d", &x);
	if (x == 1)		change();
	else     		main();  //返回主菜单     
}    //修改数据函数内容结束


void search()
{
	printf("************3.查询某个学生的打卡记录************\n");
	int i = 0;
	int j = 0;
	int it = 10;
	int t = 10;
	int x = 10;
	char name[10] = { 0 };
	char number[10] = { 0 };
	if ((fp = fopen("data.txt", "r")) == NULL)   //将文件内容读入内存
	{
		printf("文件打开失败！ \n");
		main();
	}
	for (i = 0; feof(fp) == 0; ++i)
	{
		fread(&stu[i], sizeof(struct student), 1, fp);  //读取文件内容
	}
	printf("选择查找方式:按姓名查找-1 按学号查找-2： ");
	scanf("%d", &it);
	if (it == 1)     //按姓名查找开始
	{
		printf("请输入需要查询学生的姓名： ");
		scanf("%s", &name);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].name, name);
		if (j == i)
		{
			t = 0;
			printf("未找到该学生信息，请重新输入！ \n");
		}
		if (j < i)   //查询成功
		{
			printf("您查询的信息为： 姓名%s  学号%s   性别%c   出生日期 %d年%d月%d日   打卡次数%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex, stu[j - 1].year, stu[j - 1].month, stu[j - 1].day, stu[j - 1].k);
		}
		fclose(fp);
	}//按姓名查询结束
	if (it == 2)    //按学号查找开始
	{
		printf("请输入需要查询学生的学号：");
		scanf("%s", &number);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].number, number);
		if (j == i)
		{
			t = 0;
			printf("未找到该学生信息，请重新输入！ \n");
		}
		if (j < i)   //查询成功
		{
			printf("您查询的信息为： 姓名%s  学号%s   性别%c   出生日期 %d年%d月%d日   打卡次数%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex, stu[j - 1].year, stu[j - 1].month, stu[j - 1].day, stu[j - 1].k);
		}
		fclose(fp);
	}
	printf("是否继续查询其他学生打卡信息 返回主菜单-0 继续-1： ");
	scanf("%d", &x);
	if (x == 1)		search();
	else     		main();  //返回主菜单   
}

void times()
{
	printf("************4.旷课学生的姓名及次数  ************\n");
	int i = 0;
	int j = 0;
	int it = 0;
	if ((fp = fopen("data.txt", "r")) == NULL)   //将文件内容读入内存
	{
		printf("文件打开失败！ \n");
		main();
	}
	for (i = 0; feof(fp) == 0; i++)
	{
		fread(&stu[i], sizeof(struct student), 1, fp);  //读取文件内容
	}
	printf("旷课学生的姓名及次数如下：\n ");
	for (j = 0; j < i-1;j++ )
	{
		if (stu[j].k < kq)
		printf("姓名%s  学号%s   缺课次数%f  \n ",stu[j].name, stu[j].number, (kq - stu[j].k));
	}
	printf("是否返回主菜单 0否 1是： ");
	scanf("%d", &it);
	if (it == 0)  return;
	else main();
}

void evaluate()
{
	printf("************5.学生打卡的总评分数计算************\n");
	int i = 0;
	int j = 0;
	int t = 10;
	int it = 10;
	int x = 10;
	float score=0;
	char name[10] = { 0 };
	char number[10] = { 0 };
	if ((fp = fopen("data.txt", "r")) == NULL)  //将文件读入内存
	{
		printf("文件打开失败！ \n");
		main();
	}
	for (i = 0; feof(fp) == 0; ++i)
		fread(&stu[i], sizeof(struct student), 1, fp);   //读取文件内容
	printf("选择计算对象：1 按姓名查找 2 按学号查找： ");
	scanf("%d", &it);
	if (it == 1)     //按姓名查找开始
	{
		printf("请输入需要计算分数的学生姓名： ");
		scanf("%s", &name);
		for (j = 0; t != 0; ++j)
			t = strcmp(stu[j].name, name);
		if (j == i)
		{
			t = 0;
			printf("未找到该学生信息，请重新输入！ \n");
			fclose(fp);
		}
		if (j < i)   //查询成功
		{
			printf("您查询的信息为： 姓名%s  学号%s   打卡次数%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].k);
			score = stu[j-1].k / kq * 100;
			printf("该生当前打卡总评分为 %5.2f \n", score);
		}
		fclose(fp);
		printf("是否继续计算其他学生打卡分数 0否 1是");
		scanf("%d", &x);
		if (x == 1)	 evaluate();
		else         main();
	}      //按姓名查找结束
	if (it == 2)    //按学号查找开始
	{
		printf("请输入需要计算分数的学生学号：");
		scanf("%s", &number);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].number, number);
		if (j == i)
		{
			t = 0;
			printf("未找到该学生信息，请重新输入！ \n");
		}
		if (j < i)   //查询成功
		{
			printf("您查询的信息为： 姓名%s  学号%s   性别%c   打卡日期 %d年%d月%d日   打卡次数%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex, stu[j - 1].year, stu[j - 1].month, stu[j - 1].day, stu[j - 1].k);
			score = (float)(stu[j-1].k) / kq * 100;
			printf("该生当前打卡总评分为 %5.2f \n", score);
		}
		fclose(fp);
		printf("是否继续计算其他学生打卡分数 0否 1是");
		scanf("%d", &x);
		if (x == 1)	 evaluate();
		else         main();
	}    //按学号查找结束
	printf("0 返回主菜单\n");
	getchar();
	a = getchar();
	getchar();
	if (a == '0')
		main();  //返回主菜单         
}