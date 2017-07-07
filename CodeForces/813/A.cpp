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
	int n;
	cin >> n;

	int x;
	int s = 0;
	while(n--)
	{
		cin >> x;
		s += x;
	}

	int m, l, r;
	cin >> m;

	while(m--)
	{
		cin >> l >> r;
		if(l <= s and s <= r)
		{
			cout << s << endl;
			return 0;
		}

		if(s <= l)
		{
			cout << l << endl;
			return 0;
		}
	}

	cout << -1 << endl;	

	return (0-0);	
}