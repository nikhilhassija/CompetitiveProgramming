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

lli gety(lli, lli, lli);

int main()
{
	lli m, b;
	cin >> m >> b;

	lli ans = 0;

	for(lli x=0; x<=m*b; x++)
	{
		lli y = gety(x, m, b);
		cout << y << endl;

		lli t = ((x + 1) * (y + 1) * (x + y)) / 2ll;

		ans = max(ans, t);
	}

	cout << ans << endl;

	return (0-0);	
}

lli gety(lli x, lli m, lli b)
{
	return (b * m - x) / m;
}