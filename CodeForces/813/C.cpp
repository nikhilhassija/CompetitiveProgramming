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
vector <int> A, B;
vector <int> V;

void dfs(int, int, int);

int main()
{
	int n, x;
	cin >> n >> x;

	G.resize(n+1);
	A.resize(n+1);
	B.resize(n+1);
	V.resize(n+1, 0);

	for(int i=1; i<n; i++)
	{
		int l, r;
		cin >> l >> r;

		G[l].pb(r);
		G[r].pb(l);
	}

	dfs(1, 0, 0);
	dfs(x, 0, 1);

	int ans = 0;

	for(int i=1; i<=n; i++)
		if(B[i] < A[i])
			ans = max(ans, A[i]);

	cout << 2*ans << endl;
	return (0-0);	
}

void dfs(int u, int t, int b)
{
	V[u] = 1;

	if(b)
		B[u] = t;
	else
		A[u] = t;

	for(auto v: G[u])
	{
		if(not V[v])
			dfs(v, t+1, b);
	}

	V[u] = 0;
}