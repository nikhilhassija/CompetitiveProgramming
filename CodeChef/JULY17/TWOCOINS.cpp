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

struct node
{
	int poss = 0;
	int dist_1 = 0;
	int dist_2 = 0;
};

const int MAX_N = 1e5 + 5;

vector < vector <int> > G;

vector <int> P;

// self, parent, grandparent
node DP[MAX_N][2][2][2];

void parent(int);

void dfs(int);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		mset(DP);

		int n;
		cin >> n;

		G.clear();
		G.resize(n + 3);

		for(int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;

			G[u].pb(v);
			G[v].pb(u);
		}

		P.clear();
		P.resize(n + 1);

		parent(1);

	}
	
	return (0-0);	
}

void parent(int u)
{
	for(int v: G[u])
	{
		if(v != P[u])
		{
			P[v] = u;
			parent(v);
		}
	}
}

void dfs(int u)
{
	for(int v: G[u])
		if(not P[u] == v)
			dfs(v);

	DP[u][0][0][0];

	for(int v: G[u])
	{
		//child, me, parent
		DP[v][][0][0];
	}

	DP[u][0][0][1];
	DP[u][0][1][0];
	DP[u][0][1][1];
	DP[u][1][0][0];
	DP[u][1][0][1];
	DP[u][1][1][0];
	DP[u][1][1][1];
}