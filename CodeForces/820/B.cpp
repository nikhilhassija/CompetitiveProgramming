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
	int n, a;
	cin >> n >> a;

	double total = (n-2) * 180.0F;
	double angle = total / n;

	float min_diff = abs(angle - a);
	int min_index = 2;	

	for(int i=1; i<n-2; i++)
	{	
		total -= 180;

		float cur = total - (n - 2 - i) * angle;
		cur /= 2;

		if(abs(cur - a) < min_diff)
		{
			min_index = i + 2;
			min_diff = abs(cur - a);
		}
	}

	printf("%d %d %d\n", 1, min_index, min_index+1);

	return (0-0);	
}