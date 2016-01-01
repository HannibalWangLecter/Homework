#include "BitTree.h"
tree *inittree()
{
	tree *t;
	t=(tree *)malloc(sizeof(tree));
	scanf("%c",&t->ch);
	if (t->ch=='#')
	{
		t=NULL;
	return t;
	}
	else
	{
		t->lchild=inittree();
		t->rchild=inittree();
		return t;
	}
}

	void bianli(tree *t)

	{
		if (t!=NULL)
		{
			bianli(t->lchild);
			printf("%c",t->ch);
			bianli(t->rchild);
		}
		else
			return ;
	}

