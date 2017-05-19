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
	lli n, k;
	cin >> n >> k;

	lli max_n = 1e5 + 5;
	lli A[max_n];
	mset(A);

	while(n--)
	{
		lli x, y;
		cin >> x >> y;

		A[x] += y;
	}

	for(lli i=0; i<max_n; i++)
	{
		k -= A[i];

		if(k <= 0)
		{
			cout << i << endl;
			return 0;
		}
	}
	return (0-0);	
}