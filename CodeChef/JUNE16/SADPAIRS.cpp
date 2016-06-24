#include <bits/stdc++.h>

#define lli long long int 

using namespace std;

const lli MAX_N = 2e5 + 5;

vector <lli> G;
vector < vector <lli> > E;
lli V[MAX_N];

lli n,e;
lli max_pairs = 0;

void init();
void dfs();

int main()
{
	cin>>n>>e;

	G.resize(n);
	for(lli i=0;i<n;i++)
		cin>>G[i];

	E.resize(n);
	while(e--)
	{
		lli x,y;
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}

	init();
}

void init()
{	
	lli x = 1e6 + 5;
	lli C[x];
	memset(C,0,sizeof(C));

	for(lli i=0;i<n;i++)
		C[G[i]]++;

	lli k = 0;
	for(lli i=0;i<x;i++)
	{
		max_pairs += (C[i]*(C[i]-1))/2;
		if(C[i])
		{
			C[i] = k++;
		}
	}

	for(lli i=0;i<n;i++)
		G[i] = C[G[i]];

	memset(V,0,sizeof(V));
	for(int i=0;i<n;i++)
	{
		if(V[i] == 0)
		{
			dfs(i);
		}
	}
}

void dfs()
{

}