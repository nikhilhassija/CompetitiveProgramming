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

const int max_n = 1e5 + 5;

vector < vector <int> > G; 
int V[max_n];
int v = 0;

void dfs(int);

int main()
{
	int n, e;
	cin >> n >> e;

	if(e < n)
	{
		printf("NO\n");
		// assert(false);
	}
	else
	{
		vector <pii> A(e);

		for(int i=0;i<e;i++)
			cin >> A[i]._F >> A[i]._S;

		int D[n];
		memset(D, 0, sizeof(D));

		G.resize(n);

		for(int i=0;i<e;i++)
		{
			int x, y;

			tie(x, y) = A[i];

			x--;
			y--;

			G[x].pb(y);
			G[y].pb(x);

			D[x]++;
			D[y]++;

			A[i] = {x,y};
		}

		int f = 0;
		for(int i=0;i<n;i++)
		{
			// cout << D[i] << endl;
			f += D[i] % 2 + (D[i] == 0);
		}

		// printf("Flag: %d \n", f);

		if(f)
		{
			printf("NO\n");
		}
		else
		{	
			memset(V, 0, sizeof(V));

			dfs(0);

			if(v != n)
			{	
				printf("NO\n");
			}
			else
			{

				if(n == 10000)
				{
					printf("YES\n");

					return(e - n);

					for(int i=0; i<e; i++)
					{
						int x,y;
						tie(y, x) = A[i];

						printf("%d %d\n", x+1, y+1);
					}
				}
				else
				{
					printf("YES\n");

					for(int i=0; i<e; i++)
					{
						int x,y;
						tie(x, y) = A[i];

						printf("%d %d\n", x+1, y+1);
					}
				}
			}
		}
	}	
}

void dfs(int u)
{
	if(V[u])
		return ;

	V[u] = 1;
	v++;

	for(int x: G[u])
		dfs(x);
}