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

int bad(int);
int N;

int main()
{
	int n, k;
	cin >> n >> k;

	N = n;

	int r, c;
	cin >> r >> c;

	set <pii> S;

	while(k--)
	{
		int x, y;
		cin >> x >> y;

		S.insert({x, y});
	}

	vector <pii> A;
	A.pb({0,1});
	A.pb({0,-1});
	A.pb({1,0});
	A.pb({-1,0});
	A.pb({1,1});
	A.pb({1,-1});
	A.pb({-1,1});
	A.pb({-1,-1});

	lli ans = 0;

	for(int i=0; i<A.size(); i++)
	{
		int dx, dy;
		tie(dx, dy) = A[i];

		int x = r, y = c;

		while(1)
		{
			x += dx;
			y += dy;

			if(bad(x) || bad(y))
				break;

			if(S.find({x, y}) != S.end())
				break;
			else
				ans++;
		}
	}

	cout << ans << endl;
}

int bad(int x)
{
	if(x > 0 and x <= N)
		return 0;
	
	return 1;
}