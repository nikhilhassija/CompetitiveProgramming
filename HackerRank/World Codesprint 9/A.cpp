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
		int x;
		cin >> x;

		if(x < 38)
			cout << x << endl;
		else
		{
			int r = 5 - (x % 5);

			if(r < 3)
				x += r;

			cout << x << endl;
		}
	}	
}