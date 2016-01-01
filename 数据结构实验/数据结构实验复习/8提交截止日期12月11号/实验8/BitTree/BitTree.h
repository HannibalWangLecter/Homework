#include<stdio.h>
#include<malloc.h>
typedef struct lemontree
{
	char ch;
	struct lemontree *lchild, *rchild;
} tree;

tree *inittree();
void bianli(tree *t);