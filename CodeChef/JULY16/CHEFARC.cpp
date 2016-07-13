#include <bits/stdc++.h>

#define mp(a,b) make_pair(a,b)
#define pii pair <int,int>

using namespace std;

const int N = 105;

int k[2];
int A[N][N];
int V[2][N][N];
int D[2][N][N];

int n,m,k1,k2;

void bfs(int);
int in(int);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		cin>>n>>m>>k[0]>>k[1];

		for(int l=0;l<2;l++)
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					V[l][i][j] = 1;
		memset(D,0,sizeof(D));

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>A[i][j];

		for(int l=0;l<2;l++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					V[l][i][j] = A[i][j];

		bfs(0);
		bfs(1);

		if(m == 1)
			printf("0\n");
		else
		{
			int ans = N*N;
			if(k[0] && k[1])
			{
				for(int i=1;i<=n;i++)
					for(int j=1;j<=m;j++)
						if(A[i][j] == 0 && D[0][i][j] && D[1][i][j])
							ans = min(ans,max(D[0][i][j],D[1][i][j]));
			}
			else if(k[0])
			{
				ans = D[0][1][m];
			}
			else if(k[1])
				ans = D[1][1][1];
			else
				ans = 0;
			
			if(ans && ans!=N*N)
				printf("%d\n",ans-1);
			else
				printf("-1\n");
		}
	}
}

void bfs(int l)
{
	queue <pii> Q;

	if(l)
	{
		Q.push(mp(1,m));
		D[l][1][m] = 1;
	}
	else
	{
		Q.push(mp(1,1));
		D[l][1][1] = 1;
	}

	while(!Q.empty())
	{
		pii x = Q.front();
		Q.pop();

		int i = x.first;
		int j = x.second;
		int d = D[l][i][j];


		if(V[l][i][j])
			continue;
		else
			V[l][i][j] = 1;

		for(int di=-k[l];di<=k[l];di++)
		{
			for(int dj=-k[l];dj<=k[l];dj++)
			{
				if(in(i+di) && in(j+dj) && (abs(di) + abs(dj) <= k[l]))
				{
					if(V[l][i+di][j+dj] == 0)
					{	
						if(D[l][i+di][j+dj])
							D[l][i+di][j+dj] = min(D[l][i+di][j+dj],d+1);
						else
							D[l][i+di][j+dj] = d+1;
						Q.push(mp(i+di,j+dj));
					}
				}
			}
		}
	}
}

int in(int x)
{
	if(0<=x && x<=N)
		return 1;
	return 0;
}