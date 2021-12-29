#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "model.h"

// 文件输入
int readFile(Node *L)
{
	FILE *fpr = fopen("studentInfo.txt", "r");
	Node student;
	Node *s;
	Node *t = L;

	if (fpr == NULL)
	{
		colorPrint("文件打开失败", red);
		exit(1);
	}
	else
	{

		while (fscanf(fpr, "%d %s %s %d %d %d %d", &student.id, student.name, student.sex, &student.cs, &student.ma, &student.en, &student.sum) != EOF)
		{

			s = (Node *)malloc(sizeof(Node));

			*s = student;

			t->next = s;
			t = s;
			t->next = NULL;
		}
	}
	fclose(fpr); //关闭文件指针
	return 1;
}

//保存文件
int saveFile(Node *L)
{
	FILE *fpw = fopen("studentInfo.txt", "w");
	if (fpw == NULL)
	{
		colorPrint("保存失败",red);
		return 0;
	}

	Node *p = L->next;

	while (p != NULL)
	{

		fprintf(fpw, "%d %s %s %d %d %d %d\n", p->id, p->name, p->sex, p->cs, p->ma, p->en, p->sum);
		p = p->next;
	}
	fclose(fpw); //关闭文件指针
	return 1;
}




