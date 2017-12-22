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

vector < vector <int> > G;
vector <int> C;

bool color(int, int);

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, q;
		cin >> n >> q;

		G.resize(n + q + 2);
		C.resize(n + q + 2, 0);

		bool ans = 1;

		int temp = n;

		while (q--)
		{
			int u, v, x;
			cin >> u >> v >> x;

			if (x)
			{
				if (u == v)
					ans = 0;

				G[u].pb(v);
				G[v].pb(u);
			}
			else if(u != v)
			{
				temp++;

				G[temp].pb(u);
				G[u].pb(temp);

				G[temp].pb(v);
				G[v].pb(temp);
			}
		}

		for (int i = 1; ans and i <= temp; i++)
			if (not C[i])
				ans &= color(i, 1);

		if (ans)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

		G.clear();
		C.clear();
	}
	
	return (0-0);	
}

bool color(int u, int c)
{
	C[u] = c;

	int ans = 1;

	for (int v: G[u])
	{
		if (not C[v])
			ans &= color(v, (c % 2) + 1);
		else if(C[v] == c)
			return 0;
	}

	return ans;
}