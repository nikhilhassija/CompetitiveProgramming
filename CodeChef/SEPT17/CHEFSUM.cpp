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
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		pii ans = {1e8, 1e8};

		int i = 0;

		while (n--)
		{
			int x;
			cin >> x;

			ans = min(ans, {x, ++i});
		}

		cout << ans.second << endl;
	}
	
	return (0-0);	
}