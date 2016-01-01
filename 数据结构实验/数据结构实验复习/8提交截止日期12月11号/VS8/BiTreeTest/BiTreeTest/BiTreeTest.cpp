// BiTreeTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stack>
#include <iomanip>


const int Max = 100;
using namespace std;
class Node
{
public:
	char ch[Max];      //���ǵ���ֵ��ʱ������λ��������ʹ���ַ�������
	Node* lChild;
	Node* rChild;
	Node()
	{
		strcpy_s(ch, "");
		lChild = rChild = NULL;
	}
	~Node()
	{
		if (lChild != NULL) {
			delete lChild;
		}
		if (rChild != NULL) {
			delete rChild;
		}
	}
};
static int digit = 0;
static char oriArray[Max];     //����ԭʼ����׺���ʽ
static char str[2 * Max];   //�����������������ַ�����Ϊ���ʽ��ֵ�ṩ����
static int k = 0;
char getOp(Node *temp);     //tempָ�뱣��ÿ����㣬���ص��������
Node* crtTree(Node* root);   //��������ָ�룬���ظ����ָ��
void output(Node *root);       //��ô������ַ���
bool isError(char);                //�ж��ַ��Ƿ�������
void deal();                       //���ַ�������д���
double value(string);         // �����׺���ʽ���õ�������

int main()
{
	Node* root = NULL;
	cout << "������׺���ʽ��";
	cin.getline(oriArray, 40);
	deal();
	root = crtTree(root);
	cout << "�����׺���ʽ��";
	output(root);
	cout << str << endl;
	cout << "�����׺���ʽ��ֵ��";
	if (value(str) != 0) {
		cout << fixed << setprecision(2) << value(str) << endl;
	}
	else {
		cout << "A Wrong Input!" << endl;
	}
	system("pause");
		return 0;
}
//�������ַ�����һ����㣬�����������ַ��ĺ�һ������
char getOp(Node *temp)
{
	int i = 0;
	if (isError(oriArray[digit])) {
		exit(0);
	}
	while (oriArray[digit] <= '9' && oriArray[digit] >= '0' || oriArray[digit] == '.') {
		temp->ch[i] = oriArray[digit];
		i++;
		digit++;
	}
	temp->ch[i] = '\0';
	digit++;
	return oriArray[digit - 1];
}
//��������ָ�룬���ظ����ָ��
Node* crtTree(Node* root)
{
	Node *p, *q;
	char op;
	if (root == NULL) {
		root = new Node;
		p = new Node;
	}
	op = getOp(root);
	while (op != '=') {
		q = new Node;
		q->ch[0] = op;
		q->ch[1] = '\0';
		switch (op) {
		case '+':
		case '-':
			q->lChild = root;
			root = q;
			p = new Node;
			op = getOp(p);
			root->rChild = p;
			break;
		case '*':
		case  '/':
			if (root->ch[0] == '+' || root->ch[0] == '-') {
				p = new Node;
				strcpy_s(p->ch, root->ch);
				p->lChild = root;
				p->rChild = q;
				op = getOp(root);
				root = p;
			}
			else {
				q->lChild = root;
				root = q;
				p = new Node;
				op = getOp(p);
				root->rChild = p;
			}
			break;
		case '(':
			p = root;
			while (p->rChild) {
				p = p->rChild;
			}
			if (p->lChild == NULL) {
				p->lChild = crtTree(p->lChild);  //�ݹ鴴���������ָ��
				op = oriArray[digit];
				digit++;
				break;
			}
			else {
				p->rChild = crtTree(p->rChild); //�ݹ鴴���������ָ��
				op = oriArray[digit];
				digit++;
				break;
			}
		case ')':
			return root;
		}
	}
	return root;
}
//�������㣬�������,��ֵ����һ���ַ����飨��Ҫ��Ϊ�˸�����ļ�����ʽֵ�ṩ���㣩
void output(Node *root)
{
	int n;
	if (root) {
		output(root->lChild);
		output(root->rChild);
		n = 0;
		while (root->ch[n] != '\0') {
			str[k++] = root->ch[n++];
		}
		str[k++] = ' ';
	}
}
bool isError(char ch)    //�ж�ÿ���ַ��Ƿ��д�
{
	if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && !(ch <= '9' && ch >= '0') && ch != '.' && ch != '(' && ch != ')') {
		cout << "�ַ�����!" << endl;
		return true;
	}
	return false;
}
void deal()       //���ַ�������д���
{
	int i = 0, n = 0;
	while (oriArray[i]) {
		if (oriArray[i] == ' ' || oriArray[i] == '=') {
			i++;
		}
		oriArray[n++] = oriArray[i++];
	}
	oriArray[n++] = '=';
	oriArray[n] = '\0';
}
double value(string s2)            // �����׺���ʽ���õ�������
{
	stack < double> s;
	double x, y;
	unsigned int i = 0;
	while (i <  s2.length()) {
		if (s2[i] == ' ') {
			i++;
		}
		switch (s2[i]) {
		case '+':
			if (s.size() >= 2) {
				x = s.top();
				s.pop();
				x += s.top();
				s.pop();
				i++;
				break;
			}
			else {
				return 0;
			}
		case '-':
			if (s.size() >= 2) {
				x = s.top();
				s.pop();
				x = s.top() - x;
				s.pop();
				i++;
				break;
			}
			else {
				return 0;
			}
		case '*':
			if (s.size() >= 2) {
				x = s.top();
				s.pop();
				x *= s.top();
				s.pop();
				i++;
				break;
			}
			else {
				return 0;
			}
		case '/':
			if (s.size() >= 2) {
				if (s.top() == 0) {
					return 0;
				}
				else {
					x = s.top();
					s.pop();
					x = s.top() / x;
					s.pop();
					i++;
					break;
				}
			}
			else {
				return 0;
			}
		default:
			x = 0;
			while ('0' <= s2[i] && s2[i] <= '9') {
				x = x * 10 + s2[i] - '0';
				i++;
			}
			if (s2[i] == '.') {
				double k = 10.0;
				y = 0;
				i++;
				while ('0' <= s2[i] && s2[i] <= '9') {
					y += ((s2[i] - '0') / k);
					i++;
					k *= 10;
				}
				x += y;
			}
			break;
		}
		if (x != 0) {
			s.push(x);
		}
	}
	if (s.size() == 1) {
		return s.top();
	}
	else {
		return 0;
	}
}


