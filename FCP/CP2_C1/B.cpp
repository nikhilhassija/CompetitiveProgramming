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
	int n, q;
	scanf("%d %d", &n, &q);
	// cin >> n >> q;

	n--;

	int b_size = max(1, int(sqrt(n)) / 2);
	int b_num  = n / b_size + (n % b_size != 0);

	vector < vector <pii> > B(b_num);
	vector <int> L(b_num, 0);

	for(int i=0; i<n; i++)
		B[i/b_size].pb({0, i});

	while(q--)
	{
		int t;
		cin >> t;

		int l, r;
		cin >> l >> r;
		l--;
		r--; r--;

		int lb = l / b_size;
		int rb = r / b_size;

		if(t == 1 or t == 2)
		{
			int v = -1 + (2 * (t == 2));

			for(int i=lb+1; i<rb; i++)
				L[i] += v;

			for(int i=0; i<B[lb].size(); i++)
				if(l <= B[lb][i].second and B[lb][i].second <= r)
					B[lb][i].first += v;

			sort(B[lb].begin(), B[lb].end());

			if(lb != rb)
			{
				for(int i=0; i<B[rb].size(); i++)
					if(l <= B[rb][i].second and B[rb][i].second <= r)
						B[rb][i].first += v;

				sort(B[rb].begin(), B[rb].end());
			}	
		}
		else
		{
			int ans = 0;

			for(int i=0; i<B[lb].size(); i++)
				if(l <= B[lb][i].second and B[lb][i].second <= r and ((B[lb][i].first + L[lb]) == 0))
					ans++;


			for(int i=lb+1; i<rb; i++)
			{
				int idx = upper_bound(B[i].begin(), B[i].end(), make_pair(-L[i], n+1)) - 
					lower_bound(B[i].begin(), B[i].end(), make_pair(-L[i], 0));

				ans += max(0, idx);
			}



			if(lb != rb)
			{
				for(int i=0; i<B[rb].size(); i++)
					if(l <= B[rb][i].second and B[rb][i].second <= r and ((B[rb][i].first + L[rb]) == 0))
						ans++;
			}

			printf("%d\n", ans);
			// cout << ans << endl;
		}
	}

	return (0-0);	
}