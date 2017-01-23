#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0);

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector <pii> A(n);
		for(int i=0;i<n;i++)
			cin >> A[i].first;

		for(int i=0;i<n;i++)
			A[i].second = i;

		sort(A.begin(), A.end());	
		reverse(A.begin(), A.end());

		int R[n];
		for(int i=0;i<n;i++)
			R[A[i].second] = i;

		vector < vector <int> > G(n);


		for(int i=1;i<n;i++)
		{
			int u,v;
			cin >> u >> v;

			u--;
			v--;

			G[u].pb(R[v]	);
			G[v].pb(R[u]	);
		}

		for(int i=0;i<n;i++)
		{
			G[i].pb(R[i]);
			sort(G[i].begin(), G[i].end());

			int k = 0;
			while(G[i][k] == k) k++;

			cout << A[k].second + 1 << " ";
		}

		cout << endl;
	}	
}