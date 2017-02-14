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
	int q;
	cin >> q;

	while(q--)
	{
		int n, m;
		cin >> n >> m;

		vector < vector <int> > G, g;
		G.resize(n+1);
		g.resize(n+1);

		vector <int> I(n+1, 0);

		for(int i=1; i<=n; i++)
		{
			int x;
			cin >> x;

			I[i] = x;

			while(x--)
			{
				int j;
				cin >> j;

				G[i].pb(j);
				g[j].pb(i);
			}
		}

		queue <int> Q;

		while(m--)
		{
			int x;
			cin >> x;

			Q.push(x);
		}

		vector <int> V(n+1, 0);
		priority_queue <int, vector <int>, greater<int> > H;

		while(!Q.empty())
		{
			auto u = Q.front();
			Q.pop();

			V[u] = 1;

			if(!I[u])
				H.push(u);

			for(int v: G[u])
			{
				if(!V[v])
					Q.push(v);
			}
		}

		vector <int> A;

		while(!H.empty())
		{
			auto u = H.top();
			H.pop();

			if(V[u])
			{
				A.pb(u);
				V[u] = 0;
			}


			for(int v: g[u])
			{
				I[v]--;

				if(!I[v])
					H.push(v);
			}
		}

		cout << A.size() << endl;
		for(int i: A)
			cout << i << " ";

		cout << endl;
	}
}