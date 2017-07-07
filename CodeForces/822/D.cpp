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

const int MAX_N = 5e6 + 5;
const lli MOD = 1e9 + 7;

lli P[MAX_N];
lli F[MAX_N];

void init();

int main()
{
	init();

	lli t, l, r;
	cin >> t >> l >> r;

	lli ans = 0;
	lli mul = 1;

	while(l <= r)
	{
		ans += (mul * F[l]) % MOD;
		ans %= MOD;

		mul = (mul * t) % MOD;
		
		l++;
	}

	cout << (ans % MOD) << endl;

	return (0-0);	
}

void init()
{
	mset(P);
	mset(F);

	for(int i=2; i<MAX_N; i++)
	{
		if(not P[i])
		{
			for(int j=i; j<MAX_N; j += i)
			{
				if(not P[j])
					P[j] = i;
			}
		}
	}
	
	F[0] = F[1] = 0;
	for(lli i=2; i<MAX_N; i++)
	{
		F[i] = (i * (P[i] - 1)) / 2;
		F[i] %= MOD;

		F[i] = (F[i] + F[i / P[i]]);
		F[i] %= MOD;
	}
}