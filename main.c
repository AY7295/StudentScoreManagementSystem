#include "model.h"
#include "util.h"
#include "handler.h"

Node List; //全局链表

int main()
{
	load();//加载界面
	readFile(&List);
	while (1)
	{
		//主界面
		master();
		//选择功能
		int choice = selectFunc();
		//主要功能
		system("cls");
		switch (choice)
		{
		case 1: //增加学生信息
			AddStudentInfo();
			break;
		case 2: //删除学生信息
			DeleteStudentInfo(&List);
			break;
		case 3: //修改学生信息
			UpdateStudentInfo(&List);
			break;
		case 4: //查询学生信息
			QueryStudentInfo(&List);
			break;
		case 5: //输出学生信息
			ViewStudentInfo(&List);
			break;
		case 6://帮助
			help();
			break;
		case 7://关于
			regardings();
			break;
		case 0: //退出程序
			goodBye();
			break;
		}
		printf("\n");
		system("pause");
	}

	return 0;
}


