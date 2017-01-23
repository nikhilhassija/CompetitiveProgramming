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
	lli n, m, k, x, y;
	cin >> n >> m >> k >> x >> y;

	x--;
	y--;


	if(n == 1)
	{
		lli rounds = k / m;
		lli left = k % m;

		lli A[m];

		for(int j=0; j<m; j++)
			A[j] = rounds;

		int i = 0;

		while(left--)
		{
			A[i]++;
			i++;

			i %= m; 
		}

		lli mn = k, mx = 0, a;
		for(int i=0; i<m; i++)
		{
			mn = min(mn, A[i]);
			mx = max(mx, A[i]);
		}

		a = A[y];

		printf("%lld %lld %lld\n", mx, mn, a);
	}
	else
	{
		lli r_stud = (2*n - 2) * m;
		lli rounds = k / (r_stud);
		lli left   = k % (r_stud);

		lli A[n][m];
		mset(A);

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				A[i][j] += 2*rounds;

				if(i == (n-1) || i == 0)
					A[i][j] = rounds;
			}
		}

		int di = 1;
		int i = 0;
		int j = 0;

		while(left--)
		{
			A[i][j] ++;

			j++;

			if(j == m)
			{
				j = 0;

				i += di;

				if(i == -1)
				{
					i = 1;
					di = 1;
				}
				if(i == n)
				{
					i = n-2;
					di = -1;
				}	
			}
		}
	
		lli mn = k, mx = 0, a;

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				mn = min(mn, A[i][j]);
				mx = max(mx, A[i][j]);
			}
		}

		a = A[x][y];

		printf("%lld %lld %lld\n", mx, mn, a);
	}
}