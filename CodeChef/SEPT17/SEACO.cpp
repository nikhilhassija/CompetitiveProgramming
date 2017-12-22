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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		lli A[n + 1];
		mset(A);

		lli T[m + 1], L[m + 1], R[m + 1];

		for (int i = 1; i <= m; i++)
			cin >> T[i] >> L[i] >> R[i];

		lli C[m + 1];
		mset(C);

		for (int i = 0; i <= m; i++)
			C[i] = 0;

		for (int i = m; i > 0; i--)
		{
			C[i]++;

			if (T[i] == 2)
			{
				C[R[i]] = (C[R[i]] + C[i]) % MOD;
				C[L[i] - 1] = (C[L[i] - 1] - C[i]) % MOD;
			}
			else
			{
				A[R[i]] = (A[R[i]] + C[i]) % MOD;
				A[L[i] - 1] = (A[L[i] - 1] - C[i]) % MOD;
			}

			C[i]--;

			C[i - 1] = (((C[i - 1] + C[i]) % MOD) + MOD) % MOD;
		}

		for (int i = n; i > 0; i--)
			A[i - 1] = (((A[i - 1] + A[i]) % MOD) + MOD) % MOD;

		for (int i = 1; i <= n; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	
	return (0-0);	
}