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

const int MAX_N = 3e5 + 5;
const lli MOD   = 1e9 + 7;

lli P[MAX_N];

void init();

int main()
{
	init();

	int n;
	cin >> n;

	lli A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	sort(A, A+n);

	lli ans = 0;

	for(int i=0; i<n; i++)
	{
		lli l = i;
		lli r = n - (i + 1);

		ans += (A[i] * P[l]) % MOD;
		ans -= (A[i] * P[r]) % MOD;
		ans %= MOD;
	}

	while(ans < 0)
	{
		ans += MOD;
		ans %= MOD;	
	}

	cout << ans << endl;

	return (0-0);	
}

void init()
{
	P[0] = 1;
	for(int i=1; i<MAX_N; i++)
		P[i] = (P[i-1] * 2LL) % MOD;
}