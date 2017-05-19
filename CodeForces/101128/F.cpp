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

const int INF = 2000000000;

struct Edge {
	int from, to, cap, flow, index;
	Edge(int from, int to, int cap, int flow, int index) :
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
	int N;
	vector<vector<Edge> > G;
	vector<Edge *> dad;
	vector<int> Q;
	
	// N = number of vertices
	Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
	
	// Add an edge to initially empty network. from, to are 0-based
	void AddEdge(int from, int to, int cap) {
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if (from == to) G[from].back().index++;
		G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	long long BlockingFlow(int s, int t) {
		fill(dad.begin(), dad.end(), (Edge *) NULL);
		dad[s] = &G[0][0] - 1;
		
		int head = 0, tail = 0;
		Q[tail++] = s;
		while (head < tail) {
			int x = Q[head++];
			for (int i = 0; i < G[x].size(); i++) {
				Edge &e = G[x][i];
				if (!dad[e.to] && e.cap - e.flow > 0) {
					dad[e.to] = &G[x][i];
					Q[tail++] = e.to;
				}
			}
		}
		if (!dad[t]) return 0;

		long long totflow = 0;
		for (int i = 0; i < G[t].size(); i++) {
			Edge *start = &G[G[t][i].to][G[t][i].index];
			int amt = INF;
			for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
				if (!e) { amt = 0; break; }
				amt = min(amt, e->cap - e->flow);
			}
			if (amt == 0) continue;
			for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
				e->flow += amt;
				G[e->to][e->index].flow -= amt;
			}
			totflow += amt;
		}
		return totflow;
	}

	// Call this to get the max flow. s, t are 0-based.
	// Note, you can only call this once.
	// To obtain the actual flow values, look at all edges with
	// capacity > 0 (zero capacity edges are residual edges).

	long long GetMaxFlow(int s, int t) {
		long long totflow = 0;
		while (long long flow = BlockingFlow(s, t))
			totflow += flow;
		return totflow;
	}
};

int main()
{
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	string S[n];
	for(int i=0; i<n; i++)
		cin >> S[i];

	int A[n][m];
	int id = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			A[i][j] = id++;

	int sl = id++;
	int sh = id++;

	Dinic D(id);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			// D.AddEdge(A[i][j+1], A[i][j], a);
			D.AddEdge(A[i][j], A[i][j+1], a);
		}
	}

	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n; j++)
		{
			D.AddEdge(A[i+1][j], A[i][j], a);
			D.AddEdge(A[i][j], A[i+1][j], a);
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(S[i][j] == '.')
			{
				D.AddEdge(sl, A[i][j], b);
				D.AddEdge(A[i][j], sl, b);
			}
			else
			{
				D.AddEdge(sh, A[i][j], b);
				D.AddEdge(A[i][j], sh, b);
			}
		}
	}

	cout << D.GetMaxFlow(sl, sh) << endl;
	// cout << D.GetMaxFlow(sh, sl) << endl;

	return (0-0);  
}
