#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		lli ans = 0;
		lli n,b,m;
		cin >> n >> b >> m;

		while(n)
		{
			ans += (n/2)*m;

			if(n%2)
				ans += m;

			n /= 2;

			if(n)
			{
				ans += b;
				m *=2;
			}
			else
				break;
		}

		printf("%lld\n",ans);
	}
}