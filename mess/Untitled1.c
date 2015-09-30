/*标准头文件以及一些符号常量的定义等*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100	 //顺序表可能达到的最大长度

typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。


typedef struct
{
	//char name[10]; //姓名
	string name;
	string id;
	//char id[10]; //学号
	double score; //成绩
}student;
