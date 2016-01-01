#include "other.h"
#include "Sqstack.h"

int In(char c)     //判断字符是否为操作运算符
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')' || c=='#')
		return 1;
	else
		return 0;
}

char Precede(char op1,char op2)
{  
    //判断op1和op2优先级的高低，返回'>','<','='
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

double Operate(double a,char r,double b)    //进行二元运算
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

double EvaluateExpression()     //表达式的算符优先算法
{
	Sqstack1 OPND;  //定义数字栈OPND
	Sqstack2 OPTR;  //定义字符栈OPTR
	char ch,ch1,theta,e;
	int i,t=0,t1;
	double sum,s,a,b,count;
	InitStack(OPND);  //初始化OPND
	InitStack(OPTR);  //初始化OPTR
	Push(OPTR,'#');  //将表达式起始符“#”压入OPTR栈
	scanf("%c",&ch);
	if(ch=='-') //第一个数为负数
	{
		t=1;  //标记负号
		scanf("%c",&ch);
	}
	while(ch!='#' || GetTop(OPTR)!='#')  //表达式没有扫描完毕或OPTR的栈顶元素不为“#”
	{
		if(!In(ch))    //当输入是数字时就进OPND栈
		{
			//整数部分
			sum=0;
			while(ch!='.' && !In(ch))
			{
				sum=sum*10+ch-'0';
				scanf("%c",&ch);
			}
			//小数部分
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
			if(t==1)  //负号标记sum取其相反数
				sum=0-sum;
			t=0;
			Push(OPND,sum);  //数字入栈
		}
		else
		{
			switch(Precede(GetTop(OPTR),ch))  //比较OPTR的栈顶元素和ch的优先级
			{
			case '<':
				Push(OPTR,ch);   //当前字符ch压入OPTR栈，读入下一字符ch
				ch1=ch;
				scanf("%c",&ch);
				if(ch1=='(' && ch=='-')  //如果刚入栈的为"("且读入的字符为"-"，则此"-"为负号
				{
					//printf("最初t=%d\n",t);
					t=1;
					//printf("赋值后t=%d\n",t);
					scanf("%c",&ch);
					//printf("执行完t=1后读入的字符为%c\n",ch);
				}
				break;
			case '>':
				Pop(OPTR,theta); //弹出OPTR栈顶的运算符
				Pop(OPND,a);  //出栈数字1
				Pop(OPND,b);  //出栈数字2
				count=Operate(b,theta,a);  //将数1与数2进行运算
				Push(OPND,count);  //将count存入到OPND栈中
				break;
			case '=':   //OPTR的栈顶元素是"("且ch是")"
				Pop(OPTR,e);  //弹出OPTR栈顶的"("
				scanf("%c",&ch);  //读入下一字符ch
				break;
			}  //switch
		}  //else
	}  //while
	//返回最后结果
	return GetTop(OPND);
}