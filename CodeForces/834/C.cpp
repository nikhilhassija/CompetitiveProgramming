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

int check(lli, lli, lli, lli);

int main()
{
	fastio();

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		lli x, y;
		cin >> x >> y;
		lli p = x * y;
		lli a = cbrt(p);

		if(	check(p, a - 1, x, y) or
			check(p, a + 0, x, y) or
			check(p, a + 1, x, y))
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";
	}
	
	return (0-0);	
}

int inline check(lli p, lli c, lli x, lli y)
{
	if(p == (c * c * c))
	{
		if(x % c or y % c)
			return 0;
		else
			return 1;
	}
	else
		return 0;
}