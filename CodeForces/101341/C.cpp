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

int check(lli, lli, lli, lli, lli, lli);

int main()
{
	lli a, b, c;
	cin >> a >> b >> c;

	lli n, m;
	cin >> n >> m;

	lli l = 0;
	lli h = a + b + c;

	lli ans = 0;

	while(l <= h)
	{
		lli mid = (l + h) / 2;

		if(check(a, b, c, n, m, mid))
		{
			l = mid + 1;
			ans = max(ans, mid);
		}
		else
			h = mid - 1;
	}

	cout << ans << endl;
	
	return (0-0);	
}

int check(lli a, lli b, lli c, lli n, lli m, lli x)
{
	lli num_red = min(a + c, x);
	lli num_green = min(b + c, x);

	if(num_green > m)
		return 0;

	if(num_red > n)
		return 0;

	if((a + b + c) < x)
		return 0;

	return 1;
}