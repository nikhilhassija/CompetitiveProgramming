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

int check(char);

int main()
{
	int n, m;
	cin >> n >> m;

	string S[n];
	for(int i=0; i<n; i++)
		cin >> S[i];

	int DP[n][3];
	for(int i=0; i<n; i++)
		DP[i][0] = DP[i][1] = DP[i][2] = m;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int d = check(S[i][j]);
			DP[i][d] = min(DP[i][d], min(j, abs(j - m)));
		}
	}

	int ans = 100000;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				if(i != j && j != k && k != i)
				{
					ans = min(ans, DP[i][0] + DP[j][1] + DP[k][2]);
				}
			}
		}
	}

	cout << ans << endl;
}

int check(char x)
{
	if(isalpha(x))
		return 0;

	if(isdigit(x))
		return 1;

	return 2;
}