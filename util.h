#pragma once

#include <stdio.h>
#include <windows.h>
#include "model.h"
#include "func.h"


void colorPrint(char a[], int k)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hConsole, k);
	printf("%s", a);
	SetConsoleTextAttribute(hConsole, 7); //还原颜色
}


void load()
{
	printf("欢迎使用\n");
	colorPrint("StudentScoreManagementSystem",green);printf("\n");
	colorPrint("version：1.0",greyblue);printf("\n");
	colorPrint("copyright@AY7295，任何形式的借阅和引用请标明出处",red);printf("\n");
	int i;
	char loadstring[] = {"即将进入学生管理系统..."};
	//断点输出
	for (i = 0; i < strlen(loadstring); i++)
	{
		printf("%c", loadstring[i]);
		Sleep(80);
	}
	Sleep(200);
}

//主菜单界面
void master()
{
	system("cls");
	colorPrint("*************************************\n", green);
	printf("**	             	           **\n");

	printf("**");
	colorPrint("	  学生成绩管理系统    	   ", blue);
	printf("**\n");

	printf("**	             	           **\n");
	printf("**	  增加学生信息 ---1	   **\n");
	printf("**	  删除学生信息 ---2	   **\n");
	printf("**	  修改学生信息 ---3	   **\n");
	printf("**	  查询学生信息 ---4	   **\n");
	printf("**	  输出学生信息 ---5	   **\n");
	printf("**	  管理系统帮助 ---6	   **\n");
	printf("**	  管理系统信息 ---7	   **\n");
	printf("**	  退出管理系统 ---0	   **\n");
	printf("**	             	           **\n");
	colorPrint("*************************************\n\n", green);
	colorPrint("请输入对应的功能键（数字）: ", lightblue);

	
}

//选择功能键
int selectFunc(){
	int  choice = 0 , a=0 ;
		while (1)
		{
			int ret = scanf("%d", &choice);
			fflush(stdin);

			if ((ret == 1 && choice <= 7 && choice >= 0))
			{
				break;
			}

			a++;

			if (tooManyInputError(a))
				exit(1);;
			
			colorPrint("!!请重新输入：", red);
		}
	return choice;
}

//退出程序
void goodBye()
{
	system("cls");
	colorPrint("\n\n~欢迎下次使用~\n\n",yellow);
	exit(0); //结束程序
}


void viewOneInfo(Node *student){

	printf("________________________________________________________\n");
	printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分\t|\n");
	printf("________________________________________________________\n");
	printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n", student->id, student->name, student->sex, student->cs, student->ma, student->en, student->sum);
	printf("________________________________________________________\n");
}

//单科最高分
void viewHighestScores(Node *L){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	colorPrint("\n单科最高分:\n\n", green);

	Node *P0 = queryStudentInfoById(findMaxScoreID(L, 0), L)->next;
	SetConsoleTextAttribute(hConsole, blue);
	printf("语文分数最高：%d（%s）\n", P0->cs, P0->name);

	Node *P1 = queryStudentInfoById(findMaxScoreID(L, 1), L)->next;
	SetConsoleTextAttribute(hConsole, lightblue);
	printf("数学分数最高：%d（%s）\n", P1->ma, P1->name);
	
	Node *P2 = queryStudentInfoById(findMaxScoreID(L, 2), L)->next;
	SetConsoleTextAttribute(hConsole, yellow);
	printf("英语分数最高: %d（%s）\n", P2->en, P2->name);


	SetConsoleTextAttribute(hConsole, 7); //还原颜色
}

void viewAverageScores(Node *L){
	colorPrint("\n平均分：",green);
	colorPrint("\n\n总平均分：",pink);printf("%.3lf",averageScore(L,3));
	colorPrint("\n语文平均分：",pink);printf("%.3lf",averageScore(L,0));
	colorPrint("\n数学平均分：",pink);printf("%.3lf",averageScore(L,1));
	colorPrint("\n英语平均分：",pink);printf("%.3lf\n\n",averageScore(L,2));

}


//错误输入次数过多
int tooManyInputError (int a){
	if (a>2)
	{
		colorPrint("\n ！！输入错误次数太多 ！！\n", red);
	}
	return a>2;
}

void help(){
	colorPrint("\n  功能：",darkgreen);
	colorPrint("\n\t添加学生信息：",pink);colorPrint("逐条增加学生学号、姓名、性别、语数英成绩",yellow);
	colorPrint("\n\t删除学生信息：",pink);colorPrint("根据学号删除学生信息",yellow);
	colorPrint("\n\t修改学生信息：",pink);colorPrint("根据学号修改学生信息",yellow);
	colorPrint("\n\t查询学生信息：",pink);colorPrint("可以根据学生学号或者姓名查询",yellow);
	colorPrint("\n\t输出学生信息：",pink);colorPrint("输出所有学生信息并以总成绩排名，还有各科最高分和平均分\n\n",yellow);

}

void regardings(){
	colorPrint("\n\n程序：    ",greyblue);colorPrint("StudentScoreManagementSystem\n",green);
	colorPrint("version： ",greyblue);colorPrint("1.0\n",green);
	colorPrint("开发时间：",greyblue);colorPrint("2021.12.22-2022.1.6\n",green);
	colorPrint("开发者：  ",greyblue);colorPrint("AY7295\n\n",green);
}





