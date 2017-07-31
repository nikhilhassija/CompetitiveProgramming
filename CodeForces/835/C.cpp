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

const int MAX_N = 100 + 5;
const int MAX_C = 10 + 5;

int A[MAX_C][MAX_N][MAX_N];
int DP[MAX_C][MAX_N][MAX_N];

void build();
int query(int, int, int, int, int, int);

int main()
{
	fastio();

	mset(A);
	mset(DP);

	int n, q, c;
	cin >> n >> q >> c;

	while(n--)
	{
		int x, y, s;
		cin >> x >> y >> s;

		A[s][x][y]++;
	}	
	
	build();

	while(q--)
	{
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;

		cout << query(x1 - 1, y1 - 1, x2, y2, t, c + 1) << endl; 
	}

	return (0-0);	
}

void build()
{
	for(int c = 0; c < MAX_C; c++)
	{
		for(int i = 0; i < MAX_N; i++)
			for(int j = 0; j < MAX_N; j++)
				DP[c][i][j] = A[c][i][j];

		for(int i = 0; i < MAX_N; i++)
			for(int j = 1; j < MAX_N; j++)
				DP[c][i][j] += DP[c][i][j - 1];

		for(int i = 1; i < MAX_N; i++)
			for(int j = 0; j < MAX_N; j++)
				DP[c][i][j] += DP[c][i - 1][j];
	}
}

int query(int x1, int y1, int x2, int y2, int t, int c)
{
	int ans = 0;

	for(int i = 0; i < c; i++)
	{
		int n = DP[i][x2][y2] + DP[i][x1][y1] 
				- DP[i][x1][y2] - DP[i][x2][y1];

		ans += ((i + t) % c) * n;
	}

	return ans;
}