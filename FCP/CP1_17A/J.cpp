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

const int MAX_N = 2e3 + 5;
const lli MOD = 1e9 + 7;

lli NCR[MAX_N][MAX_N];

void make_ncr();

int main()
{
	make_ncr();

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		lli A[n];
		for(int i=0; i<n; i++)
			cin >> A[i];

		sort(A, A+n);

		lli ans = 0;


		for(int i=0; i<n; i++)
		{
			int l = i;
			int r = (n - i) - 1;
			int m = min(l, r);

			lli num = 0;
			for(int i=0; i<=m; i++)
			{
				num += (NCR[l][i] * NCR[r][i]) % MOD;
				num %= MOD;
			}

			ans += (num * A[i]) % MOD;
			ans %= MOD;
		}

		cout << ans << endl;
	}

	return (0-0);	
}

void make_ncr()
{
	mset(NCR);

	for(int i=0; i<MAX_N; i++)
		NCR[i][0] = 1;

	for(int i=1; i<MAX_N; i++)
		for(int j=1; j<=i; j++)
			NCR[i][j] = (NCR[i-1][j] + NCR[i-1][j-1]) % MOD;
}