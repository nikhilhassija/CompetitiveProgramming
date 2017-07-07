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

lli nc2(lli n);

int main()
{
	map <lli, lli> X, Y;
	map <pll, lli> P;

	int n;
	cin >> n;

	while(n--)
	{
		lli x, y;
		cin >> x >> y;

		X[x]++;
		Y[y]++;
		P[{x, y}]++;
	}	

	lli ans = 0;
	for(auto it: X)
		ans += nc2(it.second);

	for(auto it: Y)
		ans += nc2(it.second);

	for(auto it: P)
		ans -= nc2(it.second);

	cout << ans << endl;

	return (0-0);	
}

lli nc2(lli n)
{
	return (n * (n-1)) / 2;
}