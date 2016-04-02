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
	int dist;
	int color;
	int parent;
	struct edge * adj;
};

void add_edge(struct vertex *, int, int);
void print_graph(struct vertex *, int);
void BFS(struct vertex *, int, int);
void print_bfs(struct vertex *, int, int);

int main()
{
	int t=1;
	// scanf("%d",&t);

	while(t--)
	{
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);

		struct vertex G[n];

		for(int i=0;i<n;i++)
		{
			G[i].adj = NULL;
			G[i].dist = inf;
			G[i].color = w;
			G[i].parent = -1;
		}

		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);

			add_edge(G,x,y);
			add_edge(G,y,x);
		}


		for(int i=0;i<k;i++)
		{
			int x;
			scanf("%d",&x);

			BFS(G,n,x);
		}
	}
}

void add_edge(struct vertex * G, int x, int y)
{
	struct edge * xy = (struct edge *)malloc(sizeof(struct edge));
	xy->data = y;
	xy->next = NULL;

	if(G[x].adj == NULL)
	{
		G[x].adj = xy;
	}
	else
	{
		struct edge * cur = G[x].adj;

		while(cur->next != NULL)
			cur = cur->next;

		cur->next = xy; 
	} 
}

void print_graph(struct vertex * G, int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d | ",i+1);

		struct edge * cur = G[i].adj;

		while(cur != NULL)
		{
			printf("%d ",cur->data+1);
			cur = cur->next;
		}
		printf("\n");
	}
}

void BFS(struct vertex * G, int n, int x)
{
	for(int i=0;i<n;i++)
	{
		G[i].dist = inf;
		G[i].color = w;
		G[i].parent = -1;
	}

	G[x].color = g;
	G[x].dist = 0;

	int Q[n];
	int head = 0;
	int tail = 0;
	Q[tail++] = x;

	while(head < tail)
	{
		int u = Q[head++];

		struct edge * cur = G[u].adj;

		while(cur != NULL)
		{
			int v = cur->data;
			
			if(G[v].color == w)
			{
				G[v].dist = G[u].dist + 1;
				G[v].color = g;
				G[v].parent = u;
				Q[tail++] = v;
			}

			cur = cur->next;
		}

		G[u].color = b;
	}

	long long int total_dist = 0;
	for(int i=0;i<n;i++)
		total_dist += G[i].dist;

	printf("%lld\n",total_dist);
	// print_bfs(G,n,x);
}

void print_bfs(struct vertex * G, int n, int x)
{
	printf("----BFS @ %d\n",x);
	for(int i=0;i<n;i++)
		printf("%d | D:%d C:%d P:%d \n",i,G[i].dist,G[i].color,G[i].parent);
}