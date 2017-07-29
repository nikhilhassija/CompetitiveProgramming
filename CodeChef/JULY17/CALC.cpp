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
		lli n, b;
		cin >> n >> b;

		lli x = n / (2 * b);
		lli ans = 0;

		for(lli i=max(x-10, 0ll); i<x+10; i++)
			ans = max((n - i*b) * i, ans);

		cout << ans << endl;
	}

	return (0-0);	
}