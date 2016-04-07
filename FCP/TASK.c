#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define inf INT_MAX
#define w 0
#define g 1
#define b 2

struct edge
{
	int data;
	struct edge * next;
};

struct vertex
{
	int color;
	int ideg;
	struct edge * adj;
};

void add_edge(struct vertex *, int, int);
int toposort(struct vertex *, int, int *);
int visit(struct vertex *, int, int *, int *);

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);

		struct vertex G[n];

		for(int i=0;i<n;i++)
		{
			G[i].color = w;
			G[i].ideg = 0;
			G[i].adj = NULL;
		}

		for(int i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);

			while(m--)
			{
				int x;
				scanf("%d",&x);

				add_edge(G,i,x-1);
				G[x-1].ideg++;
			}
		}

		int stack[n];
		if(toposort(G,n,stack))
			printf("FAIL\n");
		else
		{
			for(int i=n-1;i>=0;i--)
				printf("%d ",stack[i]+1);
			printf("\n");
		}
	}
}

void add_edge(struct vertex * G, int x, int y)
{
	struct edge * xy = (struct edge *)malloc(sizeof(struct edge));
	xy->data = y;
	xy->next = NULL;

	if(G[x].adj == NULL)
		G[x].adj = xy;
	else
	{
		struct edge * cur = G[x].adj;

		while(cur->next != NULL)
			cur = cur->next;

		cur->next = xy;
	}
}

int toposort(struct vertex * G, int n, int * stack)
{
	int top = 0;
	int f = 1;

	for(int i=0;i<n;i++)
	{
		if(G[i].color == w && G[i].ideg == 0)
		{
			f = 0;
			if(visit(G,i,stack,&top))
				return 1;
		}
	}

	return f;
}

int visit(struct vertex * G, int u, int * stack, int * top)
{
	G[u].color = g;

	struct edge * cur = G[u].adj;
	int res = 0;

	while(cur != NULL)
	{
		int v = cur->data;
		if(G[v].color == g)
			return 1;
		if(G[v].color == w)
			res = visit(G,v,stack,top);

		cur = cur->next;
	} 
	G[u].color = b;
	stack[(*top)++] = u;
	return res;
}