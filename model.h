#pragma once

#define darkblue 1
#define darkgreen 2
#define greyblue 3
#define red 4
#define purple 5
#define yellow 6
#define white 7
#define grey 8
#define blue 9
#define green 10
#define lightblue 11
#define pink 12
#define lightpurple 13
#define lightyellow 14

typedef struct Node
{
	int id;			//学号
	char name[50];	//姓名
	char sex[10];	//性别
	int cs, ma, en; //语数英
	int sum;		//总分

	struct Node *next; //链表
} Node;


