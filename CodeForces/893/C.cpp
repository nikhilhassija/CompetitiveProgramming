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

vector < int > C;
vector < vector < int > > G;

lli bfs(int);

int main()
{
	int n, m;
	cin >> n >> m;
	
	C.resize(n + 1);
	C[0] = 0;

	G.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> C[i];

	while (m--)
	{
		int x, y;
		cin >> x >> y;

		G[x].pb(y);
		G[y].pb(x);
	}

	lli ans = 0;

	for (int i = 1; i <= n; i++)
		if (C[i] != -1)
			ans += bfs(i);

	cout << ans << endl;

	return (0-0);	
}

lli bfs(int u)
{
	lli ans = C[u];
	C[u] = -1;

	for (int v: G[u])
		if (C[v] != -1)
			ans = min(ans, bfs(v));

	return ans;
}