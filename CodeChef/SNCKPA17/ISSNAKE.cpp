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

	while(t--)
	{
		int n;
		cin >> n;

		string S[2];
		cin >> S[0] >> S[1];

		int sx, sy;

		for(int i=0; i<n; i++)
		{
			if(S[0][i] == '#')
			{
				sx = 0;
				sy = i;
				break;
			}

			if(S[1][i] == '#')
			{
				sx = 1;
				sy = i;
				break;
			}
		}

		S[sx][sy] = '.';
		stack <pii> D;

		int x = sx, y = sy;

		if(D.empty() and not x)
		{
			if(S[x+1][y] == '#')
			{
				D.push({x+1, y});
				S[x+1][y] = '.';
			}
		}

		if(D.empty() and x)
		{
			if(S[x-1][y] == '#')
			{
				D.push({x-1, y});
				S[x-1][y] = '.';
			}
		}

		if(D.empty() and y)
		{
			if(S[x][y-1] == '#')
			{
				D.push({x, y-1});
				S[x][y-1] = '.';
			}
		}

		if(D.empty() and y != n-1)
		{
			if(S[x][y+1] == '#')
			{
				D.push({x, y+1});
				S[x][y+1] = '.';
			}
		}

		while(!D.empty())
		{
			auto p = D.top();
			D.pop();

			int x, y;
			tie(x, y) = p;

			if(y and S[x][y-1] == '#')
			{
				D.push({x, y-1});
				S[x][y-1] = '.';
			}

			else if(y != n-1 and S[x][y+1] == '#')
			{
				D.push({x, y+1});
				S[x][y+1] = '.';
			}

			else if(not x and S[x+1][y] == '#')
			{
				D.push({x+1, y});
				S[x+1][y] = '.';
			}

			else if(x and S[x-1][y] == '#')
			{
				D.push({x-1, y});
				S[x-1][y] = '.';
			}
		}

		x = sx, y = sy;

		if(D.empty() and not x)
		{
			if(S[x+1][y] == '#')
			{
				D.push({x+1, y});
				S[x+1][y] = '.';
			}
		}

		if(D.empty() and x)
		{
			if(S[x-1][y] == '#')
			{
				D.push({x-1, y});
				S[x-1][y] = '.';
			}
		}

		if(D.empty() and y)
		{
			if(S[x][y-1] == '#')
			{
				D.push({x, y-1});
				S[x][y-1] = '.';
			}
		}

		if(D.empty() and y != n-1)
		{
			if(S[x][y+1] == '#')
			{
				D.push({x, y+1});
				S[x][y+1] = '.';
			}
		}

		while(!D.empty())
		{
			auto p = D.top();
			D.pop();

			int x, y;
			tie(x, y) = p;

			if(y and S[x][y-1] == '#')
			{
				D.push({x, y-1});
				S[x][y-1] = '.';
			}

			else if(y != n-1 and S[x][y+1] == '#')
			{
				D.push({x, y+1});
				S[x][y+1] = '.';
			}

			else if(not x and S[x+1][y] == '#')
			{
				D.push({x+1, y});
				S[x+1][y] = '.';
			}

			else if(x and S[x-1][y] == '#')
			{
				D.push({x-1, y});
				S[x-1][y] = '.';
			}
		}

		int f = 0;
		for(int i=0; i<2; i++)
			for(int j=0; j<n; j++)
				f += (S[i][j] == '#');

		if(f)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
}