#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0);

using namespace std;

int main()
{
	lli t;
	cin >> t;

	while(t--)
	{
		lli c, d, l;
		cin >> c >> d >> l;

		l -= d * 4;

		if(l < 0 || l % 4)
			printf("no\n");
		else
		{
			lli cats = l / 4;

			if(cats > c)
			{
				printf("no\n");
			}
			else
			{
				lli def = c - cats;

				if(def > 2*d)
					printf("no\n");
				else
					printf("yes\n");
			}
		}
	}	
}
