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
	int n, m;
	cin >> n >> m;

	int A[2][n + 1];
	mset(A);

	while(m--)
	{
		int x, y;
		cin >> x >> y;

		if(x == 1)
			A[0][y] = 1;

		if(y == n)
			A[1][x] = 1;
	}

	for(int i = 0; i < n; i++)
		if(A[0][i] and A[1][i])
		{
			cout << "POSSIBLE" << endl;
			return 0;
		}

	cout << "IMPOSSIBLE" << endl;
	
	return (0-0);	
}