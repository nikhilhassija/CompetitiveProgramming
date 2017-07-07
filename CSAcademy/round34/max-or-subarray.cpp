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
vector <vector <int> > B;
vector <int> X;
vector <int> C;

void genbits(int, vector <int> &);

int main()
{
	int n;
	cin >> n;

	A.resize(n);
	B.resize(n);
	C.resize(32, 0);

	for(int i=0; i<n; i++)
		cin >> A[i];

	int x = 0;
	for(int i=0; i<n; i++)
		x |= A[i];

	for(int i=0; i<n; i++)
		genbits(A[i], B[i]);

	genbits(x, X);

	int l = 1;
	int h = n;

	int ans = n;

	while(l <= h)
	{
		int m = (l + h) / 2;
		// cout << m << "ada" << endl;

		fill(C.begin(), C.end(), 0);

		int f = 0;

		for(int i=0; i<m-1; i++)
			for(int j=0; j<32; j++)
				C[j] += B[i][j];

		for(int i=m-1; i<n; i++)
		{
			// cout << i << endl;
			for(int j=0; j<32; j++)
				C[j] += B[i][j];

			int fp = 1;
			for(int j=0; j<32; j++)
			{
				// cout << (bool)C[j];
				if((not C[j] and X[j]) or (C[j] and not X[j]))
					fp = 0;
			}

			f = f or fp;

			for(int j=0; j<32; j++)
				C[j] -= B[i-m+1][j];
		}

		if(f)
		{
			h = m -1;
			ans = min(ans, m);
		}
		else
			l = m + 1;
	}

	cout << ans << endl;

	return (0-0);	
}

void genbits(int x, vector <int>& X)
{
	for(int i=0; i<32; i++)
	{
		X.pb(x % 2);
		x /= 2;
	}
}