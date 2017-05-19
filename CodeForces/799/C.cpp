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

const max_p = 1e5 + 5;

int main()
{
	int n, c, d;
	cin >> n >> c >> d;

	int C[max_p], D[max_p];
	mset(C);
	mset(D);

	vector < pii> CP, DP;

	for(int i=0; i<n; i++)
	{
		int b, p;
		cin >> b >> p;

		char t;
		cin >> t;

		if(t == 'C')
		{
			CP.pb({b, p});
			C[p] = max(C[p], b);
		}

		if(t == 'D')
		{
			DP.pb({b, p});
			D[p] = max(D[p], b);
		}
	}

	for(int i=1; i<max_p; i++)
	{
		C[i] = max(C[i], C[i-1]);
		D[i] = max(D[i], D[i-1]);
	}



	return 0;
}