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

int main()
{
	int n;
	cin >> n;

	vector <string> S(n);

	for(int i=0; i<n; i++)
		cin >> S[i];

	vector < vector <char> > A(n);

	for(int i=0; i<S[n-1].size(); i++)
		A[n-1].pb(S[n-1][i]);

	for(int i=n-1; i>0;i--)
	{
		int x = min(A[i].size(), S[i-1].size());

		int f = 0;
		for(int j=0; j<x; j++)
		{
			if(S[i-1][j] < S[i][j])
			{
				f = j;
				break;
			}

			if(S[i-1][j] > A[i][j])
			{
				break;
			}

			A[i-1].pb(S[i-1][j]);
		}

		if(f)
		{
			for(; f<S[i-1].size(); f++)
				A[i-1].pb(S[i-1][f]);
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<A[i].size(); j++)
			cout << A[i][j];
		cout << endl;
	}
}