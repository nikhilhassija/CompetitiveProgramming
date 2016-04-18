#include <bits/stdc++.h>

using namespace std;

int lca(int, int);

int path(int, int, int);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,u,v;
		cin>>n>>u>>v;

		int l = lca(u,v);

		cout<<min(path(l,u,n),path(l,v,n))<<endl;
	}
}

int lca(int u, int v)
{
	while(u != v)
	{
		if(u<v)
			v = v>>1;
		else
			u = u>>1;
	}

	return u;
}

int path(int l, int x, int n)
{
	int m = int(log2(x)) - int(log2(l));
	int c = x - (l<<m);

	return (n-c)/(1<<m);
}