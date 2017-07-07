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
	freopen("holes.in", "r", stdin);
	freopen("holes.out", "w", stdout);

	int n;
	cin >> n;

	if(not n)
		cout << 1 << endl;
	else
	{
		if(n == 1)
			cout << 0 << endl;
		else
		{
			int d = n / 2;

			if(n % 2)
				cout << 4;

			while(d--)
				cout << 8;
			cout << endl;
		}
	}
	return (0-0);	
}