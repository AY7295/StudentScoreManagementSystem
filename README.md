# 前言
学生成绩管理系统：C语言程序设计期末大作业。

# 控制台版本开发过程整理

##### (文中尽介绍主要函数且都只有函数名，代码直接看文件)

#### **上传时间：** 

* 2021-12-29


## 开发环境

* 系统： win10 
* 工具:  VSCode

## 前置知识
涉及C语言知识
* 顺序结构
* 分支结构
* 循环结构
* 数组、字符串
* 函数
* 结构体、指针
* 链表
* 文件操作

## 功能分析
基础设想：先显示主菜单，通过输入数字选择对应的功能，包括有增加学生信息，删除学生信息，修改学生信息，查询学生信息以及退出程序功能。

## 主菜单界面实现
使用输出语句来实现界面。(util.h)
```c
//主菜单界面 
void welcome(){

}
```

## 功能框架搭建
先处理好整个功能框架，通过输入数字，进行分支判断，不同的数字代表不同的功能。(main.c)

``` c
int main(){

	
	return 0;
}
```


## 数据结构定义
围绕学生信息进行处理。信息包含，学号，姓名，性别，语文，数学，英语成绩，总分。将对应属性集合在一块，采用结构体方式进行数据操作。并使用链表的方式将数据进行串联。(model.h)

```c
typedef struct Node{
	int id;//学号
	char name[30];//姓名 
	char sex[10];//性别
	int cs;//语文
	int ma;//数学
	int en;//英语
	int sum;//总分
	

	struct Node *next;//指向下一个结点 

}node;
```




## 文件数据的读取
数据都要以文件的形式进行信息的操作。使用文件指针和相关函数,如下：(file.h)

```c
FILE *fpr=fopen("文件名","操作方式");
fscanf(fpr,"%d",&intValue);
```
操作方式：从文件中读取信息（r），信息写入文件（w）。

将读取的信息以链表的方式组织起来，可以用尾插法的方式插入数据。

``` c
// 尾插法 
t->next=s;//链表尾指针 的后一个结点指向新结点 
t=s;//更新尾结点 
t->next=NULL;//链表尾指针 的后一个结点指向NULL 
```
读取函数

```c
// 文件输入
int readFile(Node *L){
	
}
```

## 输出所有学生信息
所有学生信息的输出需要链表的遍历。(handler.h)

``` c
void ViewStudentInfo(node *L){
	 
}
```


## 增加学生信息

接下来是增加学生的信息，用头插法将链表结点进行插入。将学生信息的增加分成了两部分，一部分是界面的打印，一部分是底层数据的处理。


界面实现：(handler.h)

``` c
//增加学生信息
void AddStudentInfo(){

	 
}
```

功能实现:(func.h)

```c
void insertStudentInfo(node *L,node e){

}
```


## 文件数据的写入

这部分和文件的读取部分相似，思路是将整个链表内容存储到文件中。

使用fprintf()将文件信息进行存储。(func.h)

```c
void insertStudentInfo(node *L,node e){

}
```

再在学生信息的增加过程中添加文件数据的保存操作。(file.h)

```c
//保存文件
int saveFile(node *L){

}
```


## 学生信息查询

可以通过学号与姓名两个关键值进行信息的查找。因为是链表结构，为了方便之后的操作，逻辑函数会返回查找到的学生信息的前一个结点位置，这样的话也能在删除学生信息与修改学生信息中进行函数的复用了。

界面实现：(handler.h)

```c
//查询学生信息
void QueryStudentInfo(node *L){
	
	
}
```

逻辑实现：(func.h)

思路是遍历整个链表，逐一对关键信息进行比较。

按学号进行查找，找不到返回NULL，找到了返回前一个结点位置

```c
//按学号进行查找 
node * queryStudentInfoById(int id,node *L){
	
}
```

按姓名进行查找，找不到返回NULL，找到了返回前一个结点位置

```c
//按姓名进行查找 
node * queryStudentInfoByName(char name[],node *L){

}
```


## 学生信息修改

依旧是分成两部分，先输出界面。实现逻辑是这样的：先查到要查询的学生信息，在对信息修改，改完了再保存到文件中。

页面和实现部分：(handler.h)

```c
//修改学生信息
void UpdateStudentInfo(node *L){
	
}

```


## 学生信息删除

利用之前实现的查询信息的函数得到结点位置，之后再根据位置删除对应的结点，再将修改后的信息保存至文件中去。

页面部分(handler.h)

``` c
//删除学生信息
void DeleteStudentInfo(node *L){
		
 	
}
```

结点删除部分(func.h)

``` c
//删除学生信息
void deleteStudentInfo(node *pr){
 
	
}
```



## 结束界面

(util.h)

```c
//退出程序
void goodBye(){
	
}
```



# 彩色输出

(util.h)

```c
//彩色输出
void colorPrint(char a[], int k)

{

}
```

