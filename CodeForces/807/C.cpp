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
		lli x, y, p, q;
		cin >> x >> y >> p >> q;

		if(x == 0 and p == 0)
		{
			cout << 0 << endl;
			continue;
		}

		if(x != 0 and p == 0)
		{
			cout << -1 << endl;
			continue;
		}

		if(y == 1 and q == 1 and x == p)
		{
			cout << 0 << endl;
			continue;
		}

		if(y != 1 and q == 1)
		{
			cout << -1 << endl;
			continue;
		}

		lli m = (y-x);
		lli n = (q-p);

		lli c1 = (x/p) + (x%p != 0);
		lli c2 = (m/n) + (m%n != 0);
		lli c3 = (y/q) + (y%q != 0);

		lli c = max(c1, max(c2, c3));

		lli b = (c * q) - y;

		if(b)
			cout << b << endl;
		else if(x*q == p*y)
			cout << b << endl;
		else
			cout << -1 << endl;
 	}

	return (0-0);	
}