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
	int n;
	cin >> n;

	lli P[n];
	for(int i=0; i<n; i++)
		cin >> P[i];

	int T[n];
	mset(T);

	priority_queue <pair <lli, int> > Q[4];

	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;

		Q[x].push({-P[i], i});
	}


	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;

		Q[x].push({-P[i], i});
	}

	int q;
	cin >> q;

	while(q--)
	{
		int x;
		cin >> x;

		if(Q[x].empty())
			cout << -1 << " ";
		else
		{
			auto p = Q[x].top();
			Q[x].pop();

			while(!Q[x].empty() && (T[p.second] != 0))
			{
				p = Q[x].top();
				Q[x].pop();
			}

			if(not T[p.second])
			{
				cout << -p.first << " ";
				T[p.second] = 1;
			}
			else
				cout << -1 << " ";
		}
	}
	cout << endl;

	return (0-0);	
}