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
	int n, t, k, d;
	cin >> n >> t >> k >> d;

	int iter = (n / k) + (n % k != 0);

	int time1 = iter * t;

	int cake = 0;
	int first = t; 
	int sec = d + t;

	for(int i=0; i<time1; i++, first--, sec--)
	{
		if(not first)
		{
			cake += k;
			first = t;
		}

		if(not sec)
		{
			cake += k;
			sec = t;
		}

		if(cake >= n)
		{
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");

	return (0-0);	
}