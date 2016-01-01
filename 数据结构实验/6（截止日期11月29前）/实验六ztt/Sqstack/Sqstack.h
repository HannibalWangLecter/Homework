#include <stdio.h>
#include <math.h>
#include <malloc.h>

#define MAXSIZE 100
#define OK 1

typedef struct//����ջ�Ķ���
{
	double *base;    //ջ��ָ��
	double *top;     //ջ��ָ��
	int stacksize;      //ջ�Ŀ����������
}Sqstack1;

typedef struct//�ַ�ջ�Ķ���
{
	char *base;    //ջ��ָ��
	char *top;     //ջ��ָ��
	int stacksize;      //ջ�Ŀ����������
}Sqstack2;

int InitStack(Sqstack1 &S);     //����ջ�ĳ�ʼ��
int Push(Sqstack1 &S,double e);     //��ջ
int Pop(Sqstack1 &S,double &e);     //��ջ
double GetTop(Sqstack1 S);     //ȡջ��Ԫ��

int InitStack(Sqstack2 &S);     //�ַ�ջ�ĳ�ʼ��
int Push(Sqstack2 &S,char e);     //��ջ
int Pop(Sqstack2 &S,char &e);     //��ջ
char GetTop(Sqstack2 S);     //ȡջ��Ԫ��