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

	if(a < c && b < d)
	{
		cout << -1 << endl;
		return 0;
	}

	if(b > d)
	{
		swap(b, d);
		swap(a, c);
	}


	if(b == d)
		cout << b << endl;
	else
		cout << -1 << endl;

	return (0-0);	
}