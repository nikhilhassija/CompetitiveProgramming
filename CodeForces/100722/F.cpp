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
	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		int A[n];

		for (int i = 0; i < n; i++)
			cin >> A[i];

		int C[10];
		mset(C);

		for (int i = 0; i < n; i++)
			C[A[i]]++;

		int k = 9;
		int i = 0;

		int ans = 0;

		while(1)
		{
			while (not C[k])
				k--;

			if (A[i] == k)
			{
				ans++;
				C[k]--;

				if (i == m)
					break;
			}

			i = (i + 1) % n;
		}

		cout << ans << endl;
	}
	
	return (0-0);	
}