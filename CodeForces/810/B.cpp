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
	int n, f;
	cin >> n >> f;

	vector <lli> K(n), L(n);
	for(int i=0; i<n; i++)
		cin >> K[i] >> L[i];

	lli ans = 0;
	for(int i=0; i<n; i++)
	{
		ans += min(K[i], L[i]);
		L[i] -= min(K[i], L[i]); 
	}

	for(int i=0; i<n; i++)
		L[i] = min(L[i], K[i]);

	sort(L.rbegin(), L.rend());

	for(int i=0; i<f; i++)
		ans += L[i];

	cout << ans << endl;
	return (0-0);	
}