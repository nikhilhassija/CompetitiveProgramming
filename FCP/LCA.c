#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
	int data;
	struct node * lchild;
	struct node * rchild;
};

int min(int a, int b)
{
	return (a<b)?a:b;
}

void insert(struct node ** root, int x)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->lchild = NULL;
	temp->rchild = NULL;

	struct node * cur = *root;

	if(cur == NULL)
	{
		*root = temp;
	}
	else
	{
		struct node * y = NULL;

		while(cur != NULL)
		{
			y = cur;
			if(x <= cur->data)
				cur = cur->lchild;
			else
				cur = cur->rchild;
		}

		if(x <= y->data)
			y->lchild = temp;
		else
			y->rchild = temp;
	}
}

int minheight(struct node * root)
{
	if(root == NULL)
		return 0;

	if(root->lchild == NULL && root->rchild == NULL)
		return 1;

	if(root->lchild == NULL)
		return 1 + minheight(root->rchild);

	if(root->rchild == NULL)
		return 1 + minheight(root->lchild);

	return 1 + min(minheight(root->lchild),minheight(root->rchild));
}

int path(struct node * root, int * A, int x, int level)
{
	A[level] = root->data;
	if(root->data == x)
		return level + 1;
	else
	{
		if(x <= root->data)
			return path(root->lchild,A,x,level+1);
		else
			return path(root->rchild,A,x,level+1);
	}
}

int lca(struct node * root, int * A, int x, int * B, int y)
{
	int a = path(root,A,x,0);
	int b = path(root,B,y,0);

	int m = min(a,b);

	while(m--)
		if(A[m] == B[m])
			return A[m];
	return A[m];
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		struct node * root = NULL;

		int n;
		scanf("%d",&n);

		while(n--)
		{
			int x;
			scanf("%d",&x);

			insert(&root,x);
		}

		printf("%d\n",minheight(root));

		int q;
		scanf("%d",&q);

		while(q--)
		{
			int x,y;
			scanf("%d %d",&x,&y);

			int A[10005];
			int B[10005];
			memset(A,0,sizeof(A));
			memset(B,0,sizeof(B));

			printf("%d\n",lca(root,A,x,B,y));
			// printf("%d\n",lca(root,x,y));
		}
	}
}