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

vector < vector <int> > C;
vector <int> P;
vector <lli> W;

lli A[105][105];
lli T[105][105];
int F[105][105];

lli addacorn(int, lli, lli);
lli birdsit(int, lli);
lli dfs(int, int);

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n, m;
		cin >> n >> m;

		if(n > 100)
			return 0;

		mset(A);
		mset(F);
		mset(T);

		C.clear();
		P.clear();
		W.clear();

		C.resize(n+1);
		P.resize(n+1);
		W.resize(n+1);

		W[0]= 1e18;

		for(int i=1; i<=n; i++)
		{
			cin >> P[i] >> W[i];
			C[P[i]].pb(i);
		}

		for(int s=1; s<=m; s++)
		{
			int p;
			cin >> p;

			for(int i=1; i<=n; i++)
			{
				A[s][i] = A[p][i];
				F[s][i] = F[p][i];
				T[s][i] = T[p][i];
			}

			int q;
			cin >> q;

			if(q == 1)
			{
				lli u, w;
				cin >> u >> w;

				cout << addacorn(s, u, w) << endl;
			}
			else
			{
				lli u;
				cin >> u;

				cout << birdsit(s, u) << endl;
			}

			dfs(s, 0);

			T[s][0] = 0;
			F[s][0] = 0;
		}
	}

	return (0-0);	
}

lli addacorn(int s, lli u, lli w)
{
	A[s][u] += w;

	while(u)
	{
		T[s][u] += w;

		if(T[s][u] > W[u])
		{
			F[s][u] = 1;
			return u;
		}

		u = P[u];
	}

	return 0;
}

lli birdsit(int s, lli u)
{
	lli ret = T[s][u];

	queue <int> Q;
	Q.push(u);

	while(not Q.empty())
	{
		u = Q.front();
		Q.pop();

		T[s][u] = 0;
		A[s][u] = 0;
		for(int i=0; i<C[u].size(); i++)
			Q.push(C[u][i]);
	}

	return ret;
}

lli dfs(int s, int u)
{
	if(F[s][u])
	{
		T[s][u] = 0;
		A[s][u] = 0;
		return 0;
	}

	lli ans = A[s][u];
	for(int i=0; i<C[u].size(); i++)
		ans += dfs(s, C[u][i]);

	T[s][u] = ans;
	return ans;
}