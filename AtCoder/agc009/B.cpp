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
vector <int> V;

int dfs(int);

int main()
{
	int n;
	cin >> n;

	G.resize(n+1);
	V.resize(n+1, 0);

	for(int i=2; i<=n; i++)
	{
		int x;
		cin >> x;

		G[x].pb(i);
	}

	cout << dfs(1) << endl;
}

int dfs(int u)
{
	int ans = 0;

	V[u] = 1;

	for(int i=0; i<G[u].size(); i++)
	{
		int v = G[u][i];

		if(!V[v])
			ans = max(ans, dfs(v));
	}


	if(G[u].size() > 1)
		return ans + 2;
	else if(G[u].size() == 1)
		return ans + 1;
	else
		return ans;
}