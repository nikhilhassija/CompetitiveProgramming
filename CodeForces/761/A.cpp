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
	int e, o;
	cin >> e >> o;

	if(!e && !o)
	{
		printf("NO\n");
		return 0;
	}

	int d = abs(e - o);
	if(d < 2)
		printf("YES\n");
	else
		printf("NO\n");	
}