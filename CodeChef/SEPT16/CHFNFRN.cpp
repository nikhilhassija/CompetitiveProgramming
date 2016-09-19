#include <bits/stdc++.h>

using namespace std;

int G[1005][1005];

int check(int);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,m;
		cin>>n>>m;

		memset(G,1,sizeof(G));

		int x,y;
		while(m--)
		{
			cin>>x>>y;

			x--;
			y--;

			G[x][y] = 0;
			G[y][x] = 0;
		}

		for(int i=0;i<n;i++)
			G[i][i] = 0;

		if(check(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

int check(int n)
{
	int V[n];
	int C[n];
	memset(V,0,sizeof(V));
	memset(C,0,sizeof(C));

	for(int x=0;x<n;x++)
	{
		queue <int> Q;
		
		if(V[x] == 0)
		{
			C[x] = 1;
			Q.push(x);
		}
		else
			continue;	

		while(!Q.empty())
		{
			int i = Q.front();
			Q.pop();

			if(V[i])
				continue;

			for(int j=0;j<n;j++)
			{
				if(G[i][j])
				{
					if(C[i] == C[j])
						return 0;
					else
						C[j] = 1 + C[i]%2;

					if(V[j] == 0)
						Q.push(j);
				}
			}

			V[i] = 1;
		}
	}

	return 1;
}