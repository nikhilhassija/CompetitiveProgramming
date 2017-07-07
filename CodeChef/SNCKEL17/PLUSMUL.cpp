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

const lli MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;

lli P[MAX_N];
lli A[MAX_N];

void init();
lli solve(int);

int main()
{
	init();

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		for(int i=0; i<n; i++)
			cin >> A[i];

		lli ans = solve(n);

		cout << ans << endl;
	}

	return (0-0);	
}

void init()
{
	P[0] = 1;

	for(int i=1; i<MAX_N; i++)
		P[i] = (P[i-1] * 2ll) % MOD;
}

lli solve(int n)
{
	lli ans = 0;

	for(int i=0; i<n; i++)
	{
		if(i == n-1)
		{
			ans += A[i];
			ans %= MOD;
			break;
		}

		ans += (A[i] * P[n - i -2]) % MOD;
		ans %= MOD;

		A[i+1] = ((A[i+1] * P[i]) % MOD) + ((A[i] * A[i+1]) % MOD);
		A[i+1] %= MOD;
	}

	return ans % MOD;
}