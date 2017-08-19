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
	int n, k;
	cin >> n >> k;

	int A[n + 1];
	A[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	
	int a = 0;
	int b = 0;

	for (int i = 0; i <= n; i++)
	{
		a += A[i];

		b += min(8, a);

		a -= min(8, a);

		if(b >= k)
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return (0-0);	
}