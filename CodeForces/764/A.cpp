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
	lli a, b, z;
	cin >> a >> b >> z;

	lli l = a*b;
	l /= __gcd(a,b);

	lli ans = z / l;

	cout << ans << endl;	
}