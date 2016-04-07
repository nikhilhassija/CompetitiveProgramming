#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define white 0
#define grey 1
#define black 2

struct node
{
	int data;
	struct node * next;
};

void add(struct node * G, int x, int y);
void dfs(struct node * G, int n, int * in, int * res, int * top);
int visit(struct node * G, int n, int x, int *res, int * top);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{

		int n;
		scanf("%d",&n);

		struct node G[n];
		int in[n];
		memset(in,0,sizeof(in));
		for(int i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);

			G[i].data = white;
			G[i].next = NULL;

			if(m)
			{
				for(int j=0;j<m;j++)
				{
					int x;
					scanf("%d",&x);
	
						add(G,i,x-1);
						in[x-1]++;
				}
			}
		}

		int res[n];
		int top = 0;
		dfs(G,n,in,res,&top);

		if(top != n)
			printf("FAIL\n");
		else
		{
			for(int i=n-1;i>=0;i--)
				printf("%d ",res[i]+1);
			printf("\n");
		}
	}
}

void add(struct node * G, int x, int y)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = y;
	temp->next = NULL;

	if(G[x].next == NULL)
	{
		G[x].next = temp;
	}
	else
	{
		struct node * cur = G[x].next;
		
		while(cur->next != NULL)
			cur = cur->next;

		cur->next = temp;
	} 
}

void dfs(struct node * G, int n, int * in, int * res, int * top)
{
	for(int i=0;i<n;i++)
	{

		if(G[i].data == white && G[i].next)
			if(visit(G,n,i,res,top))
				return ;
	}
}

int visit(struct node * G, int n, int x, int *res, int * top)
{
	G[x].data = grey;
	struct node * cur = G[x].next;

	while(cur)
	{
		if(G[cur->data].data == grey)
			return 1;
		if(G[cur->data].data == white)
			visit(G,n,cur->data,res,top);

		cur = cur->next;
	}
	G[x].data = black;
	res[(*top)++] = x;
} 