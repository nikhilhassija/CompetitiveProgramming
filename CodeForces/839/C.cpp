#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

using namespace std;

double ans = 0;

vector < vector <int> > G;

void dfs(int, int, int, double);

int main()
{
	int n;
	cin >> n;

	G.resize(n + 1);

	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;

		G[u].pb(v);
		G[v].pb(u);
	}

	dfs(1, 0, 0, 1);

	cout << fixed << setprecision(15) << ans << endl;
	
	return (0-0);	
}

void dfs(int u, int p, int l, double x)
{
	int f = 0;

	for(int v : G[u])
		if(v != p)
			f++;

	if(not f)
	{
		ans += l * x;
		return ;
	}

	for(int v : G[u])
		if(v != p)
			dfs(v, u, l + 1, x / f);
}