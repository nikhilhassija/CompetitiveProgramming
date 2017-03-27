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
	lli a, b;
	cin >> a >> b;

	lli year = 0;

	while(a <= b)
	{
		a *= 3;
		b *= 2;

		year ++;
	}

	cout << year << endl;

	return (0-0);	
}