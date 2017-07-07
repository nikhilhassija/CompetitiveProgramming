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

int main()
{
	fastio();

	int t;
	cin >> t;

	while(t--)
	{
		lli p, q, r;
		cin >> p >> q >> r;

		vector <lli> A(p), B(q), C(r);

		for(int i=0; i<p; i++)
			cin >> A[i];

		for(int i=0; i<q; i++)
			cin >> B[i];

		for(int i=0; i<r; i++)
			cin >> C[i];

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		sort(C.begin(), C.end());

		vector <lli> AS(p+1, 0), BS(q+1, 0), CS(r+1, 0);

		for(int i=0; i<p; i++)
			AS[i+1] = (AS[i] + A[i]) % MOD;

		for(int i=0; i<q; i++)
			BS[i+1] = (BS[i] + B[i]) % MOD;

		for(int i=0; i<r; i++)
			CS[i+1] = (CS[i] + C[i]) % MOD;

		lli ans = 0;

		for(int i=0; i<q; i++)
		{
			lli x = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
			lli y = upper_bound(C.begin(), C.end(), B[i]) - C.begin();

			lli l = (AS[x] + ((x * B[i]) % MOD)) % MOD;
			lli r = (CS[y] + ((y * B[i]) % MOD)) % MOD;

			ans += (l * r) % MOD;
			ans %= MOD;
		} 

		cout << ans << endl;
	}

	return (0-0);	
}