#include "Queue.h"

void main()
{
	Person dancer[MAXSIZE];
	int number;
	int i;
	Person p;
	SqQueue Mdancers,Fdancers;
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	printf("请输入跳舞的人数:");
	scanf("%d",&number);
	for(i=0;i<number;i++)
	{   
		p=dancer[i];
		printf("请输入第%d位舞者的姓名:",i+1);
		scanf("%s",p.name  );
		printf("请确认舞者的性别(0.女1.男):");
		scanf("%d",&p.sex );
		if(p.sex==0)
			EnQueue(Fdancers,p);
		else
			EnQueue(Mdancers,p);
	}
	printf("the dancing persons are:\n");
	while (QueueEmpty(Fdancers)&&QueueEmpty(Mdancers))
	{
		DeQueue(Fdancers,p);
		printf("%s\n",p.name);
        DeQueue(Mdancers,p);
		printf("%s\n",p.name);
		printf("\n");
	}
	if(QueueEmpty(Fdancers))
	{
		p=GetHead(Fdancers);
		printf("next danse,the first woman to get the partner is:%s",p.name);
	}
	else if(QueueEmpty(Mdancers))
	{
		p=GetHead(Mdancers);
		printf("next danse,the first man to get the partner is:%s",p.name);
	}
	else
		printf("匹配恰好完成!");


}