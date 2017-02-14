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
	int q;
	cin >> q;

	while(q--)
	{
		int n;
		cin >> n;

		int A[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> A[i][j];

		int B[n], M[n];
		memset(B, 0, sizeof(B));
		memset(M, 0, sizeof(M));

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				M[i] += A[i][j];
				B[j] += A[i][j];
			}
		}

		sort(B, B+n);
		sort(M, M+n);

		int f = 1;

		for(int i=0; i<n; i++)
			if(B[i] != M[i])
				f = 0;

		if(f)
			printf("Possible\n");
		else
			printf("Impossible\n");
	}
}