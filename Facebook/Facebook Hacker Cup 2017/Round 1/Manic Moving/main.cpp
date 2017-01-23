#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)
#define DEBUG 0

using namespace std;

const lli inf = 1e9;

struct node
{
	lli dist;
	lli cur;
	lli load;
};

vector < vector <lli> > G;

void allpairshortest(int);

int main()
{
	int _t;
	cin >> _t;

	for(int t=1; t <= _t; t++)
	{
		G.clear();

		int n, m, k;
		cin >> n >> m >> k;

		G.resize(n+1);
		for(int i = 0; i <= n; i++)
			G[i].resize(n+1, inf);

		for(int i = 0; i < m; i++)
		{
			lli x, y, w;
			cin >> x >> y >> w;

			G[x][y] = min(G[x][y], w);
			G[y][x] = min(G[y][x], w);
		}

		allpairshortest(n+1);
		for(int i = 0; i <= n; i++)
			G[i][i] = 0;

		int S[k+2], D[k+2];
		for(int i = 0; i < k; i++)
			cin >> S[i] >> D[i]; 

		S[k+1] = S[k] = S[k-1];
		D[k+1] = D[k] = D[k-1];

		int f = 0;
		for(int i = 0; i < k; i++)
			if(G[S[i]][D[i]] == inf)
				f = 1;

		if(f)
			printf("Case #%d: -1\n", t);
		else
		{
			lli DP[2*k + 4][3];
			//DP State = (pos, load)
			
			for(int i = 0; i < 2*k; i++)
				DP[i][0] = DP[i][1] = DP[i][2] = inf;

			DP[0][1] = G[1][S[0]];

			for(int x = 0; x < k; x++)
			{
				int i;
				i = 2*x;

				//LOAD
				// At (i, 1);
				DP[i][2] = min(DP[i][2], DP[i][1] + G[S[x]][S[x+1]]);
				DP[i+1][0] = min(DP[i+1][0], DP[i][1] + G[S[x]][D[x]]);

				// At (i, 2)
				DP[i+1][1] = min(DP[i+1][1], DP[i][2] + G[S[x+1]][D[x]]);

				//UNLOAD
				i++;

				// At (i, 0)
				DP[i+1][1] = min(DP[i+1][1], DP[i][0] + G[D[x]][S[x+1]]);

				// At (i, 1)
				DP[i][2] = min(DP[i][2], DP[i][1] + G[D[x]][S[x+2]]);
				DP[i+2][0] = min(DP[i+1][0], DP[i][1] + G[D[x]][D[x+1]]);

				// At (i, 2)
				DP[i+2][1] = min(DP[i+2][1], DP[i][2] + G[S[x+2]][D[x+1]]);
			}

			int x = 2*k - 1;
			printf("Case #%d: %lld\n", t, DP[x][0]);

			if(DEBUG)
			{
				for(int i=0; i < 2*k; i++)
				{
					for(int j=0; j<3; j++)
						printf("%lld ", DP[i][j]);
					printf("\n");
				}
			}
		}
	}
}

void allpairshortest(int n)
{
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}