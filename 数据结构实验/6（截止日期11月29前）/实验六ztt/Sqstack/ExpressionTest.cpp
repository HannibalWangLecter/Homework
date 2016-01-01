#include <stdio.h>
#include "other.h"
//#include "Sqstack.h"

void main()
{
	int i=1;
	while(i)
	{
		fflush(stdin);
		printf("请输入表达式(以#为结束):\n");
		printf("%lf\n",EvaluateExpression());
		printf("继续吗？继续--1  结束--0\n");
		scanf("%d",&i);
	}
}