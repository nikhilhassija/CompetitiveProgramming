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
	int n, k, m;
	cin >> n >> k >> m;

	vector < vector < int > > A;

	A.resize(m);

	while (n--)
	{
		int x;
		cin >> x;

		A[x % m].pb(x);
	}

	for (int i = 0; i < m; i++)
	{
		if (A[i].size() >= k)
		{
			cout << "Yes" << endl;
			for (int j = 0; j < k; j++)
				cout << A[i][j] << " ";
			cout << endl;

			return 0;
		}
	}

	cout << "No" << endl;
	
	return (0-0);	
}