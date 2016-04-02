#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node * next;
};

void add_edge(struct node *, int, int);
void BFS(struct node *, int, int);

int R[5005][5005];

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int v,e;
		scanf("%d",&v);
		scanf("%d",&e);

		struct node G[v];

		for(int i=0;i<v;i++)
			G[i].next = NULL;
		memset(R,0,sizeof(R));

		while(e--)
		{
			int x,y;
			scanf("%d",&x);
			scanf("%d",&y);

			add_edge(G,x-1,y-1);
		}


		for(int i=0;i<v;i++)
			BFS(G,i,v);

		for(int i=0;i<v;i++)
		{
			int f = 1;
			for(int j=0;j<v;j++)
			{
				if(R[i][j])
				{
					if(R[j][i])
						continue;
					else
					{
						f = 0;
						break;
					}
				}
			}
			if(f)
				printf("%d ",i+1);
		}
		printf("\n");
	}
}

void add_edge(struct node * G, int x, int y)
{
	struct node * xy = (struct node *)malloc(sizeof(struct node));
	xy->data = y;
	xy->next = NULL;

	if(G[x].next == NULL)
	{
		G[x].next = xy;
	}
	else
	{
		struct node * cur = G[x].next;

		while(cur->next != NULL)
			cur = cur->next;

		cur->next = xy;
	}
}

void BFS(struct node * G, int x, int n)
{
	int Q[5005];
	int head = 0;
	int tail = 0;
	Q[tail++] = x;

	while(head<tail)
	{
		int u = Q[head++];
		struct node * cur = G[u].next;

		while(cur != NULL)
		{
			int v = cur->data;

			if(!R[x][v])
			{
				R[x][v] = 1;
				Q[tail++] = v;
			}

			cur = cur->next;
		}
	}
}