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
	int t;
	cin >> t;

	while(t--)
	{
		int n, d;
		cin >> n >> d;

		vector <pii> A;
		vector <lli> D(n), S(n);

		for(int i=0; i<n; i++)
		{
			int x;
			cin >> x >> D[i] >> S[i];

			A.pb({x, i});
		}

		sort(A.begin(), A.end());

		int k = 0;

		priority_queue <pll> Q;

		for(int i=1; i<=d; i++)
		{
			while(A[k].first == i)
			{
				int a, b;
				tie(a, b) = A[k];

				Q.push({S[b], b});

				k++;
			}

			if(Q.empty())
				continue;

			auto p = Q.top();
			Q.pop();

			D[p.second]--;

			if(D[p.second])
				Q.push(p);
		}

		lli ans = 0;

		while(not Q.empty())
		{
			auto p = Q.top();
			Q.pop();

			int i = p.second;

			ans += D[i] * S[i];
		}

		cout << ans << endl;
	}

	return (0-0);	
}