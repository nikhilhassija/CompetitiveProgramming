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
	int t = 240;
	int n, k;
	cin >> n >> k;

	t -= k;
	int sum = 0;
	int i=0;

	while(t > 0)
	{
		t -= 5*i;

		if(t>0)
			i++;
	}

	if(t != 0)
		i--;

	cout << min(n, i) << endl;
}