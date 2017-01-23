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

	int A[n];
	for(int i=0; i<n; i++)
		cin >> A[i];

	int m = 0;
	for(int i=0; i < n; i++)
		m = max(m, A[i]);

	int ans = 0;
	for(int i=0; i< n; i++)
		ans += m - A[i];

	cout << ans << endl;
}