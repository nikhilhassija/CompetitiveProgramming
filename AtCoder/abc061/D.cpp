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
	lli n, m;
	cin >> n >> m;

	vector < pair <pll, lli> > E;

	while(m--)
	{
		lli x, y, w;
		cin >> x >> y >> w;

		E.pb({{x, y}, w});
	}

	lli inf = - (1e17);

	lli D[n+1];
	for(int i=0; i<=n; i++)
		D[i] = inf;

	D[1] = 0;

	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<E.size(); j++)
		{
			lli x, y, w;

			tie(x, y) = E[j].first;
			w = E[j].second;

			D[y] = max(D[y], D[x] + w);
 		}
	}

	lli ans = D[n];

	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<E.size(); j++)
		{
			lli x, y, w;

			tie(x, y) = E[j].first;
			w = E[j].second;

			D[y] = max(D[y], D[x] + w);
 		}
	}

	if(D[n] > ans)
		cout << "inf" << endl;
	else
		cout << ans << endl;


	return (0-0);	
}