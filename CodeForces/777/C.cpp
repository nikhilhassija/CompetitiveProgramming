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

int main()
{
	int n, m;
	cin >> n >> m;

	int A[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> A[i][j];

	int S[n][m];
	mset(S);
	for(int j=0; j<m; j++)
	{
		S[0][j] = 1;
		for(int i=1; i<n; i++)
			S[i][j] = S[i-1][j] + (A[i][j] < A[i-1][j]);
	}

	int B[n][m];
	for(int i=0; i<m; i++)
		B[n-1][i] = n-1;

	for(int i=n-2; i>=0; i--)
	{
		for(int j=0; j<m; j++)
		{
			if(S[i][j] == S[i+1][j])
				B[i][j] = B[i+1][j];
			else
				B[i][j] = i;
		}
	}

	int X[n];
	mset(X);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			X[i] = max(X[i], B[i][j]);

	int k;
	cin >> k;

	while(k--)
	{
		int l, r;
		cin >> l >> r;

		l--;
		r--;

		if(r <= X[l])
			printf("Yes\n");
		else
			printf("No\n");
	}
}