#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0)
#define DEBUG 0

using namespace std;

const lli inf = 1e17;

int main()
{
	int _t;
	cin >> _t;

	for(int t = 1; t <= _t; t++)
	{
		int n, m;
		cin >> n >> m;

		lli A[n+1][m+1];

		for(int i = 1; i <= n; i++)
		{
			A[i][0] = 0;

			for(int j = 0; j < m; j++)
				cin >> A[i][j+1];

			sort(A[i] + 1, A[i] + m + 1);
		}

		lli DP[n+1][n+1];
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				DP[i][j] = inf;

		DP[0][0] = 0;

		for(int i = 1; i <= n; i++)
		{
			if(DEBUG)
			{
				printf("Day %d\n", i);
			}
		
			lli C[m+1];
			C[0] = 0;

			for(int j = 1; j <= m; j++)
				C[j] = C[j-1] + A[i][j];

			for(int j = 1; j <= m; j++)
				C[j] += j * j;

			if(DEBUG)
			{
				for(int i=0; i<=m;i++)
					cout << C[i] << " ";
				cout << endl;
			}

			for(int j = i - 1; j <= n; j++)
			{
				if(DP[i-1][j] != inf)
				{
					if(DEBUG)
					{
						printf("Candies %d\n", j);
					}
					
					for(int k = 0; k <= m && j + k <= n; k++)
					{
						DP[i][j + k] = min(DP[i][j + k], DP[i-1][j] + C[k]);

						if(DEBUG)
						{
							printf("New Candies %d = %lld\n", j+k, DP[i][j+k]);
						}
					}
				}
			}
		}
		
		if(DEBUG)
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
				{
					if(DP[i][j] == inf)
						break;

					printf("%lld ", DP[i][j]);
				}
				cout << endl;
			}
		}

		printf("Case #%d: %lld\n", t, DP[n][n]);
	}
}