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
	lli n, k;
	cin >> n >> k;

	lli ans = 0;

	lli l = 0;
	lli h = n;

	while(l <= h)
	{
		lli m = (l + h) / 2;

		if(m <= (n / (2 * (k+1))))
		{
			ans = max(ans, m);
			l = m + 1;
		}
		else
			h = m - 1;
	}

	cout << ans << " ";
	cout << (ans * k) << " ";
	cout << (n - (ans * (k + 1))) << endl;

	return (0-0);	
}