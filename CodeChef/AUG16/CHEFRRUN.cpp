#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > R;
vector <int> F, F_V, R_V;
stack <int> S;

int ctr;

void forward_dfs(int);
void reverse_dfs(int);

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		F.clear();
		R.clear();
		F_V.clear();
		R_V.clear();

		int n;
		cin>>n;

		F.resize(n);
		R.resize(n);
		F_V.resize(n,0);
		R_V.resize(n,0);

		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;

			F[i] = (i+x+1)%n;
			R[(i+x+1)%n].push_back(i);
		}

		for(int i=0;i<n;i++)
			if(F_V[i] == 0)
				forward_dfs(i);

		int ans = 0;
		while(!S.empty())
		{
			int s = S.top();
			S.pop();

			ctr = 0;

			if(R_V[s] == 0)
				reverse_dfs(s);

			if(ctr > 1)
				ans += ctr;
		}

		for(int i=0;i<n;i++)
			if(F[i] == i)
				ans++;

		printf("%d\n",ans);
	}
}

void forward_dfs(int u)
{
	F_V[u] = 1;
	
	int v = F[u];
	if(F_V[v] == 0)
		forward_dfs(v);

	S.push(u);
}

void reverse_dfs(int u)
{
	ctr++;
	R_V[u] = 1;

	for(int i=0;i<R[u].size();i++)
	{
		int v = R[u][i];
		if(R_V[v] == 0)
			reverse_dfs(v);
	}
}