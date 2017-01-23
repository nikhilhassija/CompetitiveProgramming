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
	int n, h = 0;;
	cin >> n;

	while(n--)	
	{
		int x;
		string S;

		cin >> x >> S;

		if(h == 0 || h == 20000)
		{
			if(S == "East" || S == "West")
			{
				printf("NO\n");
				return 0;
			}
		}

		if(S == "North")
		{
			h -= x;
		}

		if(S == "South")
		{
			h += x;
		}

		if(h < 0 || h > 20000)
		{
			printf("NO\n");
			return 0;
		}
	}

	if(h)
		printf("NO\n");
	else
		printf("YES\n");
}