#include <stdio.h>
#include "other.h"
//#include "Sqstack.h"

void main()
{
	int i=1;
	while(i)
	{
		fflush(stdin);
		printf("��������ʽ(��#Ϊ����):\n");
		printf("%lf\n",EvaluateExpression());
		printf("�����𣿼���--1  ����--0\n");
		scanf("%d",&i);
	}
}