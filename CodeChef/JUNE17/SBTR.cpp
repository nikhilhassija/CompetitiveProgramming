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

vector <int> A;
vector < vector<int> > G;

int main()
{
	int n, m;
	cin >> n >> m;

	A.resize(n+1);
	G.resize(n+1);

	for(int i=0; i<n; i++)
		cin >> A[i+1];

	while(m--)
	{
		int x, y;
		cin >> x >> y;

		G[x].pb(y);
		G[y].pb(x);
	}

	if(2*m == (n * (n-1)))
	{
		int x = 1;
		for(int i=1; i<=n; i++)
			if(A[x] > A[i])
				x = i;

		cout << n-1 << endl;

		for(int i=1; i<=n; i++)
			if(i != x)
				cout << i << " ";

		cout << endl;
	}
	else
	{
		cout << n << endl;

		for(int i=0; i<n; ++i)
			cout << i+1 << " ";

		cout << endl;
	}

	return (0-0);	
}