#include <bits/stdc++.h>

#define lli long long int 
#define pll pair<lli,lli>
#define pb(x) push_back(x)
#define inf (lli)(1e17 + 5)

using namespace std;

struct node
{
	int parent;
	int depth;
	vector <int> adj;
	vector <pll> tic;
};

vector <node> A;
int n,m;
lli T[500005];
lli V[100005];
lli Q[100005];

void assign_parent();
void segtree_build(int, int, int);
void segtree_update(int, int, int, int, lli);
lli segtree_query(int, int, int, int, int);
void magic();

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;

	A.resize(n);

	for(int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		A[x].adj.pb(y);
		A[y].adj.pb(x);
	}


	while(m--)
	{
		lli v,k,w;
		cin >> v >> k >> w;

		v--;
		A[v].tic.pb(make_pair(k,w));
	}

	A[0].parent = 0;
	A[0].depth  = 0;
	assign_parent();

	for(int i=0;i<100005;i++)
	{
		Q[i] = inf;
		V[i] = inf;
	}

	segtree_build(1,0,100004);

	Q[0] = 0;
	segtree_update(1,0,100004,0,0ll);
	magic();

	int q;
	cin>>q;

	while(q--)
	{
		int x;
		cin>>x;

		cout<<Q[x-1]<<'\n';
	}
}

void assign_parent()
{
	queue <int> Q;

	Q.push(0);

	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for(int i=0;i<A[x].adj.size();i++)
		{
			int u = A[x].adj[i];
			if(u != A[x].parent)
			{
				A[u].parent = x;
				A[u].depth = A[x].depth + 1;
				Q.push(u);
			}
		}
	}
}

void segtree_build(int node, int l, int r)
{
	if(l == r)
		T[node] = V[l];
	else
	{
		int m = (l+r)/2;

		segtree_build(2*node,l,m);
		segtree_build(2*node+1,m+1,r);

		T[node] = min(T[2*node],T[2*node + 1]);
	}
}

void segtree_update(int node, int l, int r, int i, lli x)
{
	if(l == r)
	{
		V[i] = x;
		T[node] = V[i];
	}
	else
	{
		int m = (l+r)/2;

		if(i <= m)
			segtree_update(2*node, l, m, i, x);
		else
			segtree_update(2*node+1, m+1, r, i, x);

		T[node] = min(T[2*node],T[2*node + 1]);
	}
}

lli segtree_query(int node, int l, int r, int ql, int qr)
{
	if(qr < l || r < ql)
		return inf;

	if(ql <= l && r <= qr)
		return T[node];

	int m = (l+r)/2;
	return min(
		segtree_query(2*node, l, m, ql, qr),
		segtree_query(2*node +1, m+1, r, ql, qr)
		);
}

void magic()
{
	stack <int> S;

	S.push(0);

	while(!S.empty())
	{
		int x = S.top();
		S.pop();
	
		for(int i=0;i<A[x].tic.size();i++)
		{
			pll p = A[x].tic[i];
			int k = p.first;
			lli w = p.second;

			lli q = segtree_query(1,0,100004,max(0,A[x].depth-k),max(0,A[x].depth-1)) + w;
			Q[x] = min(Q[x],q);
		}

		segtree_update(1,0,100004,A[x].depth,Q[x]);

		for(int i=0;i<A[x].adj.size();i++)
		{
			int u = A[x].adj[i];
			if(u != A[x].parent)
			{
				S.push(u);
			}
		}
	}
}