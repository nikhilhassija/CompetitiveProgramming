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
	int n;
	cin >> n;

	int e = 0, o = 0;

	while(n--)
	{
		int x;
		cin >> x;

		if(x%2)
			o++;
		else
			e++;
	}

	if(o%2)
	{
		if(e == 0 && o == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
		printf("YES\n");
}