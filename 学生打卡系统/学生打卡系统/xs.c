#include "xs.h"

int main()
{
	int it = 0;
	printf("\t\t�������������������������\n");
	printf("\t\t��         ����ӭ����ѧ������ϵͳ             ��\n");
	printf("\t\t��                                            ��\n");
	printf("\t\t��         1.ѧ����Ϣ�������¼��           ��\n");
	printf("\t\t��                                            ��\n");
	printf("\t\t��         2.�޸�ĳ��ѧ���Ĵ����           ��\n");
	printf("\t\t��                                            ��\n");
	printf("\t\t��         3.��ѯĳ��ѧ���Ĵ򿨼�¼           ��\n");
	printf("\t\t��                                            ��\n");
	printf("\t\t��         4.����ѧ��������������             ��\n");
	printf("\t\t��                                            ��\n");
	printf("\t\t��         5.ѧ���򿨵�������������           ��\n");
	printf("\t\t��                                            ��\n");
	printf("\t\t��         6.�˳�ϵͳ                         ��\n");
	printf("\t\t��                                            ��\n");
	printf("\t\t�������������������������\n");
	printf("\t *******��ѡ������Ҫ�Ĳ���*******  ");
	scanf("%d", &it);
	switch (it)
	{
	case 1: input(); break;
	case 2:change(); break;
	case 3:search(); break;
	case 4:times(); break;
	case 5:evaluate(); break;
	case 6:           break;
	default: printf("���������룡\n");
	}
	if (it == 6)
		printf("\t\t\t�˳�����ϵͳ����ӭ�´�ʹ�ã�");
	system("pause");
	return 0;
}

void input()
{
	int i = 0;
	int j = 0;
	int x = 1;
	printf("************1.ѧ����Ϣ�������¼��************\n");
	if ((fp = fopen("data.txt", "w")) == NULL)
	{
		printf("�ļ���ʧ�ܣ� \n");
		main();
	}
	for (i = 0; x == 1; i++)
	{
		for (; j == 0;)
		{
			getchar();
			printf("�������%d��ѧ����������", i + 1);
			gets(stu[i].name);
			printf("�������%d��ѧ����ѧ�ţ�", i + 1);
			gets(stu[i].number);
			printf("�������%d��ѧ�����Ա���-m Ů-f����", i + 1);
			stu[i].sex = getchar();
			printf("�������%d��ѧ���ĳ������ڣ���ʽ:��-��-�գ���", i + 1);
			scanf("%d%d%d", &stu[i].year, &stu[i].month, &stu[i].day);
			printf("�������%d��ѧ����ǰ�Ĵ򿨴�����", i + 1);
			scanf("%d", &stu[i].k);
			printf("���������ϢΪ�� ����%s  ѧ��%s   �Ա�%c   �������� %d��%d��%d��   �򿨴���%d  \n ",
				stu[i].name, stu[i].number, stu[i].sex,stu[i].year, stu[i].month, stu[i].day, stu[i].k);
			printf("��ȷ����Ϣ ������-0 ȷ��-1)�� ");
			scanf("%d", &j); //����ȷ��
		}		
		j = 0;
		if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
			printf("�ļ�д����� \n");  // д���ļ�
		printf("�Ƿ����������һ��ѧ������Ϣ  ��ֹ-0 ����-1�� ");
		scanf("%d", &x);   //���������ѡ��
	}
	fclose(fp);
	printf("�������˵�-0 ��");
	getchar();
	a = getchar();
	getchar();
	if (a == '0')
		main();      //�������˵�
}      //¼�����ݺ�������

void change()
{
	printf("************2.�޸�ĳ��ѧ���Ĵ����************\n");
	int i = 0;
	int j = 0;
	int t = 10;
	int it = 10;
	int x = 10;;
	char name[10] = { 0 };
	char number[10] = { 0 };
	if ((fp = fopen("data.txt", "r")) == NULL)   //���ļ����ݶ����ڴ�
	{
		printf("�ļ���ʧ�ܣ� \n");
		main();
	}
	for (i = 0; feof(fp) == 0; ++i)
	{
		fread(&stu[i], sizeof(struct student), 1, fp);  //��ȡ�ļ�����
	}
	printf("ѡ���޸Ķ���:����������-1 ��ѧ�Ų���-2�� ");
 	scanf("%d", &it);
	if (it == 1)     //���������ҿ�ʼ
	{
		printf("��������Ҫ�޸�ѧ���������� ");
		scanf("%s", &name);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].name, name);
		if (j == i)
		{
			t = 0;
			printf("δ�ҵ���ѧ����Ϣ�����������룡 \n");
			fclose(fp);
		}
		if (j < i)   //��ѯ�ɹ�
		{
			printf("����ѯ����ϢΪ�� ����%s  ѧ��%s   �Ա�%c   �򿨴���%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex, stu[j - 1].k);
		}
		printf("�Ƿ�ȷ���޸ĸ�������Ϣ ��-0  ��-1�� ");
		scanf("%d", &x);
		if (x == 1)
		{
			printf("�������µĴ򿨴����� ");
			scanf("%d", &stu[j-1].k);    //�����µĴ򿨴���
			if ((fp = fopen("data.txt", "w")) == NULL) //��ֻд��ʽ��
			{
				printf("�ļ���ʧ�ܣ� \n");
				main();
			}
			if (fwrite(&stu[j], sizeof(struct student), 1, fp) != 1)
				printf("�ļ�д����� \n");    //д���ļ�
		}
		fclose(fp);
	}//���������ҽ���
	if (it == 2)    //��ѧ�Ų��ҿ�ʼ
	{
		printf("��������Ҫ�޸�ѧ����ѧ�ţ�");
		scanf("%s", &number);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].number, number);
		if (j == i)
		{
			t = 0;
			printf("δ�ҵ���ѧ����Ϣ�����������룡 \n");
		}
		if (j < i)   //��ѯ�ɹ�
		{
			printf("����ѯ����ϢΪ�� ����%s  ѧ��%s   �Ա�%c  �򿨴���%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex,  stu[j - 1].k);
		}
		printf("�Ƿ�ȷ���޸ĸ�������Ϣ ��-0 ��-1��");
		scanf("%d", &x);
		if (x == 1)
		{
			printf("�������µĴ򿨴����� ");
			scanf("%d", &stu[j-1].k);    //�����µĴ򿨴���
			if ((fp = fopen("data.txt", "w")) == NULL) //��ֻд��ʽ��
			{
				printf("�ļ���ʧ�ܣ� \n");
				main();
			}
			if (fwrite(&stu[j], sizeof(struct student), 1, fp) != 1)
				printf("�ļ�д����� \n");    //д���ļ�
		}
		fclose(fp);
	}//��ѧ�Ų�ѯ����
	printf("�Ƿ�����޸�����ѧ������Ϣ �������˵�-0 ����-1�� ");
	scanf("%d", &x);
	if (x == 1)		change();
	else     		main();  //�������˵�     
}    //�޸����ݺ������ݽ���


void search()
{
	printf("************3.��ѯĳ��ѧ���Ĵ򿨼�¼************\n");
	int i = 0;
	int j = 0;
	int it = 10;
	int t = 10;
	int x = 10;
	char name[10] = { 0 };
	char number[10] = { 0 };
	if ((fp = fopen("data.txt", "r")) == NULL)   //���ļ����ݶ����ڴ�
	{
		printf("�ļ���ʧ�ܣ� \n");
		main();
	}
	for (i = 0; feof(fp) == 0; ++i)
	{
		fread(&stu[i], sizeof(struct student), 1, fp);  //��ȡ�ļ�����
	}
	printf("ѡ����ҷ�ʽ:����������-1 ��ѧ�Ų���-2�� ");
	scanf("%d", &it);
	if (it == 1)     //���������ҿ�ʼ
	{
		printf("��������Ҫ��ѯѧ���������� ");
		scanf("%s", &name);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].name, name);
		if (j == i)
		{
			t = 0;
			printf("δ�ҵ���ѧ����Ϣ�����������룡 \n");
		}
		if (j < i)   //��ѯ�ɹ�
		{
			printf("����ѯ����ϢΪ�� ����%s  ѧ��%s   �Ա�%c   �������� %d��%d��%d��   �򿨴���%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex, stu[j - 1].year, stu[j - 1].month, stu[j - 1].day, stu[j - 1].k);
		}
		fclose(fp);
	}//��������ѯ����
	if (it == 2)    //��ѧ�Ų��ҿ�ʼ
	{
		printf("��������Ҫ��ѯѧ����ѧ�ţ�");
		scanf("%s", &number);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].number, number);
		if (j == i)
		{
			t = 0;
			printf("δ�ҵ���ѧ����Ϣ�����������룡 \n");
		}
		if (j < i)   //��ѯ�ɹ�
		{
			printf("����ѯ����ϢΪ�� ����%s  ѧ��%s   �Ա�%c   �������� %d��%d��%d��   �򿨴���%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex, stu[j - 1].year, stu[j - 1].month, stu[j - 1].day, stu[j - 1].k);
		}
		fclose(fp);
	}
	printf("�Ƿ������ѯ����ѧ������Ϣ �������˵�-0 ����-1�� ");
	scanf("%d", &x);
	if (x == 1)		search();
	else     		main();  //�������˵�   
}

void times()
{
	printf("************4.����ѧ��������������  ************\n");
	int i = 0;
	int j = 0;
	int it = 0;
	if ((fp = fopen("data.txt", "r")) == NULL)   //���ļ����ݶ����ڴ�
	{
		printf("�ļ���ʧ�ܣ� \n");
		main();
	}
	for (i = 0; feof(fp) == 0; i++)
	{
		fread(&stu[i], sizeof(struct student), 1, fp);  //��ȡ�ļ�����
	}
	printf("����ѧ�����������������£�\n ");
	for (j = 0; j < i-1;j++ )
	{
		if (stu[j].k < kq)
		printf("����%s  ѧ��%s   ȱ�δ���%f  \n ",stu[j].name, stu[j].number, (kq - stu[j].k));
	}
	printf("�Ƿ񷵻����˵� 0�� 1�ǣ� ");
	scanf("%d", &it);
	if (it == 0)  return;
	else main();
}

void evaluate()
{
	printf("************5.ѧ���򿨵�������������************\n");
	int i = 0;
	int j = 0;
	int t = 10;
	int it = 10;
	int x = 10;
	float score=0;
	char name[10] = { 0 };
	char number[10] = { 0 };
	if ((fp = fopen("data.txt", "r")) == NULL)  //���ļ������ڴ�
	{
		printf("�ļ���ʧ�ܣ� \n");
		main();
	}
	for (i = 0; feof(fp) == 0; ++i)
		fread(&stu[i], sizeof(struct student), 1, fp);   //��ȡ�ļ�����
	printf("ѡ��������1 ���������� 2 ��ѧ�Ų��ң� ");
	scanf("%d", &it);
	if (it == 1)     //���������ҿ�ʼ
	{
		printf("��������Ҫ���������ѧ�������� ");
		scanf("%s", &name);
		for (j = 0; t != 0; ++j)
			t = strcmp(stu[j].name, name);
		if (j == i)
		{
			t = 0;
			printf("δ�ҵ���ѧ����Ϣ�����������룡 \n");
			fclose(fp);
		}
		if (j < i)   //��ѯ�ɹ�
		{
			printf("����ѯ����ϢΪ�� ����%s  ѧ��%s   �򿨴���%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].k);
			score = stu[j-1].k / kq * 100;
			printf("������ǰ��������Ϊ %5.2f \n", score);
		}
		fclose(fp);
		printf("�Ƿ������������ѧ���򿨷��� 0�� 1��");
		scanf("%d", &x);
		if (x == 1)	 evaluate();
		else         main();
	}      //���������ҽ���
	if (it == 2)    //��ѧ�Ų��ҿ�ʼ
	{
		printf("��������Ҫ���������ѧ��ѧ�ţ�");
		scanf("%s", &number);
		for (j = 0; t != 0; j++)
			t = strcmp(stu[j].number, number);
		if (j == i)
		{
			t = 0;
			printf("δ�ҵ���ѧ����Ϣ�����������룡 \n");
		}
		if (j < i)   //��ѯ�ɹ�
		{
			printf("����ѯ����ϢΪ�� ����%s  ѧ��%s   �Ա�%c   ������ %d��%d��%d��   �򿨴���%d  \n ",
				stu[j - 1].name, stu[j - 1].number, stu[j - 1].sex, stu[j - 1].year, stu[j - 1].month, stu[j - 1].day, stu[j - 1].k);
			score = (float)(stu[j-1].k) / kq * 100;
			printf("������ǰ��������Ϊ %5.2f \n", score);
		}
		fclose(fp);
		printf("�Ƿ������������ѧ���򿨷��� 0�� 1��");
		scanf("%d", &x);
		if (x == 1)	 evaluate();
		else         main();
	}    //��ѧ�Ų��ҽ���
	printf("0 �������˵�\n");
	getchar();
	a = getchar();
	getchar();
	if (a == '0')
		main();  //�������˵�         
}