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
	int m, w;
	cin >> m >> w;

	int d;
	switch(m)
	{
		case 1: d = 31; break;
		case 2: d = 28; break;
		case 3: d = 31; break;
		case 4: d = 30; break;
		case 5: d = 31; break;
		case 6: d = 30; break;
		case 7: d = 31; break;
		case 8: d = 31; break;
		case 9: d = 30; break;
		case 10: d = 31; break;
		case 11: d = 30; break;
		case 12: d = 31; break;
	}

	d += w-1;

	int ans = d / 7 + (d % 7 != 0);

	cout << ans << endl;
}