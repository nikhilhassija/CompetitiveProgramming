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

vector <int> C;
vector <vector <int> > G;

int dfs(int);

int main()
{
	int n, m;
	cin >> n >> m;

	C.resize(n+1, 0);
	G.resize(n+1);

	while(m--)
	{
		int x, y;
		cin >> x >> y;

		G[x].pb(y);
		G[y].pb(x);
	}

	for(int i=1; i<=n; i++)
	{
		if(not C[i])
		{
			C[i] = 1;
			if(dfs(i))
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}

	vector < int > X[2];

	for(int i=1; i<=n; i++)
		X[C[i] - 1].pb(i);

	cout << X[0].size() << endl;
	for(auto node: X[0])
		cout << node << " ";
	cout << endl;

	cout << X[1].size() << endl;
	for(auto node: X[1])
		cout << node << " ";
	cout << endl;

	return (0-0);	
}

int dfs(int node)
{
	for(auto v: G[node])
	{
		if(C[v] == C[node])
			return 1;

		if(not C[v])
		{
			C[v] = (C[node] == 1)?2: 1;

			if(dfs(v))
			{
				return 1;
			}
		}
	}

	return 0;
}