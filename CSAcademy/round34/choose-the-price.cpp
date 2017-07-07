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
	lli n;
	cin >> n;

	lli C[n];
	for(int i=0; i<n; i++) 
		cin >> C[i];

	sort(C, C+n);
	reverse(C, C+n);

	lli sum = 0;
	lli ans = 0;
	for(int i=0; i<n; i++)
	{
		ans = max(ans, C[i] * (i + 1));
	}

	cout << ans << endl;
	return (0-0);	
}