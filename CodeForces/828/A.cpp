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
	int n, a, b;
	cin >> n >> a >> b;

	int ans = 0;
	int c = 0;

	while(n--)
	{
		int x;
		cin >> x;

		if(x == 2)
		{
			if(b)
				b--;
			else
				ans += 2;
		}
		else
		{
			if(a)
			{
				a--;
			}
			else
			{
				if(b)
				{
					b--;
					c++;
				}
				else if(c)
					c--;
				else
					ans++;
			}
		}
	}

	cout << ans << endl;

	return (0-0);	
}