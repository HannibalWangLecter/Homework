#include "Sqstack.h"

//数字栈
int InitStack(Sqstack1 &S)     //数字栈的初始化
{
	S.base=new double[MAXSIZE];     //为数字栈分配空间
	if(!S.base)     //分配失败
		return 0;
	S.top=S.base;     //top初始为base
	S.stacksize=MAXSIZE;     //数字栈的最大容量为MAXSIZE
	return OK;
}

int Push(Sqstack1 &S,double e)     //入栈
{
	if(S.top-S.base>=S.stacksize)     //栈满
		return 0;
	*S.top++=e;     //元素入栈，同时修改top的值
	return OK;
}

int Pop(Sqstack1 &S,double &e)     //出栈
{
	if(S.top==S.base)     //数字栈栈为空
		return -1;
	e=*--S.top;     //修改top的值并返回出栈元素
	return OK;
}

double GetTop(Sqstack1 S)     //取数字栈栈顶元素
{
	if(S.top!=S.base)     //栈不为空
		return *(S.top-1);     //返回数字栈栈顶元素，不修改top指针
}

//字符栈
int InitStack(Sqstack2 &S)     //字符栈的初始化
{
	S.base=new char[MAXSIZE];     //为字符栈分配空间
	if(!S.base)     //分配失败
		return 0;
	S.top=S.base;     //top初始为base
	S.stacksize=MAXSIZE;     //字符栈的最大容量为MAXSIZE
	return OK;
}

int Push(Sqstack2 &S,char e)     //入栈
{
	if(S.top-S.base>=S.stacksize)     //栈满，重新分配更大的空间
		return 0;
	*S.top++=e;     //元素入栈，同时修改top的值
	return OK;
}

int Pop(Sqstack2 &S,char &e)     //出栈
{
	if(S.top==S.base)     //字符栈栈为空
		return -1;
	e=*--S.top;     //修改top的值并返回出栈元素
	return OK;
}

char GetTop(Sqstack2 S)     //取字符栈栈顶元素
{
	if(S.top!=S.base)     //栈不为空
		return *(S.top-1);     //返回字符栈栈顶元素，不修改top指针
}