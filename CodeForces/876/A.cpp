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

int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	n -= 2;

	int ans = min(a, b) + min(a, min(b, c)) * n;

	cout << ans << endl;

	return (0-0);	
}