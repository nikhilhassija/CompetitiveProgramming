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

const int MAX_N = 1e5 + 5;
const int MAX_X = 10 + 5;

const lli MOD = 1e9 + 7;

lli DP[MAX_N][MAX_X][3];

lli lk, ek, gk;

vector < vector < int > > G;

void dfs(int, int);

int main()
{
	mset(DP);

	int n, m;
	cin >> n >> m;

	G.resize(n + 1);
	
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		G[x].pb(y);
		G[y].pb(x);
	}

	int k, x;
	cin >> k >> x;

	lk = k - 1;
	ek = k / k;
	gk = m - k;

	dfs(1, 0);

	lli ans = 0;
	for (int i = 0; i <= x; i++)
	{
		// cout << i << " -- ";
		for (int j = 0; j < 3; j++)
		{
			// cout << DP[1][i][j] << " ";
			ans = (ans + DP[1][i][j]) % MOD;
		}
		// cout << endl;

	}

	cout << ans << endl;

	return (0-0);	
}

// 0 - less k
// 1 - equal k
// 2 - greater k

void dfs(int u, int p)
{
	// cout << u << " " << p << endl;

	if ((not G[u].size()) or (G[u].size() == 1 and G[u][0] == p))
	{
		DP[u][0][0] = lk;
		DP[u][1][1] = ek;
		DP[u][0][2] = gk;

		return ;
	}

	int f = 1;

	for (int v: G[u])
	{
		if (v != p)
			dfs(v, u);

		if (v != p and f)
		{
			// cout << "first calc " << u << " --> " << v << endl;
			f = 0;

			for (int i = 0; i < MAX_X; i++)
			{
				DP[u][i][0] = (DP[v][i][0] + DP[v][i][1] + DP[v][i][2]) % MOD;
				DP[u][i][2] = (DP[v][i][0] + DP[v][i][2]) % MOD;

				if (i)
					DP[u][i][1] = DP[v][i - 1][0];
			}

			// for (int i = 0; i < MAX_X; i++)
			// {
			// 	cout << i << " -- ";
			// 	for (int j = 0; j < 3; j++)
			// 		cout << DP[u][i][j] << " ";
			// 	cout << endl;
			// }
		}
		else if (v != p)
		{
			lli A[MAX_X][3];
			mset(A);

			for (int i = 0; i < MAX_X; i++)
			{
				for (int j = 0; j < MAX_X; j++)
				{
					if (i + j < MAX_X)
					{
						lli ans;

						// self < k
						ans = (DP[v][j][0] + DP[v][j][1] + DP[v][j][2]) % MOD;
						ans = (DP[u][i][0] * ans) % MOD;
						A[i + j][0] = (A[i + j][0] + ans) % MOD;

						// self = k;
						ans = (DP[u][i][1] * DP[v][j][0]) % MOD;
						A[i + j][1] = (A[i + j][1] + ans) % MOD;

						// self > k;
						ans = (DP[v][j][0] + DP[v][j][2]) % MOD;
						ans = (DP[u][i][2] * ans) % MOD;
						A[i + j][2] = (A[i + j][2] + ans) % MOD;
					}
				}
			}

			for (int i = 0; i < MAX_X; i++)
				for (int j = 0; j < 3; j++)
					DP[u][i][j] = A[i][j] % MOD;
		}
	}

	for (int i = 0; i < MAX_X; i++)
	{
		DP[u][i][0] = (DP[u][i][0] * lk) % MOD;
		DP[u][i][1] = (DP[u][i][1] * ek) % MOD;
		DP[u][i][2] = (DP[u][i][2] * gk) % MOD;
	}

	// cout << "final DP " << u << endl;

	// for (int i = 0; i < MAX_X; i++)
	// {
	// 	cout << i << " -- ";

	// 	for (int j = 0; j < 3; j++)
	// 		cout << DP[u][i][j] << " ";

	// 	cout << endl;
	// }
}