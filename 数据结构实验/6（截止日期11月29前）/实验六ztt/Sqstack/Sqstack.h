#include <stdio.h>
#include <math.h>
#include <malloc.h>

#define MAXSIZE 100
#define OK 1

typedef struct//数字栈的定义
{
	double *base;    //栈底指针
	double *top;     //栈顶指针
	int stacksize;      //栈的可用最大容量
}Sqstack1;

typedef struct//字符栈的定义
{
	char *base;    //栈底指针
	char *top;     //栈顶指针
	int stacksize;      //栈的可用最大容量
}Sqstack2;

int InitStack(Sqstack1 &S);     //数字栈的初始化
int Push(Sqstack1 &S,double e);     //入栈
int Pop(Sqstack1 &S,double &e);     //出栈
double GetTop(Sqstack1 S);     //取栈顶元素

int InitStack(Sqstack2 &S);     //字符栈的初始化
int Push(Sqstack2 &S,char e);     //入栈
int Pop(Sqstack2 &S,char &e);     //出栈
char GetTop(Sqstack2 S);     //取栈顶元素