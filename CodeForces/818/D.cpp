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

const int MAX_N = 1e6 + 1;

int main()
{
	int n, A;
	cin >> n >> A;

	vector < vector <int> > O(MAX_N);
	vector <int> T(n+1);

	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;

		if(x == A)
			T[i] = 1;
		else
			O[x].pb(i);
	}

	for(int i=1; i<=n; i++)
		T[i] += T[i-1];

	for(int i=0; i<O.size(); i++)
	{
		if(O[i].size())
		{
			int c = 0;
			int f = 1;
			
			for(int j=0; j<O[i].size(); j++)
			{
				if(O[i][j] and T[O[i][j]-1] > c)
				{
					f = 0;
				}

				c++;

				if(T[O[i][j]] > c)
					f = 0;
			}

			if(T[n] > c)
				f = 0;

			if(f)
			{
				cout << i << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;

	return (0-0);	
}