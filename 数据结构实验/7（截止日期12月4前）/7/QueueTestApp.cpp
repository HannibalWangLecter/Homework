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
	printf("���������������:");
	scanf("%d",&number);
	for(i=0;i<number;i++)
	{   
		p=dancer[i];
		printf("�������%dλ���ߵ�����:",i+1);
		scanf("%s",p.name  );
		printf("��ȷ�����ߵ��Ա�(0.Ů1.��):");
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
		printf("ƥ��ǡ�����!");


}