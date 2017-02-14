#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

vector < vector <int> > G;
vector <int> C, V, R;

void dfs(int, int);

int main()
{
	int n;
	cin >> n;

	G.resize(n+1);
	C.resize(n+1);
	V.resize(n+1, 0);
	R.resize(n+1, 0);

	for(int i=1; i<n; i++)
	{
		int x, y;
		cin >> x >> y;

		G[x].pb(y);
		G[y].pb(x);

	}

	for(int i=1; i<=n; i++)
	{
		cin >> C[i];
	}

	for(int i=1; i<=n; i++)
	{
		if(!V[i] and G[i].size() == 1)
		{
			dfs(i, C[i]);
		}
	}

	int r = 0;
	for(int i=0; i<=n; i++)
		r += R[i] != 0;

	if(r == 0)
	{
		printf("YES\n1\n");
	}
	else if(r == 1)
	{
		printf("YES\n");
		for(int i=0; i<=n; i++)
		{
			if(R[i])
			{
				printf("%d\n", i);
				return 0;
			}
		}
	}
	else
	{
		printf("NO\n");
	}
}

void dfs(int node, int c)
{
	if(C[node] != c)
	{
		R[node] = 1;
		return ;
	}

	V[node] = 1;

	for(int i=0; i<G[node].size(); i++)
	{
		int v = G[node][i];

		if(!V[v])
		{
			dfs(v, c);
		}
	}
}