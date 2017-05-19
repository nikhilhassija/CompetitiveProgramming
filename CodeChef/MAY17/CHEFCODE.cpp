#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define fastio() ios_base::sync_with_stdio(0)

using namespace std;

vector <lli> A, L, R, S_L, S_R;

int main()
{
	lli n, k;
	cin >> n >> k;

	A.resize(n);

	for(int i=0; i<n; i++)
		cin >> A[i];

	int mid = (n / 2);

	for(int i=0; i<mid; i++)
		L.pb(A[i]);

	for(int i=mid; i<n; i++)
		R.pb(A[i]);

	int sz_l = L.size();
	int sz_r = R.size();

	for(int i=1; i<(1<<sz_l); i++)
	{
		lli p = 1;
		int a = 1;

		for(int b=0; b<sz_l; b++)
		{
			if(i & (1 << b))
			{
				if(k/p >= L[b])
				{
					p *= L[b];
				}
				else
				{
					a = 0;
					break;
				}
			}
		}

		if(a)
			S_L.pb(p);
	}

	for(int i=1; i<(1<<sz_r); i++)
	{
		lli p = 1;
		int a = 1;

		for(int b=0; b<sz_r; b++)
		{
			if(i & (1 << b))
			{
				if(k/p >= R[b])
				{
					p *= R[b];
				}
				else
				{
					a = 0;
					break;
				}
			}
		}

		if(a)
			S_R.pb(p);
	}

	lli ans = S_L.size() + S_R.size();

	sort(S_L.begin(), S_L.end());
	sort(S_R.begin(), S_R.end());

	for(int i=0; i < S_R.size(); i++)
	{
		lli f = k/S_R[i];

		ans += upper_bound(S_L.begin(), S_L.end(), f) - S_L.begin();
	}

	cout << ans << endl;

	return (0-0);	
}