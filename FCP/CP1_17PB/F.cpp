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

vector <int> V;
vector < vector < int > > G;

void dfs(int);

int main()
{
	int n, m;
	cin >> n >> m;

	G.resize(n+1);
	V.resize(n+1, 0);

	while(m--)
	{
		int x, y;
		cin >> x >> y;

		G[x].pb(y);
		G[y].pb(x);
	}

	int ans = 0;
	for(int i=1; i<=n; i++)
	{
		if(not V[i])
		{
			dfs(i);
			ans++;
		}
	}

	cout << ans << endl;

	return (0-0);	
}

void dfs(int node)
{
	V[node] = 1;

	for(auto v: G[node])
		if(not V[v])
			dfs(v);
}