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

const int MAX_N = 1e5;
const lli MOD   = 1e9 + 7;

void seive();
lli  binpow(lli, lli);

vector <lli> P;
map <lli, lli> M;

int main()
{
	seive();

	int n;
	cin >> n;

	lli A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	for(auto i: A)
	{
		for(auto j: P)
		{
			while(i % j == 0)
			{
				M[j]++;
				i /= j;
			}
		}

		if(i > 1)
			M[i]++;
	}

	lli ans = 1;
	int flg = 1;

	for(auto it: M)
	{
		auto a = it.first;
		auto b = it.second;

		if(b % n)
			flg = 0;

		ans *= binpow(a, ((n+1) - (b % (n+1))) % (n + 1));
		ans %= MOD;
	}

	if(flg)
		cout << "justdoit" << endl;
	else
		cout << ans << endl;

	return (0-0);	
}

void seive()
{
	int A[MAX_N];
	mset(A);

	for(int i=2; i<MAX_N; i++)
	{
		if(not A[i])
		{
			P.pb(i);

			for(int j=2*i; j<MAX_N; j += i)
				A[j] = 1;
		}
	}
}

lli binpow(lli a, lli b)
{
	lli res = 1;

	while(b)
	{
		if(b % 2)
			res = (res * a) % MOD;

		a = (a * a) % MOD;
		b = (b / 2);
	}

	return res;
}