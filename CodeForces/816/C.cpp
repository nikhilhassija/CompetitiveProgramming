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

const int MAX_N = 105;

int n, m;
int A[MAX_N][MAX_N];

int R[MAX_N];
int X[MAX_N];

int C[MAX_N];
int Y[MAX_N];

int tryrow();
int trycol();

vector <int> AR;
vector <int> AC;

int ar = 0;
int ac = 0;

int main()
{
	cin >> n >> m;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> A[i][j];

	for(int i=0; i<MAX_N; i++)
		R[i] = C[i] = 1000;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			R[i] = min(R[i], A[i][j]);
			C[j] = min(C[j], A[i][j]);
		}
	}



	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(A[i][j] > (R[i] + C[j]))
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}

	mset(X);
	mset(Y);


	tryrow();
	trycol();

	int ans = min(ac, ar);

	vector <int> Z;

	if(ans == 1e9)
	{
		cout << -1 << endl;
		return 0;
	}

	if(ans == ar)
		Z = AR;
	else
		Z = AC;

	cout << ans << endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<Z[i]; j++)
			cout << "row " << i + 1 << endl;

	for(int i=0; i<m; i++)
		for(int j=0; j<Z[i+n]; j++)
			cout << "col " << i + 1 << endl;

	return (0-0);	
}

int tryrow()
{
	for(int i=0; i<n; i++)
		X[i] = R[i];

	for(int j=0; j<m; j++)
	{
		int mn = 1000;

		for(int i=0; i<n; i++)
			mn = min(mn, A[i][j] - X[i]);

		Y[j] = mn;
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(X[i] + Y[j] != A[i][j])
			{
				ar = 1e9;

				return 1;
			}
		}
	}

	for(int i=0; i<n; i++)
	{
		ar += X[i];
		AR.pb(X[i]);
	}

	for(int i=0; i<m; i++)
	{
		ar += Y[i];
		AR.pb(Y[i]);
	}

	return 0;
}

int trycol()
{
	for(int i=0; i<m; i++)
		Y[i] = C[i];

	for(int i=0; i<n; i++)
	{
		int mn = 1000;

		for(int j=0; j<m; j++)
			mn = min(mn, A[i][j] - Y[j]);

		X[i] = mn;
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(X[i] + Y[j] != A[i][j])
			{
				ac = 1e9;

				return 1;
			}
		}
	}

	for(int i=0; i<n; i++)
	{
		ac += X[i];
		AC.pb(X[i]);
	}

	for(int i=0; i<m; i++)
	{
		ac += Y[i];
		AC.pb(Y[i]);
	}

	return 0;
}