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
	int t;
	cin >> t;

	while(t--)
	{
		lli n, m;
		cin >> n >> m;

		vector <pll> A;
		for(lli i=1; i<n; i++)
		{
			lli x;
			cin >> x;
			A.pb({x, 0});
		}

		for(int i=1; i<m; i++)
		{
			lli x;
			cin >> x;
			A.pb({x, 1});
		}

		sort(A.rbegin(), A.rend());

		lli ans = 0;
		lli C[2] = {1, 1};

		for(int i=0; i<A.size(); i++)
		{
			pll p = A[i];

			ans += p.first * C[1 - p.second];
			C[p.second]++;
		}

		cout << ans << endl;
	}
	return (0-0);	
}