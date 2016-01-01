#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define queuesize 5

typedef struct //定义结构体 
{
	char name[20];         //定义一个长度为20的字符串，用来表示姓名
	char sex;               //定义一个char变量sex，用来表示性别,规定m表示男性，f 表示女性  

}person_type;

typedef struct //定义循环队列结构体队列 
{
	person_type *qBase;   	 //储存空间基址
	int front;               //头指针，若队列不空，指向队列头元素
	int rear;                //尾指针，若队列不空，指向队列尾元素的下一个位置
}cir_queue;

void init_queue(cir_queue *q) //初始化循环队列
{
	q->qBase = (person_type *)malloc(sizeof(person_type)*queuesize);
	//动态创建储存空间基址
	if (!q->qBase)    //创建失败，退出程序！
	{
		printf("动态创建失败，程序终止！");
		exit(-1);
	}
	q->front = q->rear = 0;

}
/*
void traverse_queue(cir_queue *q) 	//遍历输出循环队列元素
{
int i=q->front ;
while(i != q->rear )//当头指针与尾指针相等时结束while循环
{
printf("%s\n",q->qBase[i].name );//输出元素的名字
i=(i+1)%queuesize;               //解决假溢出问题
}
}
*/
bool full_queue(cir_queue *q)   //判断循环队列是否为满
{//当尾指针的下一个位置等于头指针时，队列为满
 // 为满返回true，否则返回false
	if ((q->rear + 1) % queuesize == q->front)
		return true;
	else
		return false;
}
bool empty_queue(cir_queue *q)//判断循环队列是否为空
{//当头指针位置等于尾指针时，循环队列为空，
 //为空返回true，否则返回false
	if (q->front == q->rear)
		return true;
	else
		return false;
}
void en_queue(cir_queue *q, person_type p)//进队函数，使p进入队列
{

	if (full_queue(q))//判断是否为满
	{
		printf("队列已满，无法实现进队操作，程序终止！");
		exit(-1);
	}
	else             //不满进行操作
	{
		q->qBase[q->rear] = p;
		q->rear = (q->rear + 1) % queuesize; //尾指针指向下一个位置
	}
}
person_type de_queue(cir_queue *q)//出队函数，用p返回出队值
{
	person_type p;
	if (empty_queue(q))//判断是否为空
	{
		printf("队列为空，无法实现出队操作，程序终止！");
		exit(-1);
	}
	else   //不为空进行操作
	{
		p = q->qBase[q->front];
		q->front = (q->front + 1) % queuesize;
		return p;
	}
}
int length_queue(cir_queue *q)//求循环队列元素个数
{
	return q->rear - q->front; //尾指针位置减去头指针位置即可
}
person_type queue_front(cir_queue *q)//访问队头元素，并返回
{
	if (empty_queue(q))//判断是否为空
	{
		printf("队列为空，操作失败！");
		exit(-1);
	}
	return q->qBase[q->front];
}
void dancepartners(cir_queue femaledancer, cir_queue maledancer, int lun)//舞伴配对函数 
{
	int m = length_queue(&femaledancer);   //计算女队人数
	int n = length_queue(&maledancer);     //计算男队人数
	for (int j = 1; j <= lun; ++j)              //for循环表示舞会进行的轮数情况
	{//通过对男女队人数的比较，进行一下操作
		if (m>n)// 女队人数多于男队，女队有剩余队员
		{
			person_type p;
			person_type q;
			person_type s;
			printf("------------------------");
			printf("第%d轮配对情况：\n", j);
			for (int i = 1; i <= n; ++i) //for循环实现配对操作
			{
				p = de_queue(&maledancer);
				q = de_queue(&femaledancer); //出队的男女舞伴

				printf("男:%s", p.name);
				printf("和女:%s配对成功\n", q.name);//输出配对情况

				en_queue(&maledancer, p);
				en_queue(&femaledancer, q); //将出队的男女舞伴重新进队
			}
			//输出女队剩余队员情况,并输出在下一轮首先出场的队员姓名
			printf("女队中还有%d个人在等待!\n", m - n);
			s = queue_front(&femaledancer); 
				printf("女队中第一个等待的是：%s\n", s.name);
		}
		else if (m<n) //男队人数多于女队，男队有剩余队员
		{
			person_type p;
			person_type q;
			person_type s;
			printf("------------------------");
			printf("第%d轮配对情况：\n", j);
			for (int i = 1; i <= m; ++i)
			{
				p = de_queue(&maledancer);
				q = de_queue(&femaledancer);//出队的男女舞伴

				printf("男:%s", p.name);
				printf("和女:%s配对成功\n", q.name);//输出配对情况

				en_queue(&maledancer, p);
				en_queue(&femaledancer, q);	//将出队的男女舞伴重新进队			   	    		 
			}
			//输出男队剩余队员情况,并输出在下一轮首先出场的队员姓名
			printf("男队中还有%d个人在等待!\n", n - m);
			s = queue_front(&maledancer);
			printf("男队中第一个等待的是：%s\n", s.name);

		}
		else //男女队人数相等，没有剩余队员
		{
			person_type p;
			person_type q;
//			person_type s;
			printf("------------------------");
			printf("第%d轮配对情况：\n", j);
			for (int i = 1; i <= m; ++i)
			{
				p = de_queue(&maledancer);
				q = de_queue(&femaledancer); //出队的男女舞伴

				printf("男:%s", p.name);
				printf("和女:%s配对成功\n", q.name);//输出配对情况

				en_queue(&maledancer, p);
				en_queue(&femaledancer, q);//将出队的男女舞伴重新进队
			}
			printf("没有人剩余!\n");
		}
	}
}
void main()
{
	person_type p, dancers[queuesize];
	//键盘输入男女舞者的信息，包括姓名，性别
	int i, num;
	printf("输入男女dancer的总人数:\n");
	scanf_s("%d", &num);
	printf("输入姓名和性别（用m表示男性，用f表示女性），如: \nzhangsan\nm\n");
	for (i = 0; i<num; i++)
	{
		scanf_s("%s", &dancers[i].name);
		getchar();
		scanf_s("%c", &dancers[i].sex);
		if (dancers[i].sex != 'f'&&dancers[i].sex != 'm')//判断输入信息是否合法 
			printf("第%d个人的信息有误,请重新输入", (i--) + 1);
	}
	cir_queue maledancer, femaledancer;//定义两个循环队列结构体 
	init_queue(&maledancer);//调用init_queue()函数置空队列maledancer表示男队 
	init_queue(&femaledancer);//调用init_queue()函数置空队列femaledancer表示女队 
	for (i = 0; i<num; i++)
	{
		p = dancers[i];//结构体整体赋值
		if (p.sex == 'f')//女的进队列femaledancer
		{
			en_queue(&femaledancer, p);
			printf("%s进女队\n", p.name);
		}
		else//男的进队列maledancer 
		{
			en_queue(&maledancer, p);
			printf("%s进男队\n", p.name);
		}
	}
	/*
	int j;
	int m = length_queue(&femaledancer);
	int n = length_queue(&maledancer);
	if(m<n)
	{
	person_type p;
	person_type q;
	person_type s;
	for(j=1;j<=7;++j)
	{
	printf("第%d轮配对情况：\n",j);
	for(int i =1;i<=m;++i )
	{
	p=de_queue(&maledancer);
	q=de_queue(&femaledancer);
	printf("男:%s",p.name);
	printf("和女:%s配对成功\n",q.name);
	en_queue(&maledancer,p);
	en_queue(&femaledancer,q);
	}
	printf("男队中还有%d个人在等待!\n",n-m);
	s=queue_front(&maledancer);
	printf("男队中第一个等待的是：%s\n",s.name);
	}
	}
	*/
	/*  int m =length_queue(&maledancer);
	printf("%d",m);
	traverse_queue(&maledancer);
	traverse_queue(&femaledancer);
	traverse_queue(&maledancer);
	*/
	int n;
	printf("请输入要进行的轮数：\n");
	scanf_s("%d", &n);
	dancepartners(femaledancer, maledancer, n);
	//getchar(); 

}
