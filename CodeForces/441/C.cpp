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

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	int t = 0;
	int i = 0;
	int j = 0;

	int A[n][m];
	mset(A);

	for(int x = 0; x < n * m; x++)
	{
		A[i][j] = ++t;

		if(j != m - 1 and not A[i][j + 1])
		{
			j++;
			continue;
		}

		if(j and not A[i][j - 1])
		{
			j--;
			continue;
		}

		i++;
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			A[i][j] = min((A[i][j] + 1) / 2, k);

	for(int c = 1; c <= k; c++)
	{
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				ans += (A[i][j] == c);

		cout << ans << " ";
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(A[i][j] == c)
					cout << i + 1 << " " << j + 1 << " ";

		cout << endl;
	}

	return (0-0);	
}