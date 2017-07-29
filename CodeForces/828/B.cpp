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

	string S[n];
	for(int i = 0; i < n; i++)
		cin >> S[i];

	int minx = n;
	int maxx = 0;
	int miny = m;
	int maxy = 0;

	int cnt = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(S[i][j] == 'B')
			{
				minx = min(minx, i);
				maxx = max(maxx, i);

				miny = min(miny, j);
				maxy = max(maxy, j);
		
				cnt++;
			}
		}
	}

	if(cnt == 0)
	{
		cout << 1 << endl;
		return 0;
	}



	int x = maxx - minx + 1;
	int y = maxy - miny + 1;

	int h = max(x, y);

	if(h > min(n, m))
	{
		cout << -1 << endl;
		return 0;
	}

	int ans = (h * h) - cnt;

	cout << ans << endl;

	return (0-0);	
}
