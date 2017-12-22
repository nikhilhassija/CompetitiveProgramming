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
	lli n, d;
	cin >> n >> d;

	lli cur = 0;
	lli ans = 0;

	while (n--)
	{
		lli x;
		cin >> x;

		cur += x;

		if (cur > d)
		{
			cout << -1 << endl;
			return 0;
		}

		if (x == 0 and cur < 0)
		{
			cur = 0;
			ans++;
		}
	}

	cout << ans << endl;

	return (0-0);	
}