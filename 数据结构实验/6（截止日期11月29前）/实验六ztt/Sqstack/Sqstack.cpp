#include "Sqstack.h"

//����ջ
int InitStack(Sqstack1 &S)     //����ջ�ĳ�ʼ��
{
	S.base=new double[MAXSIZE];     //Ϊ����ջ����ռ�
	if(!S.base)     //����ʧ��
		return 0;
	S.top=S.base;     //top��ʼΪbase
	S.stacksize=MAXSIZE;     //����ջ���������ΪMAXSIZE
	return OK;
}

int Push(Sqstack1 &S,double e)     //��ջ
{
	if(S.top-S.base>=S.stacksize)     //ջ��
		return 0;
	*S.top++=e;     //Ԫ����ջ��ͬʱ�޸�top��ֵ
	return OK;
}

int Pop(Sqstack1 &S,double &e)     //��ջ
{
	if(S.top==S.base)     //����ջջΪ��
		return -1;
	e=*--S.top;     //�޸�top��ֵ�����س�ջԪ��
	return OK;
}

double GetTop(Sqstack1 S)     //ȡ����ջջ��Ԫ��
{
	if(S.top!=S.base)     //ջ��Ϊ��
		return *(S.top-1);     //��������ջջ��Ԫ�أ����޸�topָ��
}

//�ַ�ջ
int InitStack(Sqstack2 &S)     //�ַ�ջ�ĳ�ʼ��
{
	S.base=new char[MAXSIZE];     //Ϊ�ַ�ջ����ռ�
	if(!S.base)     //����ʧ��
		return 0;
	S.top=S.base;     //top��ʼΪbase
	S.stacksize=MAXSIZE;     //�ַ�ջ���������ΪMAXSIZE
	return OK;
}

int Push(Sqstack2 &S,char e)     //��ջ
{
	if(S.top-S.base>=S.stacksize)     //ջ�������·������Ŀռ�
		return 0;
	*S.top++=e;     //Ԫ����ջ��ͬʱ�޸�top��ֵ
	return OK;
}

int Pop(Sqstack2 &S,char &e)     //��ջ
{
	if(S.top==S.base)     //�ַ�ջջΪ��
		return -1;
	e=*--S.top;     //�޸�top��ֵ�����س�ջԪ��
	return OK;
}

char GetTop(Sqstack2 S)     //ȡ�ַ�ջջ��Ԫ��
{
	if(S.top!=S.base)     //ջ��Ϊ��
		return *(S.top-1);     //�����ַ�ջջ��Ԫ�أ����޸�topָ��
}