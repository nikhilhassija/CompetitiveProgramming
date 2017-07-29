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

const int MAX_N = 1e5 + 5;

int n, m;

int T[100 * MAX_N][3];
int node = 1;

vector < vector <pii> > G;

vector < pair <pii, int> > Q(MAX_N);

vector < int > C(MAX_N, 0);
vector < vector <int> > K;

vector < int > V(MAX_N, 0);

unordered_map <lli, int> M;

void magic();

void dfs(int);

void bin(int *, int);

void update(int);
int  query(int);

lli code(int, int);

int main()
{
	fastio();

	int t;
	cin >> t;

	T[0][0] = T[0][1] = T[0][2] = 0;

	while(t--)
	{
		cin >> n;

		G.clear();
		G.resize(n + 1);

		for(int i = 1; i < n; i++)
		{
			int u, v, c;
			cin >> u >> v >> c;

			G[u].pb({v, c});
			G[v].pb({u, c});
		}

		cin >> m;

		for(int i = 0; i < m; i++)
		{
			cin >> Q[i].first.first
				>> Q[i].first.second
				>> Q[i].second;

			C[Q[i].first.first]++;
			C[Q[i].first.second]++;
		}

		magic();

		for(int i = 0; i < m; i++)
		{
			int u, v, k;

			u = Q[i]._F._F;
			v = Q[i]._F._S;
			k = Q[i]._S;

			lli a = code(u, k);
			lli b = code(v, k);
			int ans = M[a] ^ M[b];

			cout << ans << "\n";
		}
	}

	return (0-0);	
}

void magic()
{
	K.clear();
	K.resize(n + 1);

	for(int i = 0; i <= n; i++)
		K[i].resize(C[i]);

	for(int i = 0; i < m; i++)
	{
		int u, v, k;

		tie(u, v) = Q[i].first;
		k = Q[i].second;

		K[u][--C[u]] = (k);
		K[v][--C[v]] = (k);
	}

	dfs(1);
}

lli code(int a, int b)
{
	lli x = 1e10;
	return (x * a) + (lli)b;
}

void dfs(int u)
{
	V[u] = 1;

	for(int i = 0; i < K[u].size(); i++)
	{
		lli p = code(u, K[u][i]);

		M[p] = query(K[u][i] + 1);
	}

	int v, k;

	for(int i = 0; i < G[u].size(); i++)
	{
		v = G[u][i]._F;
		k = G[u][i]._S;

		if(V[v])
			continue;

		update(k);

		dfs(v);

		update(k);
	}

	V[u] = 0;
}

void update(int k)
{
	int A[32];
	bin(A, k);

	int cur = 1;

	for(int i = 0; i < 32; i++)
	{
		T[cur][2] ^= k;

		if(T[cur][A[i]] == 0)
		{
			T[cur][A[i]] = ++node;

			T[node][0] = T[node][1] = T[node][2] = 0;
		}

		cur = T[cur][A[i]];
	}

	T[cur][2] ^= k;
}

void bin(int * A, int k)
{
	for(int i = 31; i >= 0; i--)
	{
		A[i] = k % 2;

		k /= 2;
	}
}

int query(int k)
{
	int A[32];
	bin(A, k);

	int cur = 1;

	int ans = 0;

	for(int i = 0; i < 32; i++)
	{
		if(A[i] == 1)
		{
			if(T[cur][0])
				ans ^= T[T[cur][0]][2];
		}

		if(not T[cur][A[i]])
			break;

		cur = T[cur][A[i]];
	}

	return ans;
}