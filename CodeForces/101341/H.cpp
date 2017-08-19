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

int ans = 1e9 + 5;
pii cord = {-1, -1};

void check(pair <int, pii>);

int main()
{
	fastio();

	int n, m;
	cin >> n >> m;

	int A[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> A[i][j];

	int DR[n][m];
	int DL[n][m];
	int UR[n][m];
	int UL[n][m];

	DR[0][0] = A[0][0];
	for(int i = 1; i < n; i++)
		DR[i][0] = max(DR[i - 1][0], A[i][0]);

	for(int i = 1; i < m; i++)
		DR[0][i] = max(DR[0][i - 1], A[0][i]);

	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++)
			DR[i][j] = max(A[i][j], 
						max(DR[i][j - 1], 
							DR[i - 1][j]));

	DL[0][m - 1] = A[0][m - 1];
	for(int i = m - 2; i >= 0; i--)
		DL[0][i] = max(A[0][i], DL[0][i + 1]);

	for(int i = 1; i < n; i++)
		DL[i][m - 1] = max(A[i][m - 1], DL[i - 1][m - 1]);

	for(int i = 1; i < n; i++)
		for(int j = m - 2; j >= 0; j--)
			DL[i][j] = max(A[i][j], 
						max(DL[i - 1][j], 
							DL[i][j + 1]));

	UR[n - 1][0] = A[n - 1][0];
	for(int i =  n - 2; i >= 0; i--)
		UR[i][0] = max(UR[i + 1][0], A[i][0]);

	for(int i = 1; i < m; i++)
		UR[n - 1][i] = max(UR[n - 1][i - 1], A[n - 1][i]);

	for(int i = n - 2; i >= 0; i--)
		for(int j = 1; j < m; j++)
			UR[i][j] = max(A[i][j],
						max(UR[i + 1][j],
							UR[i][j - 1]));

	UL[n - 1][m - 1] = A[n - 1][m - 1];
	for(int i = n - 2; i >= 0; i--)
		UL[i][m - 1] = max(A[i][m - 1], UL[i + 1][m - 1]);

	for(int i = m - 2; i >= 0; i--)
		UL[n - 1][i] = max(A[n - 1][i], UL[n - 1][i + 1]);

	for(int i = n - 2; i >= 0; i--)
		for(int j = m - 2; j >= 0; j--)
			UL[i][j] = max(A[i][j], 
						max(UL[i + 1][j],
							UL[i][j + 1]));



	check({UL[1][1], {0, 0}});
	check({UR[1][m - 2], {0, m - 1}});
	check({DL[n - 2][1], {n - 1, 0}});
	check({DR[n - 2][m - 2], {n - 1, m - 1}});

	for(int i = 1; i < m - 1; i++)
	{
		check({max(UR[1][i - 1], UL[1][i + 1]), {0, i}});
		check({max(DR[n - 2][i - 1], DL[n - 2][i + 1]), {n - 1, i}});
	}

	for(int i = 1; i < n - 1; i++)
	{
		check({max(DL[i - 1][1], UL[i + 1][1]), {i, 0}});
		check({max(DR[i - 1][m - 2], UR[i + 1][m - 2]), {i, m - 1}});
	}

	for(int i = 1; i < n - 1; i++)
		for(int j = 1; j < m - 1; j++)
		{
			int x = max(max(DR[i - 1][j - 1], DL[i - 1][j + 1]), 
						max(UR[i + 1][j - 1], UL[i + 1][j + 1]));
			check({x, {i, j}});
		}

	int x, y;

	tie(x, y) = cord;

	cout << x + 1 << " " << y + 1 << endl;


	return (0-0);	
}

void check(pair <int, pii > x)
{
	int a = x.first;
	pii c = x.second;

	if(a < ans)
	{
		ans = a;
		cord = c;
	}
}