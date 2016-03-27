#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct node 
{
	int data;
	struct node * next;
};

int Q[100005], head, tail;
int V[100005];
int D[100005];

int min(int a, int b)
{
	return (a<b)?a:b;
}

void insert(struct node ** A, int x)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;

	if((*A) == NULL)
		*A = temp;
	else
	{
		struct node * cur = *A;

		while(cur->next != NULL)
			cur = cur->next;

		cur->next = temp;
	}
}

void bfs(struct node ** A, int x)
{
	if(head == tail)
		return;
	else
	{
		V[x] = 1;
		struct node * cur = A[x];

		while(cur != NULL)
		{
			if(V[cur->data] == 0)
			{
				Q[tail] = cur->data;
				tail++;
			}

			D[cur->data] = min(D[x] + 1,D[cur->data]);
			cur = cur->next;
		}

		head++;
		bfs(A,Q[head]);
	}
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n,m;

		scanf("%d %d",&n,&m);

		struct node * A[n];

		for(int i=0;i<n;i++)
			A[i] = NULL;

		while(m--)
		{
			int x,y;
			scanf("%d %d",&x,&y);

			insert(&A[x-1],y-1);
			insert(&A[y-1],x-1);
		}

		memset(V,0,sizeof(V));
		for(int i=0;i<n;i++)
			D[i] = INT_MAX;

		D[0] = 0;

		Q[0] = 0;
		head = 0;
		tail = 1;

		bfs(A,0);

		if(D[n-1] != INT_MAX)
			printf("%d\n",D[n-1]);
		else
			printf("-1\n");
	}
}