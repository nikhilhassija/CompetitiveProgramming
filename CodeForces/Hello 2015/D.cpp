#include <bits/stdc++.h>

#define lli long long int 
#define pll pair<int,int>
#define plp pair <lli, pll>

using namespace std;

const lli inf = 1e17;

vector < vector <plp> > G;
vector <lli> D;
vector <int> V;

void dijkstra(lli);

int main()
{
	ios_base::sync_with_stdio(false);

	lli n, m, C;
	cin >> n >> m >> C;

	G.resize(n);
	D.resize(n,inf);
	V.resize(n,0);

	while(m--)
	{
		lli u,v,w,c;

		cin >> u >> v >> w >> c;

		u--;
		v--;

		G[u].push_back({v,{w,c}});
		// G[v].push_back({u,{w,c}});
	}


	lli s;
	cin >> s;

	dijkstra(s-1);

	lli q;
	cin >> q;

	while(q--)
	{
		lli x;
		cin >> x;

		if(D[x-1] == inf)
			cout << "-1\n";
		else
			cout << D[x-1] << '\n';
	}
}

void dijkstra(lli node)
{
	D[node] = 0;

	priority_queue <plp, vector<plp>, greater<plp> > Q;

	Q.push({D[node],{node, -1}});
	set < pair<lli,lli> > S;
	// map < pll, int>  M;

	lli w, u, c;
	
	while(!Q.empty())
	{
		auto p = Q.top();
		Q.pop();

		w = p.first;
		u = p.second.first;
		c = p.second.second;

		if(S.find({u,c}) != S.end())
			continue;

		V[u]++;
		D[u] = min(D[u],w);

		for(int i=0;i<G[u].size();i++)
		{
			p = G[u][i];

			if(c != p.second.second)
				if(V[p.first] < 2)
					Q.push({w+p.second.first,{p.first,p.second.second}});
		}

		S.insert({u,c});
	}
}