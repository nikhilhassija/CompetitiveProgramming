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
	int n;
	cin >> n;

	int A[n][n];
	mset(A);

	for(int i = 0; i < n; i++)
		A[0][i] = 1 ^ (i % 2);

	for(int i = 1; i < n; i++)
		for(int j = 0; j < n; j++)
			A[i][j] = 1 ^ A[i-1][j];

	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			ans += A[i][j];

	cout << ans << endl;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(A[i][j])
				cout << "C";
			else
				cout << ".";
		}

		cout << endl;
	}
	return (0-0);	
}