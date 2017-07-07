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

int h, w, n;
int cr;
set <pii> S;

int add_row(int);

int main()
{
	#ifdef ONLINE_JUDGE
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	#else
	// local
	#endif

	cin >> h >> w >> n;
	cr = 0;

	while(n--)
	{
		int x;
		cin >> x;

		auto it = S.upper_bound({x-1, h+1});

		// cout << it->first << " " << it->secbond << 
			// " " << (it == S.end()) << endl;


		if(it == S.end())
		{
			x = add_row(x);
			if(not x)
				cout << -1 << endl;
			else
				cout << x << endl;
		}
		else
		{
			auto p = *it;
			S.erase(it);

			p.first -= x;

			if(p.first)
				S.insert(p);

			cout << p.second << endl;
		}
	}

	return (0-0);	
}

int add_row(int x)
{
	if(cr == h)
		return 0;

	if(x > w)
		return 0;

	cr++;
	pii p = {w-x, cr};

	if(p.first)
		S.insert(p);

	return cr;
}