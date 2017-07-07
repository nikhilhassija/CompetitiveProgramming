#include <bits/stdc++.h>

#define mset(x) memset(x, 0, sizeof(x))

using namespace std;

const int MAX_N = 2505;

int n, k;

int m[MAX_N], M[MAX_N], L[MAX_N];

int A[MAX_N][MAX_N];
int C[MAX_N][MAX_N];

int can_union(int, int);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		for(int i=0; i<MAX_N; i++)
			m[i] = 3000;

		mset(M);
		mset(L);
		mset(C);

		cin >> n >> k;

		for(int i=0; i<n; i++)
		{
			cin >> L[i];

			for(int j=0; j<L[i]; j++)
				cin >> A[i][j];
		}

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<L[i]; j++)
			{
				C[i][A[i][j]] = 1;
				m[i] = min(m[i], A[i][j]);
				M[i] = max(M[i], A[i][j]);
			}
		}

		int ans = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				if(can_union(i, j))
				{
					int sum = 0;

					for(int l=1; l<=k; l++)
						sum += (C[i][l] or C[j][l]);

					ans += (sum == k);
				}
			}
		}

		cout << ans << endl;
	}

	return (0-0);	
}

int can_union(int i, int j)
{
	if(min(m[i], m[j]) == 1 and max(M[i], M[j]) == k and (L[i] + L[j] >= k))
		return 1;

	return 0;
}