#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define queuesize 5

typedef struct //����ṹ�� 
{
	char name[20];         //����һ������Ϊ20���ַ�����������ʾ����
	char sex;               //����һ��char����sex��������ʾ�Ա�,�涨m��ʾ���ԣ�f ��ʾŮ��  

}person_type;

typedef struct //����ѭ�����нṹ����� 
{
	person_type *qBase;   	 //����ռ��ַ
	int front;               //ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;                //βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}cir_queue;

void init_queue(cir_queue *q) //��ʼ��ѭ������
{
	q->qBase = (person_type *)malloc(sizeof(person_type)*queuesize);
	//��̬��������ռ��ַ
	if (!q->qBase)    //����ʧ�ܣ��˳�����
	{
		printf("��̬����ʧ�ܣ�������ֹ��");
		exit(-1);
	}
	q->front = q->rear = 0;

}
/*
void traverse_queue(cir_queue *q) 	//�������ѭ������Ԫ��
{
int i=q->front ;
while(i != q->rear )//��ͷָ����βָ�����ʱ����whileѭ��
{
printf("%s\n",q->qBase[i].name );//���Ԫ�ص�����
i=(i+1)%queuesize;               //������������
}
}
*/
bool full_queue(cir_queue *q)   //�ж�ѭ�������Ƿ�Ϊ��
{//��βָ�����һ��λ�õ���ͷָ��ʱ������Ϊ��
 // Ϊ������true�����򷵻�false
	if ((q->rear + 1) % queuesize == q->front)
		return true;
	else
		return false;
}
bool empty_queue(cir_queue *q)//�ж�ѭ�������Ƿ�Ϊ��
{//��ͷָ��λ�õ���βָ��ʱ��ѭ������Ϊ�գ�
 //Ϊ�շ���true�����򷵻�false
	if (q->front == q->rear)
		return true;
	else
		return false;
}
void en_queue(cir_queue *q, person_type p)//���Ӻ�����ʹp�������
{

	if (full_queue(q))//�ж��Ƿ�Ϊ��
	{
		printf("�����������޷�ʵ�ֽ��Ӳ�����������ֹ��");
		exit(-1);
	}
	else             //�������в���
	{
		q->qBase[q->rear] = p;
		q->rear = (q->rear + 1) % queuesize; //βָ��ָ����һ��λ��
	}
}
person_type de_queue(cir_queue *q)//���Ӻ�������p���س���ֵ
{
	person_type p;
	if (empty_queue(q))//�ж��Ƿ�Ϊ��
	{
		printf("����Ϊ�գ��޷�ʵ�ֳ��Ӳ�����������ֹ��");
		exit(-1);
	}
	else   //��Ϊ�ս��в���
	{
		p = q->qBase[q->front];
		q->front = (q->front + 1) % queuesize;
		return p;
	}
}
int length_queue(cir_queue *q)//��ѭ������Ԫ�ظ���
{
	return q->rear - q->front; //βָ��λ�ü�ȥͷָ��λ�ü���
}
person_type queue_front(cir_queue *q)//���ʶ�ͷԪ�أ�������
{
	if (empty_queue(q))//�ж��Ƿ�Ϊ��
	{
		printf("����Ϊ�գ�����ʧ�ܣ�");
		exit(-1);
	}
	return q->qBase[q->front];
}
void dancepartners(cir_queue femaledancer, cir_queue maledancer, int lun)//�����Ժ��� 
{
	int m = length_queue(&femaledancer);   //����Ů������
	int n = length_queue(&maledancer);     //�����ж�����
	for (int j = 1; j <= lun; ++j)              //forѭ����ʾ�����е��������
	{//ͨ������Ů�������ıȽϣ�����һ�²���
		if (m>n)// Ů�����������жӣ�Ů����ʣ���Ա
		{
			person_type p;
			person_type q;
			person_type s;
			printf("------------------------");
			printf("��%d����������\n", j);
			for (int i = 1; i <= n; ++i) //forѭ��ʵ����Բ���
			{
				p = de_queue(&maledancer);
				q = de_queue(&femaledancer); //���ӵ���Ů���

				printf("��:%s", p.name);
				printf("��Ů:%s��Գɹ�\n", q.name);//���������

				en_queue(&maledancer, p);
				en_queue(&femaledancer, q); //�����ӵ���Ů������½���
			}
			//���Ů��ʣ���Ա���,���������һ�����ȳ����Ķ�Ա����
			printf("Ů���л���%d�����ڵȴ�!\n", m - n);
			s = queue_front(&femaledancer); 
				printf("Ů���е�һ���ȴ����ǣ�%s\n", s.name);
		}
		else if (m<n) //�ж���������Ů�ӣ��ж���ʣ���Ա
		{
			person_type p;
			person_type q;
			person_type s;
			printf("------------------------");
			printf("��%d����������\n", j);
			for (int i = 1; i <= m; ++i)
			{
				p = de_queue(&maledancer);
				q = de_queue(&femaledancer);//���ӵ���Ů���

				printf("��:%s", p.name);
				printf("��Ů:%s��Գɹ�\n", q.name);//���������

				en_queue(&maledancer, p);
				en_queue(&femaledancer, q);	//�����ӵ���Ů������½���			   	    		 
			}
			//����ж�ʣ���Ա���,���������һ�����ȳ����Ķ�Ա����
			printf("�ж��л���%d�����ڵȴ�!\n", n - m);
			s = queue_front(&maledancer);
			printf("�ж��е�һ���ȴ����ǣ�%s\n", s.name);

		}
		else //��Ů��������ȣ�û��ʣ���Ա
		{
			person_type p;
			person_type q;
//			person_type s;
			printf("------------------------");
			printf("��%d����������\n", j);
			for (int i = 1; i <= m; ++i)
			{
				p = de_queue(&maledancer);
				q = de_queue(&femaledancer); //���ӵ���Ů���

				printf("��:%s", p.name);
				printf("��Ů:%s��Գɹ�\n", q.name);//���������

				en_queue(&maledancer, p);
				en_queue(&femaledancer, q);//�����ӵ���Ů������½���
			}
			printf("û����ʣ��!\n");
		}
	}
}
void main()
{
	person_type p, dancers[queuesize];
	//����������Ů���ߵ���Ϣ�������������Ա�
	int i, num;
	printf("������Ůdancer��������:\n");
	scanf_s("%d", &num);
	printf("�����������Ա���m��ʾ���ԣ���f��ʾŮ�ԣ�����: \nzhangsan\nm\n");
	for (i = 0; i<num; i++)
	{
		scanf_s("%s", &dancers[i].name);
		getchar();
		scanf_s("%c", &dancers[i].sex);
		if (dancers[i].sex != 'f'&&dancers[i].sex != 'm')//�ж�������Ϣ�Ƿ�Ϸ� 
			printf("��%d���˵���Ϣ����,����������", (i--) + 1);
	}
	cir_queue maledancer, femaledancer;//��������ѭ�����нṹ�� 
	init_queue(&maledancer);//����init_queue()�����ÿն���maledancer��ʾ�ж� 
	init_queue(&femaledancer);//����init_queue()�����ÿն���femaledancer��ʾŮ�� 
	for (i = 0; i<num; i++)
	{
		p = dancers[i];//�ṹ�����帳ֵ
		if (p.sex == 'f')//Ů�Ľ�����femaledancer
		{
			en_queue(&femaledancer, p);
			printf("%s��Ů��\n", p.name);
		}
		else//�еĽ�����maledancer 
		{
			en_queue(&maledancer, p);
			printf("%s���ж�\n", p.name);
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
	printf("��%d����������\n",j);
	for(int i =1;i<=m;++i )
	{
	p=de_queue(&maledancer);
	q=de_queue(&femaledancer);
	printf("��:%s",p.name);
	printf("��Ů:%s��Գɹ�\n",q.name);
	en_queue(&maledancer,p);
	en_queue(&femaledancer,q);
	}
	printf("�ж��л���%d�����ڵȴ�!\n",n-m);
	s=queue_front(&maledancer);
	printf("�ж��е�һ���ȴ����ǣ�%s\n",s.name);
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
	printf("������Ҫ���е�������\n");
	scanf_s("%d", &n);
	dancepartners(femaledancer, maledancer, n);
	//getchar(); 

}
