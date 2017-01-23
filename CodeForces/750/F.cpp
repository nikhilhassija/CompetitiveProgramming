#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define pii pair <int, int>
#define pll pair <lli, lli>
#define _F first
#define _S second
#define mset(x) memset(x, 0, sizeof(x))
#define fastio() ios_base::sync_with_stdio(0);

using namespace std;

void dfs(int);
int V[1000];
int root = 0;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int h;
		cin >> h;

		root = 0;
		memset(V, 0, sizeof(V));

		dfs(1);

		printf("! %d\n", root);
		fflush(stdout);
	}
}

void dfs(int node)
{
	if(root)
		return ;

	V[node] = 1;
	printf("? %d\n", node);
	fflush(stdout);

	int n, a,b,c;

	cin >> n;

	switch(n)
	{
		case 1: cin >> a; if(!V[a]) dfs(a); break;
		case 2: cin >> a >> b; root = node; return; break;
		case 3: cin >> a >> b >> c;
			if(V[a])
			{
				if(V[b])
				{
					dfs(c);
				}
				else
					dfs(b);
			}
			else
			{
				dfs(a);
			}; break;
	}
}