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

const int MAXN = 1e6 + 30;

lli P[MAXN];
lli F[MAXN];
lli I[MAXN];

void init();

void seive();
void factorials();

lli choose(lli, lli);
lli binpow(lli, lli);

int main()
{
	init();

	int q;
	cin >> q;

	while (q--)
	{
		lli x, y;
		cin >> x >> y;

		lli cur = P[x];
		lli cnt = 1;

		x /= cur;

		lli ans = 1;

		while (x != 1)
		{
			if (P[x] != cur)
			{
				ans = (ans * choose(y + cnt - 1, cnt)) % MOD;
				cur = P[x];
				cnt = 1;
			}
			else 
				cnt++;

			x /= cur;
		}

		if (cur != 1)
			ans = (ans * choose(y + cnt - 1, cnt)) % MOD;

		ans = (ans * binpow(2, y - 1)) % MOD;

		cout << ans << endl;
	}
	
	return (0-0);	
}

void init()
{
	seive();
	factorials();
}

void seive()
{
	mset(P);

	P[1] = 1;

	for (int i = 2; i < MAXN; i++)
		if (!P[i])
			for (int j = i; j < MAXN; j += i)
				if (!P[j])
					P[j] = i;
}

void factorials()
{
	F[0] = 1;

	for (int i = 1; i < MAXN; i++)
		F[i] = (F[i - 1] * i) % MOD;

	for (int i = 0; i < MAXN; i++)
		I[i] = binpow(F[i], MOD - 2) % MOD;
}

lli binpow(lli a, lli b)
{
	lli res = 1;

	while (b)
	{
		if (b % 2)
			res = (res * a) % MOD;

		a = (a * a) % MOD;
		b /= 2;
	}

	return res;
}

lli choose(lli n, lli r)
{
	lli ret = (F[n] * I[r]) % MOD;


	return (ret * I[n - r]) % MOD;
}