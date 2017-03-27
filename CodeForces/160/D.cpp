#include <bits/stdc++.h>

#define pb push_back
#define mset(x) memset(x, -1, sizeof(x))
#define lli long long int

using namespace std;

struct edge
{
	int x, y;
	int w;
	int i;

	edge() : x(0), y(0), w(0), i(0)
	{}

	edge (int x, int y, int w, int i) : x(x), y(y), w(w), i(i)
	{}
};

bool operator < (const edge &a, const edge &b)
{
	return a.w < b.w; 
}

const int MAX_N = 1e5 + 5;

int DSU_C[MAX_N];

edge E[MAX_N];
int T[MAX_N];

int DFS_L[MAX_N];
int DFS_D[MAX_N];
int DFS_V[MAX_N];
int DFS_G[MAX_N];

vector < edge > G[MAX_N];

int n, m;
lli p, q;
int dfs_cycle = 0;

void dsu_init ();
int  dsu_find (int);
void dsu_join (int, int);

int same_r (int);

int dfs (int, int, int);

int main()
{
	dsu_init();

	cin >> n >> m;
	// cin >> p >> q;

	for(int i=0; i<m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;

		E[i] = edge(x, y, w, i);
	}

	sort(E, E+m);

	for(int i=0; i<m; i=same_r(i))
	{
		int r = same_r(i);

		dfs_cycle++;

		for(int j=i; j<r; j++)
		{
			if(dsu_find(E[j].x) == dsu_find(E[j].y))
			{
				T[E[j].i] = 2;
			}
			else
			{
				int x = dsu_find(E[j].x);
				int y = dsu_find(E[j].y);

				if(DFS_G[x] != dfs_cycle)
				{
					DFS_G[x] = dfs_cycle;
					G[x].clear();
				}

				if(DFS_G[y] != dfs_cycle)
				{
					DFS_G[y] = dfs_cycle;
					G[y].clear();
				}

				G[x].pb(edge(x, y, 0, E[j].i));
				G[y].pb(edge(y, x, 0, E[j].i));
			}
		}

		for(int j=i; j<r; j++)
		{
			int x = dsu_find(E[j].x);
			int y = dsu_find(E[j].y);

			if(x != y)
			{
				if(DFS_V[x] != dfs_cycle)
					dfs(x, 0, 1);

				if(DFS_V[y] != dfs_cycle)
					dfs(y, 0, 1);

				dsu_join(x, y);
			}
		}
	}	

	for(int i=0; i<m; i++)
	{
		if(T[i] == 0)
		{
			cout << "at least one" << endl;
			continue;
		}

		if(T[i] == 1)
		{
			cout << "any" << endl;
			continue;
		}

		if(T[i] == 2)
		{
			cout << "none" << endl;
			continue;
		}
	}


	return (0-0);	
}

void dsu_init()
{
	for(int i=0; i<MAX_N; i++)
		DSU_C[i] = i;
}

int dsu_find(int x)
{
	if(DSU_C[x] == x)
		return x;

	return DSU_C[x] = dsu_find(DSU_C[x]);
}

void dsu_join(int x, int y)
{
	DSU_C[dsu_find(x)] = dsu_find(y);
}

int same_r(int x)
{
	for(int i=x; i<m; i++)
		if(E[i].w != E[x].w)
			return i;

	return m;
}

int dfs(int node, int p, int d)
{
	DFS_D[node] = d;
	DFS_V[node] = dfs_cycle;
	DFS_L[node] = d;

	int low_d = d;
	int first = 0;

	for(int i=0; i<G[node].size(); i++)
	{
		if(first || G[node][i].y != p)
		{
			int v = G[node][i].y;

			if(DFS_V[v] != dfs_cycle)
			{
				int dfs_ret = dfs(v, node, d+1);

				low_d = min(low_d, dfs_ret);

				if(dfs_ret > d)
					T[G[node][i].i] = 1;
			}
			else
			{
				low_d = min(low_d, DFS_L[v]);
			}
		}
		else
			first = 1;
	}

	DFS_L[node] = low_d;

	return DFS_L[node];
}