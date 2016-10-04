#include <bits/stdc++.h>

#define lli long long int
#define pii pair<lli,lli>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

using namespace std;

int main()
{
	lli n,m,k;
	cin>>n>>m>>k;
	
	if(k == 0)
	{
		printf("-1\n");
		return 0;
	}

	vector < vector < pii > > G(n);

	while(m--)
	{
		lli x,y,w;
		cin>>x>>y>>w;

		x--;
		y--;

		G[x].pb(mp(y,w));
		G[y].pb(mp(x,w));
	}

	lli A[k];
	for(lli i=0;i<k;i++)
		cin>>A[i];

	lli D[n];
	memset(D,-1,sizeof(D));

	for(lli i=0;i<k;i++)
	{
		A[i]--;
		D[A[i]] = 0;
	}

	for(lli i=0;i<k;i++)
	{
		lli u = A[i];
		for(lli j=0;j<G[u].size();j++)
		{
			lli v,w;
			tie(v,w) = G[u][j];
			
			if(D[v] == -1)
				D[v] = w;
			else
				D[v] = min(D[v],w);
		}
	}

	for(lli i=0;i<k;i++)
		D[A[i]] = -1;

	lli ans = -1;
	for(lli i=0;i<n;i++)
	{
		if(D[i] != -1)
		{
			if(ans == -1)
				ans = D[i];
			else
				ans = min(ans,D[i]);
		}
	}

	printf("%lld\n",ans);
}