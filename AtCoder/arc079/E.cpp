#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

using namespace std;

int main()
{
	lli n;
	cin >> n;

	lli A[n];
	for(int i = 0; i < n; i++)
		cin >> A[i];

	sort(A, A + n);
	reverse(A, A + n);

	lli ans = 0;

	for(int i = 0; i < n; i++)
	{
		if(A[i] >= n)
		{
			lli x = (A[i] + n - 1) / n;
			x--;

			// cout << x << endl;

			ans += (x * n);
		}
	}

	cout << ans << endl;
	
	return (0-0);	
}