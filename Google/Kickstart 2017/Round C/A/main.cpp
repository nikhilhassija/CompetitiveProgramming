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

const int MOD = 26;

vector < vector <pii> > P(26);

vector < vector < vector <pii> > > B;

void pre();

int main()
{
	pre();

	int T;
	cin >> T;

	for(int t=1; t<=T; t++)
	{
		string S;
		cin >> S;

		char A[S.size() + 5];
		mset(A);

		if(S.size() == 1)
			assert(0);

		if(S.size() % 2)
			cout << "Case #" << t << ": AMBIGUOUS" << endl;
		else
		{
			int n = S.size();

			A[1] = S[0] - 'A';
			for(int i=3; i<n; i += 2)
			{
				A[i] = (S[i-1] - 'A' - A[i-2] + MOD) % MOD;
			}

			A[n-2] = S[n-1] - 'A';
			for(int i=n-4; i>=0; i--)
			{
				A[i] = (S[i+1] - A[i+2] - 'A' + MOD) % MOD;
			}

			cout << "Case #" << t << ": ";
			for(int i=0; i<n; i++)
			{
				A[i] += 'A';
				cout << A[i];
			}
			cout << endl;
		}
	}

	return (0-0);	
}

void pre()
{
	for(int i=0; i<MOD; i++)
	{
		for(int j=0; j<MOD; j++)
		{
			P[(i + j) % MOD].pb({i, j});
		}
	}
}