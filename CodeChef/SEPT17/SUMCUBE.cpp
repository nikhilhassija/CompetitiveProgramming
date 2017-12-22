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

vector < int > A;

const lli MOD = 1e9 + 7;

lli solve(int, int, lli);

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		lli n, m, k;
		cin >> n >> m >> k;

		if (k == 1)
		{
			lli ans = m;

			while (m--)
			{
				int u, v;
				cin >> u >> v;
			}

			for (int i = 0; i < n - 2; i++)
				ans = (ans * 2) % MOD;

			cout << ans << endl;
		}
		else if (n <= 15)
		{
			G.clear();
			G.resize(n, vector <int> (n, 0));

			while (m--)
			{
				int u, v;
				cin >> u >> v;

				u--; v--;

				G[u][v] = 1;
				G[v][u] = 1;
			}

			A.clear();
			A.resize(n, 0);

			cout << solve(0, n, k) << endl;
		}
		else
			cout << 0 << endl;
	}
	
	return (0-0);	
}

lli solve(int x, int n, lli k)
{
	if (x == n)
	{
		lli e = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (A[i] and A[j])
					e += G[i][j];

		return (lli) pow(e, k);
	}

	lli ans = solve(x + 1, n, k);

	A[x] = 1;

	ans = (ans + solve(x + 1, n, k)) % MOD;

	A[x] = 0;

	return ans;
}