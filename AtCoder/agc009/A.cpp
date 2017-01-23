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

	lli A[n], B[n];
	for(int i=0; i<n; i++)
		cin >> A[i] >> B[i];

	lli ans = 0;
	for(int i=n-1; i>=0; i--)
		ans += (B[i] - ((A[i] + ans) % B[i])) % B[i];

	cout << ans << endl;
}