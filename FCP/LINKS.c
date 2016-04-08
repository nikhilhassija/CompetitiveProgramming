#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int max(int a, int b)
{
	return (a>b)?a:b;
}

int min(int a, int b)
{
	return (a<b)?a:b;
}

int find(int *, int);
void merge(int *, int *, int, int);

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);

	int P[n];
	int S[n];

	memset(S,0,sizeof(S));

	int mx = 1;
	int mn = 1;

	for(int i=0;i<n;i++)
	{
		P[i] = i;
		S[i] = 1;
	}

	while(q--)
	{
		char A[5];
		scanf("%s",A);

		if(strcmp(A,"M") == 0)
		{
			int x,y;
			scanf("%d %d",&x,&y);	

			x--;
			y--;

			merge(P,S,x,y);
			mx = max(mx,S[find(P,x)]);
		}
		if(strcmp(A,"Q") == 0)
		{
			int x;
			scanf("%d",&x);

			printf("%d\n",S[find(P,x-1)]);
		}
		if(strcmp(A,"MAX") == 0)
		{
			mx = S[find(P,0)];
			for(int i=0;i<n;i++)
			{
				mx = max(mx,S[find(P,i)]);
			}
			printf("%d\n",mx);
		}
		if(strcmp(A,"MIN") == 0)
		{
			mn = S[find(P,0)];
			for(int i=0;i<n;i++)
			{
				mn = min(mn,S[find(P,i)]);
			}
			printf("%d\n",mn);
		}
	}
}

int find(int * P, int x)
{
	if(P[x] == x)
		return x;
	else
		return P[x] = find(P,P[x]);
}

void merge(int * P, int * S, int a, int b)
{
	a = find(P,a);
	b = find(P,b);

	if(a != b)
	{
		P[a] = b;

		int s = S[a] + S[b];
		S[a] = s;
		S[b] = s;
	}
}