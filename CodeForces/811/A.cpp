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
	int a, b;
	cin >> a >> b;

	int t = 1;

	while(1)
	{
		if(t % 2)
		{
			if(a < t)
			{
				cout << "Vladik" << endl;
				return 0;
			}
			else
				a -= t;
		}
		else
		{
			if(b < t)
			{
				cout << "Valera" << endl;
				return 0;
			}
			else
				b -= t;
		}
		t++;
	}

	return (0-0);	
}