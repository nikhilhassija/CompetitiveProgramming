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

int n, m, last;

vector <string> A;

int solve(int, int);

int main()
{
	cin >> n >> m;

	A.resize(n);

	for(int i=0; i<n; i++)
		cin >> A[i];

	reverse(A.begin(), A.end());

	last = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(A[i][j+1] == '1')
				last = i;

	cout << solve(0, 0) << endl;

	return (0-0);	
}

int solve(int f, int x)
{
	if(not x)
	{
		int cost = 0;
		for(int i=0; i<m; i++)
			if(A[f][i+1] == '1')
				cost = i + 1;

		int next_l = cost;
		int next_r = (m - cost) + 1;

		if(f == last)
			return cost;

		int l = cost + next_l + solve(f+1, 0) + 1;
		int r = cost + next_r + solve(f+1, 1) + 1;

		return min(l, r);
	}
	else
	{
		int cost = 0;
		for(int i=0; i<m; i++)
		{
			if(A[f][i+1] == '1')
			{
				cost = i + 1;
				break;
			}
		}

		int next_l = cost;

		cost = (m - cost) + 1;

		int next_r = cost;

		if(f == last)
			return cost;

		int l = cost + next_l + solve(f+1, 0) + 1;
		int r = cost + next_r + solve(f+1, 1) + 1;

		return min(l, r);
	}
}