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
	lli a, b, c, d;
	cin >> a >> b >> c >> d;

	lli t   = 0;
	lli inf = 1e7;

	while(t < inf)
	{
		t++;

		if(t < b or t < d)
			continue;

		if((t - b) % a == 0 and (t - d) % c == 0)
		{
			cout << t << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return (0-0);	
}