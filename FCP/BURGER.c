#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct edge
{
	long long int x;
	long long int y;
	long long int w;
};

void sort(struct edge *, long long int, long long int);
void merge(struct edge *, long long int, long long int, long long int);
void copy(struct edge *, struct edge *);
void unite(long long int *, long long int, long long int); 
long long int find(long long int *, long long int);

int main()
{
	long long int t;
	scanf("%lld",&t);

	while(t--)
	{
		long long int n,m;
		scanf("%lld %lld",&n,&m);

		struct edge G[m];

		for(long long int i=0;i<m;i++)
		{
			scanf("%lld %lld %lld",&G[i].x,&G[i].y,&G[i].w);
			G[i].x--;
			G[i].y--;
			G[i].w *= -1;
		}

		sort(G,0,m-1);

			long long int P[n];

		for(long long int i=0;i<n;i++)
			P[i] = i;

		long long int cost = 0;

		struct edge A[m];

		long long int k = 0;

		for(long long int i=0;i<m;i++)
		{
			long long int a = G[i].x;
			long long int b = G[i].y;
			long long int c = G[i].w;

			if(find(P,a) != find(P,b))
			{
				cost += c;
				copy(&A[k],&G[i]);
				k++;
				unite(P,a,b);
			}
		}

		printf("%lld\n",-cost);
	}
}

void sort(struct edge * G, long long int l, long long int r)
{
	if(l < r)
	{
		long long int m = (l+r)>>1;

		sort(G,l,m);
		sort(G,m+1,r);

		merge(G,l,m,r);
	}
}

void merge(struct edge * G, long long int l, long long int m, long long int r)
{
	long long int n1 = m - l + 1;
	long long int n2 = r - m + 0;

	struct edge L[n1];
	struct edge R[n2];

	for(long long int i=0;i<n1;i++)
	{
		copy(&L[i],&G[l+i]);
	}

	for(long long int i=0;i<n2;i++)
	{
		copy(&R[i],&G[m+1+i]);
	}

	long long int a = 0;
	long long int b = 0;
	long long int c = l;

	while(a<n1 && b<n2)
	{
		if(L[a].w < R[b].w)
		{
			copy(&G[c],&L[a]);
			c++;
			a++;
		}
		else
		{
			copy(&G[c],&R[b]);
			c++;
			b++;
		}
	}

	while(a<n1)
	{
		copy(&G[c],&L[a]);
		c++;
		a++;
	}

	while(b<n2)
	{
		copy(&G[c],&R[b]);
		c++;
		b++;
	}

}

void copy(struct edge * a, struct edge * b)
{
	a->x = b->x;
	a->y = b->y;
	a->w = b->w;
}

long long int find(long long int * P, long long int x)
{
	if(P[x] == x)
		return x;
	else
		return P[x] = find(P,P[x]);
}

void unite(long long int * P, long long int a, long long int b)
{
	a = find(P,a);
	b = find(P,b);

	P[a] = b;
}