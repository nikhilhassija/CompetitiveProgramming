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
		
	lli M;
	cin >> M;

	lli T[k];
	for (int i = 0; i < k; i++)
		cin >> T[i];

	sort(T, T + k);

	lli sum = 0;
	for (int i = 0; i < k; i++)
		sum += T[i];

	lli ans = 0;

	for (int i = 0; i <= n; i++)
	{
		lli tot = i * sum;

		if (tot > M)
			continue;

		lli points = (k + 1) * i;

		for (int j = 0; j < k; j++)
		{
			for (int x = i + 1; x <= n; x++)
			{
				if (tot + T[j] > M)
					break;
				else
				{
					tot += T[j];
					points++;

					if (j == k - 1)
						points++;
				}
			}
		}

		ans = max(ans, points);
	}

	cout << ans << endl; 

	return (0-0);	
}