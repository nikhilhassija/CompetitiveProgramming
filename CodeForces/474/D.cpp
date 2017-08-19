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

int main()
{
	int t, k;
	cin >> t >> k;

	const lli MOD = 1e9 + 7;
	const lli MAX_K = 1e5 + 5;

	lli DP[MAX_K];
	mset(DP);

	DP[0] = 1;
	for(int i = 1; i < MAX_K; i++)
	{
		if(i >= k)
			DP[i] += DP[i - k];

		DP[i] += DP[i - 1];

		DP[i] %= MOD;
	} 

	for(int i = 1; i < MAX_K; i++)
		DP[i] = (DP[i] + DP[i - 1]) % MOD;

	while(t--)
	{
		int a, b;
		cin >> a >> b;

		lli ans = (DP[b] - DP[a - 1] + MOD) % MOD;

		cout << ans << endl;
	}
	
	return (0-0);	
}