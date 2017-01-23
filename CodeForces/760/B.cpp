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

lli SUM(lli);

int main()
{
	lli n, m, k;
	cin >> n >> m >> k;

	m -= n;

	lli ans = 0;
	lli l = 0;
	lli r = m+1;

	lli on_l = k - 1;
	lli on_r = n - k;

	while(l <= r)
	{
		lli mid = (l + r) / 2;

		lli temp = mid + 2ll*SUM(mid-1ll);

		
		if(on_l < mid)
			temp -= SUM((mid - 1) - on_l);

		if(on_r < mid)
			temp -= SUM((mid - 1) - on_r);

		if(temp <= m)
		{
			ans = max(ans, mid);

			l = mid + 1;
		}
		else
		{
			r = mid - 1; 
		}
	}

	ans ++;

	cout << ans << endl;
}

lli SUM(lli n)
{
	return (n*(n+1)) / 2;
}