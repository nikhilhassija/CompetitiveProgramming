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
	lli r, g, b;
	cin >> r >> g >> b;

	lli m = max(r, max(g, b));

	if(m > 2 * (r + g + b - m))
		cout << (r + g + b - m) << endl;
	else
		cout << (r + g + b) / 3 << endl;
	
	return (0-0);	
}