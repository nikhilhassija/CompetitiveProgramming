#include <bits/stdc++.h>

using namespace std;

struct Query
{
	int t,a,b;
}Q[100005];

int ans[100005];
int V[100005];
int I[1005];
int R[1005];
int A[1005][1005];
vector < vector <int> > N;
int n,m,q;

void query(int);

int main()
{
	cin>>n>>m>>q;

	N.resize(q+1);
	memset(I,0,sizeof(I));
	memset(R,0,sizeof(R));

	Q[0].t =0;
	for(int i=1;i<=q;i++)
	{
		cin>>Q[i].t;
		if(Q[i].t < 3)
			cin>>Q[i].a>>Q[i].b;
		else
			cin>>Q[i].a;
	}

	for(int i=0;i<q;i++)
		if(i != q && Q[i+1].t != 4)
				N[i].push_back(i+1);

	for(int i=0;i<=q;i++)
		if(Q[i].t == 4 && Q[i].a != i-1)
			N[Q[i].a].push_back(i);

	query(0);

	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
}

void query(int x)
{
	if(Q[x].t && Q[x].t != 4)
	{
		ans[x] = ans[x-1];
		if(Q[x].t == 1)
		{
			int i,j;
			i = Q[x].a - 1;
			j = Q[x].b - 1;
			if(A[i][j] ^ I[i] == 0)
			{
				ans[x] += 1;
				R[i]++;
			}
			A[i][j] = I[i] ^ 1;
		}
		if(Q[x].t == 2)
		{
			int i,j;
			i = Q[x].a - 1;
			j = Q[x].b - 1;
			if(A[i][j] ^= I[i])
			{
				ans[x] -= 1;
				R[i]--;
			}
			A[i][j] = I[i];
		}
		if(Q[x].t == 3)
		{
			int i = Q[x].a - 1;
			ans[x] = ans[x-1] + m - 2*R[i];
			R[i] = m - R[i];
			I[i] ^= 1;
		}
	}

	for(int i=0;i<N[x].size();i++)
	{
		int u = N[x][i];
		if(Q[u].t == 4)
			ans[u] = ans[x];
		query(u);
	}

	if(Q[x].t && Q[x].t != 4)
	{
		if(Q[x].t == 2)
		{
			int i,j;
			i = Q[x].a - 1;
			j = Q[x].b - 1;
			if(A[i][j] ^ I[i] == 0)
			{
				// ans[x] = ans[x-1] + 1;
				R[i]++;
			}
			A[i][j] = I[i] ^ 1;
		}
		if(Q[x].t == 1)
		{
			int i,j;
			i = Q[x].a - 1;
			j = Q[x].b - 1;
			if(A[i][j]^I[i])
			{
				// ans[x] = ans[x-1] - 1;
				R[i]--;
			}
			A[i][j] = I[i];
		}
		if(Q[x].t == 3)
		{
			int i = Q[x].a - 1;
			// ans[x] = ans[x-1] + m - 2*R[i];
			R[i] = m - R[i];
			I[i] ^= 1;
		}
	}
}