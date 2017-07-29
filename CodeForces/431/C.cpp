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

const lli MOD = 1e9 + 7;

int main()
{
	int n, k, d;
	cin >> n >> k >> d;

	lli DP[2][110][110];
	mset(DP);

	DP[0][0][0] = 1;

	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <= k; j++)
			for(int s = 0; s <= n; s++)
				if(s - j >= 0)
				{
					DP[(j >= d)][i][s] += DP[0][i - 1][s - j];

					DP[1][i][s] += DP[1][i - 1][s - j];

					DP[0][i][s] %= MOD;
					DP[1][i][s] %= MOD;
				}

	lli ans = 0;
	for(int i = 0; i <= n; i++)
		ans = (ans + DP[1][i][n]) % MOD;;

	cout << ans << endl;
	
	return (0-0);	
}