#pragma once


#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "model.h"
#include "util.h"
#include "file.h"

Node List;

//增加学生信息
void AddStudentInfo()
{

	system("cls");

	Node student;//暂存数据

	int i[5] = {0};//控制输入错误次数


	printf("请输入新增学生相关信息\n");

	//输入学号
	colorPrint("学号:", green);
	while (1)
	{
		int ret = scanf("%d", &student.id);
		fflush(stdin);
		if (ret == 1)
			break;
		i[0]++;
		if(tooManyInputError(i[0]))return;
		
	}

	//输入姓名
	colorPrint("姓名：", green);
	scanf("%s", student.name);

	//输入性别
	colorPrint("性别(男:1;女:0):", green);
	while (1)
	{
		int a;
		int ret = scanf("%d", &a);
		fflush(stdin);
		if (ret == 1 && (a == 1 || a == 0))
		{
			if (a == 1)
			{
				strcpy(student.sex, "男");
			}
			else
			{
				strcpy(student.sex, "女");
			}
			break;
		}
		i[1]++;
		if(tooManyInputError(i[1]))return;
		
	}

	//输入语文成绩
	colorPrint("语文成绩:", green);
	while (2)
	{
		int ret = scanf("%d", &student.cs);
		fflush(stdin);
		if (ret == 1 && student.cs <= 100 && student.cs >= 0)
			break;
		i[2]++;
		if (tooManyInputError(i[2]))
		return;
		
	}

	//输入数学成绩
	colorPrint("数学成绩:", green);
	while (3)
	{
		int ret = scanf("%d", &student.ma);
		fflush(stdin);
		if (ret == 1 && student.ma <= 100 && student.ma >= 0)
			break;
		i[3]++;
		if(tooManyInputError(i[3]))return;
		
	}

	//输入英语成绩
	colorPrint("英语成绩:", green);
	while (4)
	{
		int ret = scanf("%d", &student.en);
		fflush(stdin);
		if (ret == 1 && student.en <= 100 && student.en >= 0)
			break;
		i[4]++;
		if(tooManyInputError(i[4]))return;

	}

	//计算总成绩
	student.sum = student.cs + student.ma + student.en;

	//插入信息
	insertStudentInfo(&List, student);
	//展示输入信息
	viewOneInfo(&student);
	colorPrint("\n录入成功！\n", blue);


}

//删除学生信息
void DeleteStudentInfo(Node *L)
{

	int id, a = 0;
	Node *p;

	colorPrint("请输入要删除的学生学号:", yellow);
	while (1)
	{
		int ret = scanf("%d", &id);
		if (ret == 1)
			break;
		a++;
		if (tooManyInputError(a))return;
		
	}

	Node *student = queryStudentInfoById(id, L);
	p = student;

	if (student == NULL)
	{
		colorPrint("\n查无此人！\n", red);
		return;
	}

	student = student->next;

	//展示信息
	viewOneInfo(student);//输出操作信息

	//删除信息
	deleteStudentInfo(p);
	//保存最新的文件
	saveFile(L);
	colorPrint("\n删除成功！\n", purple);
	return;

}

//修改学生信息
void UpdateStudentInfo(Node *L)
{
	system("cls");

	int id;
	int choice = -1;
	int i[5];

	colorPrint("请输入要修改的学生学号：", lightblue);
	while (1)
	{
		int ret = scanf("%d", &id);
		fflush(stdin);
		if (ret == 1)
			break;
		i[0]++;
		if (tooManyInputError(i[0]))return;
	
	}

	Node *student = queryStudentInfoById(id, L);

	if (student == NULL)
	{
		colorPrint("\n查无此人！\n", red);
		return;
	}

	student = student->next;

	//展示信息
	viewOneInfo(student);//输出操作信息

	printf("修改姓名---- 1\n");
	printf("修改性别---- 2\n");
	printf("修改语文---- 3\n");
	printf("修改数学---- 4\n");
	printf("修改英语---- 5\n");
	printf("完成修改---- 0\n");

	while (1)
	{

		colorPrint("请输入要执行的命令: ", greyblue);
		int a = 0;
		while (1)
		{
			int ret = scanf("%d", &choice);
			fflush(stdin);
			if ((ret == 1 && choice <= 5 && choice >= 0) || a > 3)
			{
				break;
			}
			a++;
			if(tooManyInputError(a))return;
			
		}


		switch (choice)
		{

		case 1:
			colorPrint("请输入修改后的姓名：", lightyellow);
			scanf("%s", student->name);
			break;

		case 2:
			colorPrint("请输入修改后的性别(男:1;女:0):", lightyellow);
			while (1)
			{
				int a;
				int ret = scanf("%d", &a);
				fflush(stdin);
				//避免乱码采用赋值此方式
				if (ret == 1 && (a == 1 || a == 0))
				{
					if (a == 1)
					{
						strcpy(student->sex, "男");
					}
					else
					{
						strcpy(student->sex, "女");
					}
					break;
				}

				i[1]++;
				
				if(tooManyInputError(i[1]))return;
				
			}
			break;

		case 3:
			colorPrint("请输入修改后的语文成绩:", lightyellow);
			while (2)
			{
				int ret = scanf("%d", &student->cs);
				fflush(stdin);
				if (ret == 1 && student->cs <= 100 && student->cs >= 0)
					break;
				i[2]++;
				if(tooManyInputError(i[2]))return;
				
			}
			break;

		case 4:
			colorPrint("请输入修改后的数学成绩:", lightyellow);
			while (3)
			{
				int ret = scanf("%d", &student->ma);
				fflush(stdin);
				if (ret == 1 && student->ma <= 100 && student->ma >= 0)
					break;
				i[3]++;
				if(tooManyInputError(i[3]))return;
				
			}
			break;

		case 5:
			colorPrint("请输入修改后的英语成绩:", lightyellow);
			while (4)
			{
				int ret = scanf("%d", &student->en);
				fflush(stdin);
				if (ret == 1 && student->en <= 100 && student->en >= 0)
					break;
				i[4]++;
				if(tooManyInputError(i[4]))return;
			
			}
			break;

		case 0:
			goto Loop;
			break;
		}
	}
Loop:
	student->sum = student->cs + student->ma + student->en;
	colorPrint("\n修改成功:\n", lightpurple);
	saveFile(L);

	//展示信息
	viewOneInfo(student);//输出操作信息

	return;

}

//查询学生信息
void QueryStudentInfo(Node *L)
{
	system("cls");
	int choice = 0;
	int id;
	int a[5] = {0};
	char name[50];
	Node *student;
	printf("按学号查询----- 1\n");
	printf("按姓名查询----- 2\n");
	while (1)
	{
		colorPrint("请输入查询方式：", pink);
		int ret = scanf("%d", &choice);
		fflush(stdin);
		if (ret == 1 && (choice == 1 || choice == 2))
		{
			break;
		}
		a[0]++;
		if(tooManyInputError(a[0]))return;
	}

	if (choice == 1)
	{
		colorPrint("请输入要查询的学号：", lightyellow);
		while (1)
		{
			int ret = scanf("%d", &id);
			fflush(stdin);
			if (ret == 1)
				break;
			a[1]++;
			if(tooManyInputError(a[1]>3))return;
		}

		student = queryStudentInfoById(id, L);
	}
	else if (choice == 2)
	{
		colorPrint("请输入要查询的姓名：", lightyellow);
		scanf("%s", name);

		student = queryStudentInfoByName(name, L);
	}

	if (student == NULL)
	{
		colorPrint("\n查无此人！\n", red);
		return;
	}
	else
	{
		student = student->next;
		colorPrint("此人信息如下：\n", darkgreen);
		viewOneInfo(student);//输出操作信息

	}
	return;

}

//输出学生信息
void ViewStudentInfo(Node *L)
{
	// system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//学生成绩从高到低排序
	sortStudentScore(L);

	Node *p = L->next;
	printf(" _______________________________________________________________\n");
	colorPrint("|名次   |学号   |姓名   |性别   |语文   |数学   |英语   |总分   |",green);
	printf("\n _______________________________________________________________\n");
	if (p != NULL)
	{
		int f=0,k=0;
		while (p != NULL)
		{
			k++;
			if (!f)
			{
				SetConsoleTextAttribute(hConsole, purple);
			} //高亮总分第一名

			printf("|第%d名\t|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", k, p->id, p->name, p->sex, p->cs, p->ma, p->en, p->sum);

			if (!f)
			{
				SetConsoleTextAttribute(hConsole, 7);
				f++;
			} //还原颜色
			printf(" _______________________________________________________________\n");
			p = p->next;
		}
	}
	viewAverageScores(L);//输出每科平均分
	viewHighestScores(L);//输出单科最高分

}



