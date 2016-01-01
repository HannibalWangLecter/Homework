#include<string.h>
#include<ctype.h>
#include<malloc.h> 
#include<limits.h>
#include<stdio.h> 
#include<stdlib.h>
#include<math.h> 
#include<process.h> //���ų����Ķ���

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define QVERFLOW -2 //�޸ı�����������

typedef int Status; 
typedef int Boolean; 

typedef struct 
{
	char name[20];
	int sex;
}Person;

#define MAXSIZE 100
typedef struct 
{
    Person *base;
	int front;
	int rear;
}SqQueue;


Status InitQueue(SqQueue &Q);
Status QueueEmpty(SqQueue Q);
Status EnQueue(SqQueue &Q,Person e);
Status DeQueue(SqQueue &Q,Person &e);
Person GetHead(SqQueue Q);



