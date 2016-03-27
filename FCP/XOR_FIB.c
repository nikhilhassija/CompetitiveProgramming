#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int ends_here;
	struct node * sub[2];
};

const int mod = 1e9 + 7;

void genfib(int *, int);
void genbits(int *, int);
void insert(struct node *, int);
int maxxor(struct node *, int);

int main()
{
	struct node * root = (struct node *)malloc(sizeof(struct node));
	root->ends_here = 0;
	root->sub[0] = NULL;
	root->sub[1] = NULL;

	int A[100005];
	genfib(A,100005);

	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);

	while(n--)
	{
		int x;
		scanf("%d",&x);

		insert(root,x);
	}

	for(int i=0;i<m;i++)
	{
		int x = maxxor(root,A[i+1]);
		printf("%d\n",x);

		insert(root,x);
	}
}

void genfib(int * A, int n)
{
	A[0] = 0;
	A[1] = 1;
	for(int i=2;i<n;i++)
		A[i] = (A[i-1] + A[i-2])%mod;
}

void insert(struct node * root, int x)
{
	int A[32];
	memset(A,0,sizeof(A));
	genbits(A,x);

	for(int i=0;i<32;i++)
	{
		if(root->sub[A[i]] == NULL)
		{
			(root->sub[A[i]]) = (struct node *)malloc(sizeof(struct node));
			(root->sub[A[i]])->ends_here = 0;
			(root->sub[A[i]])->sub[0] = NULL;
			(root->sub[A[i]])->sub[1] = NULL;
		}
		root = root->sub[A[i]];
	}
	root->ends_here = 1;
}

void genbits(int * A, int x)
{
	for(int i=0;i<32;i++)
		A[i] = 1 & (x >> (31-i));
}

int maxxor(struct node * root, int x)
{
	int A[32];
	memset(A,0,sizeof(A));
	genbits(A,x);

	int cur = 0;

	for(int i=0;i<32;i++)
	{
		if(root->sub[1^A[i]] != NULL)
		{
			cur = (cur<<1) + (1^A[i]);
			root = root->sub[1^A[i]]; 
		}
		else
		{
			cur = (cur<<1) + A[i];
			root = root->sub[A[i]];
		}
	}	

	return x ^ cur;
}