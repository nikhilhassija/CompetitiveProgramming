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

const int MAX_N = 5e3 + 5;

int main()
{
	int n;
	cin >> n;

	int A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	int L[MAX_N], R[MAX_N];
	for(int i=0; i<MAX_N; i++)
	{
		L[i] = MAX_N + 5;
		R[i] = -1;
	}

	for(int i=0; i<n; i++)
	{
		L[A[i]] = min(L[A[i]], i);
		R[A[i]] = max(R[A[i]], i);
	}

	int DP[n+1][n+1];
	mset(DP);

	DP[0][0] = (R[A[0]] == 0) * A[0];
	for(int i=1; i<n; i++)
	{
		DP[0][i] = DP[0][i-1];

		if(R[A[i]] == i)
			DP[0][i] ^= A[i];
	}

	for(int i=1; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			DP[i][j] = DP[i][j-1];

			if(R[A[j]] == j)
			{
				if(i <= L[A[j]])
					DP[i][j] = DP[i][j] ^ A[j];
				else
					DP[i][j] = 0;
			}

			if(L[A[j]] < i)
				DP[i][j] = 0;
		}
	}


	for(int i=1; i<n; i++)
	{
		int prev = 0;
		for(int j=0; j<i; j++)
			prev = max(prev, DP[j][i-1]);

		for(int j=i; j<n; j++)
			DP[i][j] += prev;
	}

	int ans = 0;
	for(int i=0; i<n; i++)
		ans = max(ans, DP[i][n-1]);

	cout << ans << endl;

	return (0-0);	
}
