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
	int n, m;
	cin >> n >> m;

	string a, b;
	cin >> a >> b;

	int DP[m][n];
	mset(DP);

	for(int i=0; i<=(m-n); i++)
	{
		DP[i][0] = (a[0] != b[i]);

		for(int j=1; j<n; j++)
			DP[i][j] = DP[i][j-1] + (a[j] != b[i+j]);
	}

	int ans = n + 1;
	int idx = 0;

	for(int i=0; i<=(m-n); i++)
	{
		if(ans > DP[i][n-1])
		{
			ans = min(ans, DP[i][n-1]);
			idx = i;
		}
	}

	cout << ans << endl;

	if(DP[idx][0])
		cout << 1 << " ";

	for(int i=1; i<n; i++)
		if(DP[idx][i] > DP[idx][i-1])
			cout << i + 1 << " ";
	cout << endl;

	return (0-0);	
}