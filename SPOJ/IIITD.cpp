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
		int n;
		cin >> n;

		int ans = 0;

		if(n < 0)
		{
			n *= -1;
			ans += 2 * n;
		}

		ans += pow(10, (int(log10(n+0.9))));

		cout << ans << endl;
	}
	return (0-0);	
}