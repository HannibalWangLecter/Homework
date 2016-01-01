#include "Queue.h"

Status InitQueue(SqQueue &Q)
{
	Q.base =new Person[MAXSIZE];
	if (!Q.base )
		exit(OVERFLOW);
	Q.front =Q.rear =0;
	return OK;
}

int QueueEmpty(SqQueue Q)
{
     if(Q.front ==Q.rear )
		 return 0;
	 else
		 return 1;
}

Status EnQueue(SqQueue &Q,Person e)
{
     if((Q.rear +1)%MAXSIZE==Q.front )
		 return ERROR;
	 Q.base[Q.rear ]=e;
	 Q.rear =(Q.rear +1)%MAXSIZE;
	 return OK;
}

Status DeQueue(SqQueue &Q,Person &e)
{
	if(Q.rear ==Q.front )
		return ERROR;
	e=Q.base [Q.front ];
	Q.front =(Q.front +1)%MAXSIZE;
	return OK;
}

Person GetHead(SqQueue Q)
{
	if(Q.front !=Q.rear )
		return Q.base [Q.front ];
}