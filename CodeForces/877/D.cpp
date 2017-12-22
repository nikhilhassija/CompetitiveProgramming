#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0); cin.tie(NULL)

#ifdef LOCAL
struct timer
{
	~timer()
	{
		std::cerr << "Time: " << (double) std::clock() / CLOCKS_PER_SEC << "s" << std::endl;
	}
} timer;
#endif

using namespace std;

int n, m, k;

int DP[1001][1001][2];

vector < string > S; 

bool good(int, int);
int bfs(int, int, int, int);

int main()
{
	cin >> n >> m >> k;

	S.resize(n);

	for (int i = 0; i < n; i++)
		cin >> S[i];
	
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	memset(DP, -1, sizeof(DP));

	cout << bfs(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endl;

	return (0-0);	
}

bool good(int x, int y)
{
	return (x >= 0) and (x < n) and (y >= 0) and (y < m);
}

int bfs(int x1, int y1, int x2, int y2)
{
	queue < pair <pii, int > > Q;

	Q.push({{x1, y1}, 0});

	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};

	while (!Q.empty())
	{
		auto p = Q.front();
		Q.pop();

		int curx, cury;
		tie(curx, cury) = p.first;

		if (curx == x2 and cury == y2)
			return p.second;

		for (int dir = 0; dir < 4; dir++)
		{
			int i = curx;
			int j = cury;

			for (int l = 1; l <= k; l++)
			{
				i += dx[dir];
				j += dy[dir];

				if (good(i, j) and S[i][j] != '#' and DP[i][j][dir % 2] == -1)
				{
					DP[i][j][dir % 2] = p.second + 1;
					Q.push({{i, j}, p.second + 1});
				}
				else
					break;
			}
		}
	}

	return -1;
}