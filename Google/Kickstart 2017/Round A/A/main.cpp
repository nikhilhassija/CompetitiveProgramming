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

lli mod = 1e9 + 7;

int main()
{
	int _t;
	cin >> _t;

	for(int t=1; t<=_t; t++)
	{
		int n, m;
		cin >> n >> m;

		lli ans = 0;
		for(int l=1; l<=min(n,m); l++)
		{
			ans += (((m-l)*(n-l) % mod)*l) % mod;
			ans %= mod;
		}

		printf("Case #%d: %lld\n", t, ans);
	}

	return (0-0);	
}