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
const lli p = 997;

const lli MAX_N = 5e3 + 5;

lli P[MAX_N];
lli I[MAX_N];

lli HP[MAX_N];
lli HS[MAX_N];

int K[MAX_N];
int n;

unordered_map <lli, int> M;

lli binpow(lli, lli, lli);
lli prehash(int, int);
lli sufhash(int, int);

int work(int, int);

int main()
{
	fastio();

	P[0] = 1;
	for(int i = 1; i < MAX_N; i++)
		P[i] = (P[i - 1] * p) % MOD;

	for(int i = 0; i < MAX_N; i++)
		I[i] = binpow(P[i], MOD - 2, MOD);

	string S;
	cin >> S;

	n = S.size();

	HP[0] = S[0];
	for(int i = 1; i < n; i++)
		HP[i] = (HP[i - 1] + ((S[i] * P[i]) % MOD)) % MOD;

	HS[0] = S[n - 1];
	for(int i = 1; i < n; i++)
		HS[i] = (HS[i - 1] + ((S[n - 1 - i] * P[i]) % MOD)) % MOD;

	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			lli p = prehash(i, j);
			lli s = sufhash(i, j);

			if(p == s)
			{
				int k;

				if(M.find(p) != M.end())
					k = M[p];
				else
				{
					k = work(i, j);
					M[p] = k;
				}

				K[k]++;
			}
		}
	}

	for(int i = MAX_N - 1; i > 0; i--)
		K[i - 1] += K[i];

	for(int i = 0; i < n; i++)
		cout << K[i] << " ";
	cout << endl;

	return (0-0);	
}

lli binpow(lli a, lli b, lli m)
{
	lli r = 1;

	while(b)
	{
		if(b % 2)
			r = (r * a) % m;

		a = (a * a) % m;
		b = b / 2;
	}

	return r;
}

lli prehash(int l, int r)
{
	if(not l)
		return HP[r];

	lli x = (HP[r] - HP[l - 1] + MOD) % MOD;

	x = (x * I[l]) % MOD;

	return x; 
}

lli sufhash(int l, int r)
{
	if(r == n - 1)
		return HS[n - 1 - l];

	lli x = (HS[n - 1 - l] - HS[n - 2 - r] + MOD) % MOD;
	
	x = (x * I[n - 1 - r]) % MOD;

	return x;
}

int work(int l, int r)
{
	int len = r - l + 1;

	if(len == 1)
		return 0;

	int l1 = l;
	int r1 = l + (len / 2) - 1;

	int l2 = r - (len / 2) + 1;
	int r2 = r; 

	if(prehash(l1, r1) == prehash(l2, r2))
		return work(l1, r1) + 1;
	else
		return 0;
}