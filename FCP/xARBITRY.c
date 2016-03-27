#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 0
#define BLACK 1 

struct node
{
	int data;
	char color;

	struct node * parent;
	struct node * lchild;
	struct node * rchild;
};

struct Tree
{	
	struct node * nil;
	struct node * root;
};

struct node * Q[1005];
int head;
int tail;

void lrotate(struct Tree *, struct node *);
void rrotate(struct Tree *, struct node *);
void fixup(struct Tree *, struct node *);
void insert(struct Tree *, struct node *);
void preoder(struct node *, struct node *, int);
void print(struct Tree *, int);

int main()
{
	struct Tree * T = (struct Tree *)malloc(sizeof(struct Tree));

	T->nil = (struct node *)malloc(sizeof(struct node));
	(T->nil)->data = 0;
	(T->nil)->color = BLACK;
	(T->nil)->parent = T->nil;
	(T->nil)->lchild = T->root;
	(T->nil)->rchild = T->root;

	T->root = T->nil;

	int q;
	scanf("%d",&q);

	while(q--)	
	{
		char A[20];
		scanf("%s",A);

		if(strcmp(A,"INSERT") == 0)
		{
			int x;
			scanf("%d",&x);

			struct node * z = (struct node *)malloc(sizeof(struct node));
			z->data = x;

			insert(T,z);
		}
		if(strcmp(A,"PRINT") == 0)
		{
			char x;
			scanf("%c",&x);
			scanf("%c",&x);

			if(T->root != T->nil)
			{
				head = 0;
				tail = 0;
				Q[tail++] = T->root;

				if(x == 'B')
					print(T,BLACK);
				if(x == 'R')
					print(T,RED);
			}
		}
	}
}

void lrotate(struct Tree * T, struct node * temp)
{
	struct node * x = temp;
	struct node * y = x->rchild;
	x->rchild = y->lchild;

	if(y->lchild != T->nil)
		(y->lchild)->parent = x;
	
	y->parent = x->parent;

	if(x->parent == T->nil)
		T->root = y;
	else
	{
		if(x == (x->parent)->lchild)
			(x->parent)->lchild = y;
		else
			(x->parent)->rchild = y;	
	}		
	y->lchild = x;
	x->parent = y;
}


void rrotate(struct Tree * T, struct node * temp)
{
	struct node * x = temp;
	struct node * y = x->lchild;
	x->lchild = y->rchild;

	if(y->rchild != T->nil)
		(y->rchild)->parent = x;
	
	y->parent = x->parent;

	if(x->parent == T->nil)
		T->root = y;
	else
	{
		if(x == (x->parent)->rchild)
			(x->parent)->rchild = y;
		else
			(x->parent)->lchild = y;	
	}		
	y->rchild = x;
	x->parent = y;
}

void fixup(struct Tree * T, struct node * temp)
{
	struct node * z = temp;

	while((z->parent)->color == RED)
	{
		if(z->parent == ((z->parent)->parent)->lchild)
		{
			struct node * y = ((z->parent)->parent)->rchild;
			if(y->color == RED) 
			{
				(z->parent)->color = BLACK;
				y->color = BLACK;
				((z->parent)->parent)->color = RED;
				z = (z->parent)->parent;
			}
			else
			{
				if(z == (z->parent)->rchild)
				{
					z = z->parent;
					lrotate(T,z);
				}
				(z->parent)->color = BLACK;
				((z->parent)->parent)->color = RED;
				rrotate(T,(z->parent)->parent);
			}
		}
		else
		{
			struct node * y = ((z->parent)->parent)->lchild;
			if(y->color == RED) 
			{
				(z->parent)->color = BLACK;
				y->color = BLACK;
				((z->parent)->parent)->color = RED;
				z = (z->parent)->parent;
			}
			else
			{
				if(z == (z->parent)->lchild)
				{
					z = z->parent;
					rrotate(T,z);
				}
				(z->parent)->color = BLACK;
				((z->parent)->parent)->color = RED;
				lrotate(T,(z->parent)->parent);
			}
		}	
	}

	(T->root)->color = BLACK;
}

void insert(struct Tree * T, struct node * temp)
{
	struct node * z = temp;
	struct node * y = T->nil;
	struct node * x = T->root;

	while(x != T->nil)
	{
		y = x;
		if(z->data < x->data)
			x = x->lchild;
		else
			x = x->rchild;
	}

	z->parent = y;

	if(y == T->nil)
		T->root = z;
	else if(z->data < y->data)
		y->lchild = z;
	else
		y->rchild = z;

	z->lchild = T->nil;
	z->rchild = T->nil;
	z->color = RED;

	fixup(T,z);
}

void preoder(struct node * root, struct node * nil, int level)
{
	if(root == nil)
		return;
	else
	{
		for(int i=0;i<level;i++)
			printf("-");
		printf("%d(%d)\n",root->data,root->color);

		preoder(root->lchild,nil,level+1);		
		preoder(root->rchild,nil,level+1);		
	}
}

void print(struct Tree * T, int c)
{
	int f = 0;
	while(head != tail)
	{
		if(Q[head]->lchild != T->nil) 
			Q[tail++] = Q[head]->lchild;
		if(Q[head]->rchild != T->nil) 
			Q[tail++] = Q[head]->rchild;

		if(Q[head]->color == c)
		{
			f = 1;
			printf("%d ",Q[head]->data);
		}
		head++;
	}

	if(f)
		printf("\n");
}