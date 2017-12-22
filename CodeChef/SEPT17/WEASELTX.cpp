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

vector < vector <int> > G;

int main()
{
	int n = 21;
	int d = 21;

	int A[d][n];

	for (int p = 0; p < n; p++)
	{
		mset(A);

		A[0][p] = 1;

		for (int i = 1; i < d; i++)
		{
			for (int j = n - 1; j > 0; j--)
				A[i][j - 1] = A[i][j] ^ A[i - 1][j - 1];

			cout << A[i][0];
		}
		cout << endl;
	}
	
	return (0-0);	
}