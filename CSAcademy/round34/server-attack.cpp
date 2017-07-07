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
	cin >> n;;

	int ans = 0;
	int l = 1e5;

	while(n--)
	{
		int t, x;
		cin >> t >> x;

		if(t == 1)
		{
			l = min(l, x);
		}
		else
		{
			ans += max(0, x - l);
			l = 1e5;
		}
	}

	cout << ans << endl;
	return (0-0);	
}