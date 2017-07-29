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

	vector <string> A(n+1);
	A[0] = "a";

	const int N = 2e6 + 5;

	vector <pii> P(N);
	for(int i = 0; i < N; i++)
		P[i] = {0, i};

	int l = 0;

	for(int i = 1; i <= n; i++)
	{
		cin >> A[i];

		int s = A[i].size();
		int k;
		cin >> k;

		while(k--)
		{
			int x; 
			cin >> x;
			x--;

			l = max(l, x + s);

			pii p = {i, x + s - 1};

			if(P[x].second <= p.second)
				P[x] = p;
		}
	}

	vector <pii> C;
	C.pb(P[0]);
	for(int i = 1; i < l; i++)
	{
		if(P[i].second > C[C.size() - 1].second)
		{
			C[C.size() - 1].second = i - 1;
			C.pb(P[i]);
		}
	}

	int c = 0;

	for(int i = 0; i < l; i++)
	{
		int k = 0;
		int x = C[c].first;
		int y = C[c].second;

		c++;

		for(; i <= y; i++)
			cout << A[x][k++];

		i--;
	}
	cout << endl;
}