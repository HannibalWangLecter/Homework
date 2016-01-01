#include "other.h"
#include "Sqstack.h"

int In(char c)     //�ж��ַ��Ƿ�Ϊ���������
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')' || c=='#')
		return 1;
	else
		return 0;
}

char Precede(char op1,char op2)
{  
    //�ж�op1��op2���ȼ��ĸߵͣ�����'>','<','='
	switch(op1)
	{
	case '+':
		switch(op2)
		{
		case '*':
		case '/':
		case '(':
		case '^':return '<';
			break;
		default:return '>';
			break;
		}
		break;
	case '-':
		switch(op2)
		{
		case '*':
		case '/':
		case '(':
		case '^':return '<';
			break;
		default:return '>';
			break;
		}
		break;
	case '*':
		switch(op2)
		{
		case '(':
		case '^':return '<';
			break;
		default:return '>';
			break;
		}
		break;
	case '/':
		switch(op2)
		{
		case '(':
		case '^':return '<';
			break;
		default:return '>';
			break;
		}
		break;
	case '(':
		switch(op2)
		{
		case ')':return '=';
			break;
		default:return '<';
			break;
		}
		break;
	case ')':
		switch(op2)
		{
		default:return '>';
			break;
		}
		break;
	case '^':
		switch(op2)
		{
		case '(':return '<';
			break;
		default:return '>';
			break;
		}
		break;
	case '#':
		switch(op2)
		{
		case '#':return '=';
			break;
		default:return '<';
			break;
		}
		break;
	default:return '<';
		break;
	}
}

double Operate(double a,char r,double b)    //���ж�Ԫ����
{
	double sum;
	switch(r)
	{
	case '+':sum=a+b;break;
	case '-':sum=a-b;break;
	case '*':sum=a*b;break;
	case '/':if(b==0)
				 return 0;
		else
			sum=a/b;
		break;
	case '^':sum=pow(a,b);break;
	}
	return sum;
}

double EvaluateExpression()     //���ʽ����������㷨
{
	Sqstack1 OPND;  //��������ջOPND
	Sqstack2 OPTR;  //�����ַ�ջOPTR
	char ch,ch1,theta,e;
	int i,t=0,t1;
	double sum,s,a,b,count;
	InitStack(OPND);  //��ʼ��OPND
	InitStack(OPTR);  //��ʼ��OPTR
	Push(OPTR,'#');  //�����ʽ��ʼ����#��ѹ��OPTRջ
	scanf("%c",&ch);
	if(ch=='-') //��һ����Ϊ����
	{
		t=1;  //��Ǹ���
		scanf("%c",&ch);
	}
	while(ch!='#' || GetTop(OPTR)!='#')  //���ʽû��ɨ����ϻ�OPTR��ջ��Ԫ�ز�Ϊ��#��
	{
		if(!In(ch))    //������������ʱ�ͽ�OPNDջ
		{
			//��������
			sum=0;
			while(ch!='.' && !In(ch))
			{
				sum=sum*10+ch-'0';
				scanf("%c",&ch);
			}
			//С������
			if(ch=='.')
			{
				scanf("%c",&ch);
				s=0,i=1;
				while(!In(ch))
				{
					s=s+(ch-'0')*pow(0.1,i);
					i++;
					scanf("%c",&ch);
				}
				sum=sum+s;
			}
			if(t==1)  //���ű��sumȡ���෴��
				sum=0-sum;
			t=0;
			Push(OPND,sum);  //������ջ
		}
		else
		{
			switch(Precede(GetTop(OPTR),ch))  //�Ƚ�OPTR��ջ��Ԫ�غ�ch�����ȼ�
			{
			case '<':
				Push(OPTR,ch);   //��ǰ�ַ�chѹ��OPTRջ��������һ�ַ�ch
				ch1=ch;
				scanf("%c",&ch);
				if(ch1=='(' && ch=='-')  //�������ջ��Ϊ"("�Ҷ�����ַ�Ϊ"-"�����"-"Ϊ����
				{
					//printf("���t=%d\n",t);
					t=1;
					//printf("��ֵ��t=%d\n",t);
					scanf("%c",&ch);
					//printf("ִ����t=1�������ַ�Ϊ%c\n",ch);
				}
				break;
			case '>':
				Pop(OPTR,theta); //����OPTRջ���������
				Pop(OPND,a);  //��ջ����1
				Pop(OPND,b);  //��ջ����2
				count=Operate(b,theta,a);  //����1����2��������
				Push(OPND,count);  //��count���뵽OPNDջ��
				break;
			case '=':   //OPTR��ջ��Ԫ����"("��ch��")"
				Pop(OPTR,e);  //����OPTRջ����"("
				scanf("%c",&ch);  //������һ�ַ�ch
				break;
			}  //switch
		}  //else
	}  //while
	//���������
	return GetTop(OPND);
}