#pragma once

#include <string.h>
#include "model.h"
#include "file.h"



//查找单科成绩最高的学号
int findMaxScoreID(Node *L, int code)
{
	// code 0:语文 1:数学 2:英语 
	Node *p = L->next;
	int maxs[3] = {-1, -1, -1};
	int ids[3] = {0};

	switch (code)
	{
	case 0:
		while (p != NULL)
		{
			if (p->cs > maxs[0])
			{
				maxs[0] = p->cs;
				ids[0] = p->id;
			}
			p = p->next;
		}
		break;
	case 1:
		while (p != NULL)
		{
			if (p->ma > maxs[1])
			{
				maxs[1] = p->ma;
				ids[1] = p->id;
			}
			p = p->next;
		}
		break;
	case 2:
		while (p != NULL)
		{
			if (p->en > maxs[2])
			{
				maxs[2] = p->en;
				ids[2] = p->id;
			}
			p = p->next;
		}
		break;
	}
	return ids[code];
}

//插入学生信息
void insertStudentInfo(Node *L, Node student)
{
	//头插法
	Node *h = L;
	Node *s = (Node *)malloc(sizeof(Node));
	*s = student;

	s->next = h->next;
	h->next = s;

	saveFile(L);
}

//删除学生信息
void deleteStudentInfo(Node *L)
{
	Node *s = L->next;

	L->next = s->next;
	s->next = NULL;

	free(s); //释放结点
}

//以总成绩排序
void sortStudentScore(Node *L)
{

	for (Node *p = L->next; p != NULL; p = p->next)
	{

		for (Node *q = p; q != NULL; q = q->next)
		{
			if (p->sum < q->sum)
			{
				//交换数据域
				Node t = *p;
				*p = *q;
				*q = t;
				// 调整指针指向
				t.next = p->next;
				p->next = q->next;
				q->next = t.next;
			}
		}
	}
}

//按学号进行查找
Node *queryStudentInfoById(int id, Node *L)
{

	Node *p = L;

	while (p->next != NULL)
	{

		if (p->next->id == id)
		{
			return p;
		}

		p = p->next;
	}

	return NULL;
}
//按姓名进行查找
Node *queryStudentInfoByName(char name[], Node *L)
{

	Node *p = L;

	while (p->next != NULL)
	{

		if (strcmp(name, p->next->name) == 0)
		{
			return p;
		}

		p = p->next;
	}

	return NULL;
}

double averageScore(Node *L,int code){
	// code 0:语文 1:数学 2:英语 3:总分
	Node *p = L->next;
	double a=0,b=0;

	switch (code)
	{
	case 0:
		while (p != NULL)
		{
			b++;
			a+=p->cs;
			p = p->next;
		}
		return a/b;
		break;
	case 1:
		while (p != NULL)
		{
			b++;
			a+=p->ma;
			p = p->next;
		}
		return a/b;
		break;
	case 2:
		while (p != NULL)
		{
			b++;
			a+=p->en;
			p = p->next;
		}
		return a/b;
		break;
	case 3:
		while (p != NULL)
		{
			b++;
			a+=p->sum;
			p = p->next;
		}
		return a/b;
		break;	
	}
	
}



