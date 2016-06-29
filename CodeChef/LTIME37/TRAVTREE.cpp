#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > E;
vector <int> P;
vector <int> V;

void assign(int);
int query(int, int);

int root=0;

int main()
{
	int n;
	cin>>n;

	E.resize(n);
	P.resize(n);
	V.resize(n);

	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;

		E[x].push_back(y);
		E[y].push_back(x);
	}

	P[root] = root;
	assign(root);

	int q;
	cin>>q;

	while(q--)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;

		int ans = query(u,v);
		printf("%d\n",ans);
	}
}

void assign(int p)
{
	for(int i=0;i<E[p].size();i++)
	{
		if(E[p][i] != P[p])
		{
			P[E[p][i]] = p;
			assign(E[p][i]);
		}
	}
}

int query(int u, int v)
{
	vector <int> A;
	A.push_back(u);

	int x = u;
	while(x != root)
	{
		x = P[x];
		A.push_back(x);
	}

	vector <int> B;
	B.push_back(v);

	x = v;
	while(x != root)
	{
		x = P[x];
		B.push_back(x);
	}

	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());

	int i;
	for(i=0;i<A.size() && i<B.size();i++)
		if(A[i] != B[i])
			break;

	x = i;
	int ans = V[A[i-1]];
	V[A[i-1]]++;

	for(i=x;i<A.size();i++)
	{
		ans = max(ans,V[A[i]]);
		V[A[i]]++;
	}
	for(i=x;i<B.size();i++)
	{
		ans = max(ans,V[B[i]]);
		V[B[i]]++;
	}

	return ans;
}