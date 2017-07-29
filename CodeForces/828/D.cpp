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
	int n, e;
	cin >> n >> e;

	vector <int> D(n+1, 0);
	vector <int> E;

	for(int i = 1; i <= e; i++)
		E.pb(i);

	int center = e + 1;

	vector <int> I;

	for(int i = e + 2; i <= n; i++)
		I.pb(i);

	vector <pii> edges;
	for(int i = 0; i < I.size(); i++)
	{
		D[center]++;
		D[I[i]]++;

		edges.pb({center, I[i]});  
	}

	int k = 0;
	for(int i = 0; i < E.size(); i++)
	{
		D[I[k]]++;

		edges.pb({I[k], E[i]});

		k = (k + 1) % I.size();
	}

	vector <int> S;

	for(int i=0; i < I.size(); i++)
	{
		if(D[I[i]] < 2)
		{
			S.pb(I[i]);
		}
	}

	if(S.size() and S.size() % 2)
		S.pb(S[0]);

	for(int i = 0; i < S.size(); i += 2)
		edges.pb(S[i], S[i+1]);

	cout << 3 << endl;
	for(int i = 0; i < edges.size(); i++)
		cout << edges[i].first << " " << edges[i].second << endl;	

	return (0-0);	
}