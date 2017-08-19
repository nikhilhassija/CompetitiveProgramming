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

const int MAX_N = 1e6 + 5;
const int MOD = 1e9 + 7;

lli F[MAX_N];
lli P[MAX_N];
set <int> S;
map <int, vector <int> > M;

inline void factor(int x)
{
	for(int i = 1; i < sqrt(x); i++)
	{
		if(x % i == 0)
		{
			M[x].pb(i);
			M[x].pb(x / i);
		}
	}

	int s = sqrt(x);

	if(s * s == x)
		M[x].pb(s);
}

int main()
{
	int n;
	cin >> n;

	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
		S.insert(A[i]);

	for (int i : S)
		factor(i);

	P[0] = 1;
	for (int i = 1; i < MAX_N; i++)
		P[i] = (P[i - 1] * 2) % MOD;

	lli ans = 0;

	for(int i = 0; i < n; i++)
	{
		cerr << A[i] << endl;;
		for(int f: M[A[i]])
		{
			if(f != 1)
			{
				lli x = F[f];

				cerr << f << " " << x << " -- " << (f * (P[x + 1] - 1)) << endl;;

				ans = (ans + ((f * (P[x + 1] - 1)) % MOD));

				F[f]++;
			}
		}
		cerr << endl;
	}

	cout << ans << endl;

	return (0-0);	
}